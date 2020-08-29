#include <array>
#include <boost/endian/conversion.hpp>
#include <iostream>

template <typename T, std::size_t N>
bool bcd_conversion(const T &v, std::array<unsigned char, N> &buf) {
  if ((N == 6 && v > 999999999999u) || (N == 7 && v > 99999999999999u)) {
    std::cout << "The value is not valid " << std::endl;
    return false;
  }

  constexpr uint64_t mods[]{10u,
                            100u,
                            1000u,
                            10000u,
                            100000u,
                            1000000u,
                            10000000u,
                            100000000u,
                            1000000000u,
                            10000000000u,
                            100000000000u,
                            1000000000000u,
                            10000000000000u,
                            100000000000000u};
  constexpr uint64_t divs[]{
      1u,           10u,           100u,           1000u,          10000u,
      100000u,      1000000u,      10000000u,      100000000u,     1000000000u,
      10000000000u, 100000000000u, 1000000000000u, 10000000000000u};

  uint64_t q = 0u;
  auto i = 0u;
  while ((i < N * 2) && (v / divs[i])) {
    q |= ((v % mods[i]) / divs[i]) << (i << 2);
    ++i;
  }
  boost::endian::native_to_big_inplace(q);
  auto used_bytes = (i % 2) ? (i / 2 + 1) : i / 2;
  // init 0xf for all nibble
  buf.fill(0xff);
  // copy the used bytes only
  memcpy(buf.begin() + N - used_bytes,
         (unsigned char *)(&q) + sizeof(uint64_t) - used_bytes, used_bytes);
  // in case of a the number of digit is odd then there is a unused nibble in a
  // same byte that located the first used nibble, set its value to 0xf
  if (i % 2) {
    buf[N - used_bytes] = buf[N - used_bytes] + 0xf0;
  }
  return true;
}
struct A {
 public:
  void show_char() {
    for (int i = 0; i < 3; i++) {
      std::cout << std::endl;
      prices[i].show();
      std::cout << std::endl;
    }
  }

  struct price_t {
    // price_t() {}
    price_t(uint64_t prc) {
      bcd_conversion<uint64_t, 7>(prc, price_);
      std::cout << "ham tao ne\n";
    }

    price_t &operator=(const uint64_t &prc) {
      bcd_conversion<uint64_t, 7>(prc, price_);
      std::cout << "qua tai toan tu = ne\n";
      return *this;
    }

    void show() {
      for (auto i : price_) {
        printf("%.2x ", i);
      }
    }

   private:
    std::array<unsigned char, 7> price_;
  } __attribute__((packed)) prices[3];
} __attribute__((packed));

int main() {
  A a;
  // A a = {1, 2, 3};
  // a.show_char();
  // std::cout << "----------------" << std::endl;
  // std::array<uint64_t, 3> arr{124, 231, 259881897632};
  // std::copy(arr.begin(), arr.end(), a.prices);
  // a.show_char();
}

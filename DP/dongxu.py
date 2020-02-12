n, S = map(int, input().split())
w = list(map(int, input().split()))
dp = [0] * (S + 1)
dp[0] = 0

for P in range(1, S + 1):
    dp[P] = min(dp[P - x] for x in w if x <= P) + 1

print(dp)
print(dp[S])

# Nếu đầu vào như sau: n = 3, S = 11, w = [1, 3, 5]
# Thì bảng lời giải cho các bài toán con sẽ lần lượt như sau:
# P = 0 |1 |2 |3 |4 |5 |6 |7 |8 |9 |10|11
# ------+--+--+--+--+--+--+--+--+--+--+--
# k = 0 |1 |2 |1 |2 |1 |2 |3 |2 |3 |2 |3
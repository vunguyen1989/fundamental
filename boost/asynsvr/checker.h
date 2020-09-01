#pragma once

#include <vector>

#include <boost/asio.hpp>
#include <string_view>

namespace VuNguyen
{

    /**
 * Checking the input string is valid or not.
 */
    class Checker
    {
    public:
        bool IsValid(const std::string_view &str);

    private:
    };

} // namespace VuNguyen

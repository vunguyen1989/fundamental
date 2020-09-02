#pragma once

#include <vector>

#include <boost/asio.hpp>

namespace VuNguyen
{

    /**
 * Checking the input string is valid or not.
 */
    class Checker
    {
    public:
        bool IsValid(uint8_t *p, uint16_t size_, char *str);
    };

} // namespace VuNguyen

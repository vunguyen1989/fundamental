#include "checker.h"
#include <iostream>

namespace VuNguyen
{

    bool Checker::IsValid(const std::string_view &s)
    {
        if (s.back() != '\n')
        {
            std::cout << "The message is not end by a \n"
                      << std::endl;
            return false;
        }

        return true;
    }

} // namespace VuNguyen

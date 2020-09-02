#include "checker.h"
#include <iostream>

namespace VuNguyen
{

    bool Checker::IsValid(uint8_t *p, uint16_t size_)
    {
        if (*(p + size_ - 1) != '\n')
        {

            std::cout << "The message is not end by a new line character\n";
            return false;
        }
        if (size_ == 1)
        {
            std::cout << "The message is a new line characteronly\n";
            return false;
        }
        return true;
    }

} // namespace VuNguyen

#include "checker.h"
#include <iostream>

namespace VuNguyen
{

    bool Checker::IsValid(uint8_t *p, uint16_t size_, char *str)
    {
        if (*(p + size_ - 1) != '\n')
        {
            std::cout << "The message is not end by a new line character\n";
            return false;
        }
        for (auto i = 0, j = 0; i < size_; i++)
        {
            if (p[i] == ' ')
                continue;
            else
            {
                str[j] = p[i];
                j++;
            }
        }
        return true;
    }

} // namespace VuNguyen

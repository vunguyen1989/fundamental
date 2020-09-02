#include "processor.h"
#include <optional>
#include <stack>

namespace VuNguyen
{
    expression *Evaluator::parse_number(const char *&s)
    {
        assert("Sanity check" && s && std::isdigit(*s));
        number_token *nt = new number_token(0);
        // Convert number...

        while (*s && std::isdigit(*s))
        {
            nt->value_ = nt->value_ * 10 + *s++ - '0';
        }
        return nt;
    }

    expression *Evaluator::parse_atom(const char *&s)
    {
        assert("Sanity check" && s);
        if (*s == 0)
        {
            throw std::runtime_error("Atom parse error: unexpected EOS");
        }
        else if (*s == '(')
        {
            s++;
            expression *atom = parse_summands(s);
            if (*s == ')')
            {
                s++;
                return atom;
            }
            throw std::runtime_error("Atom parse error: unbalanced brackets");
        }
        else if (std::isdigit(*s))
        {
            expression *atom = parse_number(s);
            return atom;
        }
        throw std::runtime_error("Atom parse error: unexpected char");
    }

    expression *Evaluator::parse_factors(const char *&s)
    {
        assert("Sanity check" && s);
        expression *left = parse_atom(s);
        while (*s)
        {
            if (*s == '*')
            {
                s++;
                expression *right = parse_atom(s);
                left = new mul_type(left, right);
                continue;
            }
            else if (*s == '/')
            {
                s++;
                expression *right = parse_atom(s);
                left = new div_type(left, right);
                continue;
            }
            return left;
        }
        return left;
    }

    expression *Evaluator::parse_summands(const char *&s)
    {
        assert("Sanity check" && s);
        expression *left = parse_factors(s);
        while (*s)
        {
            if (*s == '+')
            {
                s++;
                expression *right = parse_factors(s);
                left = new plus_type(left, right);
                continue;
            }
            else if (*s == '-')
            {
                s++;
                expression *right = parse_factors(s);
                left = new minus_type(left, right);
                continue;
            }
            return left;
        }
        return left;
    }

    const expression *Evaluator::parse(const char *s)
    {
        return parse_summands(s);
    }

} // namespace VuNguyen
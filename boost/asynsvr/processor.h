#pragma once

#include <boost/asio.hpp>
#include <optional>
#include <vector>

namespace VuNguyen
{
    struct expression
    {
        virtual ~expression(){};
        virtual int operator()() const = 0;
    };

    struct number_token : public expression
    {
        int value_;
        number_token(const int value = 0) : value_(value) {}
        int operator()() const
        {
            return value_;
        }
    };

    struct binary_predicate : public expression
    {
        expression *left_;
        expression *right_;

        binary_predicate(expression *const left = 0, expression *const right = 0)
            : left_(left), right_(right)
        {
        }
    };

    struct plus_type : public binary_predicate
    {
        plus_type(expression *const left, expression *const right)
            : binary_predicate(left, right)
        {
        }

        int operator()() const
        {
            return (*left_)() + (*right_)();
        }
    };

    struct minus_type : public binary_predicate
    {
        minus_type(expression *const left, expression *const right)
            : binary_predicate(left, right)
        {
        }

        int operator()() const
        {
            return (*left_)() - (*right_)();
        }
    };

    struct mul_type : public binary_predicate
    {
        mul_type(expression *const left, expression *const right)
            : binary_predicate(left, right)
        {
        }

        int operator()() const
        {
            return (*left_)() * (*right_)();
        }
    };

    struct div_type : public binary_predicate
    {
        div_type(expression *const left, expression *const right)
            : binary_predicate(left, right)
        {
        }

        int operator()() const
        {
            return (*left_)() / (*right_)();
        }
    };

    class Evaluator
    {
    public:
        const expression *parse(const char *); ///< Parse an expression

    private:
        expression *parse_number(const char *&);   ///< Parse numeric constants
        expression *parse_atom(const char *&);     ///< Parse nested expression
        expression *parse_summands(const char *&); ///< Parse '+' and '-' operations
        expression *parse_factors(const char *&);  ///< Parse '*' and '/' operations
    };
} // namespace VuNguyen

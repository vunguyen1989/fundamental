#include <cassert>
#include <iostream>
#include <list>
#include <memory>
#include <stdexcept>

// https://stackoverflow.com/questions/17806760/binary-expression-tree-c

/// \todo Because I'm short of time, there is no smart pointers or
/// even destructors (w/ delete) :) -- THIS IS FAR FROM PRODUCTION CODE,
/// but it is minimalistic to realize the idea...

/**
* \brief Expression abstract base class
*
* ... has only evaluate function.
*/
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

    std::unique_ptr<expression> left_;
    std::unique_ptr<expression> right_;

    binary_predicate(std::unique_ptr<expression> left = 0, std::unique_ptr<expression> right = 0)

    {
        left_ = std::move(left);
        right_ = std::move(right);
    }
    virtual ~binary_predicate(){

    };
};

struct plus_type : public binary_predicate
{
    plus_type(std::unique_ptr<expression> left, std::unique_ptr<expression> right)
    {
        left_ = std::move(left);
        right_ = std::move(right);
    }

    int operator()() const
    {
        return (*left_)() + (*right_)();
    }
};

struct minus_type : public binary_predicate
{
    minus_type(std::unique_ptr<expression> left, std::unique_ptr<expression> right)
    {
        left_ = std::move(left);
        right_ = std::move(right);
    }

    int operator()() const
    {
        return (*left_)() - (*right_)();
    }
};

struct mul_type : public binary_predicate
{
    mul_type(std::unique_ptr<expression> left, std::unique_ptr<expression> right)
    {
        left_ = std::move(left);
        right_ = std::move(right);
    }

    int operator()() const
    {
        return (*left_)() * (*right_)();
    }
};

struct div_type : public binary_predicate
{
    div_type(std::unique_ptr<expression> left, std::unique_ptr<expression> right)
    {
        left_ = std::move(left);
        right_ = std::move(right);
    }

    int operator()() const
    {
        return (*left_)() / (*right_)();
    }
};

class evaluator
{
public:
    std::unique_ptr<expression> parse(const char *); ///< Parse an expression

private:
    std::unique_ptr<expression> parse_number(const char *&);   ///< Parse numeric constants
    std::unique_ptr<expression> parse_atom(const char *&);     ///< Parse nested expression
    std::unique_ptr<expression> parse_summands(const char *&); ///< Parse '+' and '-' operations
    std::unique_ptr<expression> parse_factors(const char *&);  ///< Parse '*' and '/' operations
};

std::unique_ptr<expression> evaluator::parse_number(const char *&s)
{
    assert("Sanity check" && s && std::isdigit(*s));
    std::unique_ptr<number_token> nt(new number_token(0));
    // Convert number...

    while (*s && std::isdigit(*s))
    {
        nt->value_ = nt->value_ * 10 + *s++ - '0';
    }
    return std::move(nt);
}

std::unique_ptr<expression> evaluator::parse_atom(const char *&s)
{
    assert("Sanity check" && s);
    if (*s == 0)
    {
        throw std::runtime_error("Atom parse error: unexpected EOS");
    }
    else if (*s == '(')
    {
        s++;
        std::unique_ptr<expression> atom = parse_summands(s);
        if (*s == ')')
        {
            s++;
            return atom;
        }
        throw std::runtime_error("Atom parse error: unbalanced brackets");
    }
    else if (std::isdigit(*s))
    {
        std::unique_ptr<expression> atom = parse_number(s);
        return atom;
    }
    throw std::runtime_error("Atom parse error: unexpected char");
}

std::unique_ptr<expression> evaluator::parse_factors(const char *&s)
{
    assert("Sanity check" && s);
    std::unique_ptr<expression> left = parse_atom(s);
    while (*s)
    {
        if (*s == '*')
        {
            s++;
            std::unique_ptr<expression> right = parse_atom(s);
            auto mul = std::unique_ptr<mul_type>(new mul_type(std::move(left), std::move(right)));
            left = std::move(mul);

            continue;
        }
        else if (*s == '/')
        {
            s++;
            std::unique_ptr<expression> right = parse_atom(s);
            auto div = std::unique_ptr<div_type>(new div_type(std::move(left), std::move(right)));
            left = std::move(div);
            continue;
        }
        return left;
    }
    return left;
}

std::unique_ptr<expression> evaluator::parse_summands(const char *&s)
{
    assert("Sanity check" && s);
    std::unique_ptr<expression> left = parse_factors(s);
    while (*s)
    {
        if (*s == '+')
        {
            s++;
            std::unique_ptr<expression> right = parse_factors(s);
            auto sum = std::unique_ptr<plus_type>(new plus_type(std::move(left), std::move(right)));
            left = std::move(sum);

            continue;
        }
        else if (*s == '-')
        {
            s++;
            std::unique_ptr<expression> right = parse_factors(s);
            auto minus = std::unique_ptr<minus_type>(new minus_type(std::move(left), std::move(right)));
            left = std::move(minus);
            continue;
        }
        return left;
    }
    return left;
}

std::unique_ptr<expression> evaluator::parse(const char *s)
{
    return parse_summands(s);
}

int evaluate(const char *const e)
{
    evaluator ev;
    std::unique_ptr<expression> ex = ev.parse(e);
    assert("Sanity check" && ex);
    return (*ex)();
}

// s= evaluate(“(4+3)*2/5” );
// s= evaluate(“((12+9)/2)*5”);
int main()
{
    {
        int a = evaluate("(4+3)*2/5");
        assert("Unexpected result" && a == 2);
        std::cout << "\"(4+3)*2/5\" = " << a << std::endl;
    }
    {
        int a = evaluate("((12+9)/2)*5");
        assert("Unexpected result" && a == 50);
        std::cout << "\"((12+9)/2)*5\" = " << a << std::endl;
    }
    {
        int a = evaluate("(3/2+2*4)*7+(4-6/3)+1-10");
        // assert("Unexpected result" && a == 74);
        std::cout << "\"(3/2+2*4)*7+(4-6/3)+1-10\" = " << a << std::endl;
    }
    return 0;
}
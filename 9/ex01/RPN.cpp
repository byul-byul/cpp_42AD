#include <sstream>
#include <stack>
#include <stdexcept>
#include <cctype>
#include "RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(RPN const &other)
{
    (void)other;
}

RPN &RPN::operator=(RPN const &other)
{
    (void)other;
    return *this;
}

RPN::~RPN()
{
}

static bool isOperator(std::string const &token)
{
    return token.size() == 1
        && (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/');
}

int RPN::evaluate(std::string const &expression)
{
    std::istringstream iss(expression);
    std::stack<int> values;
    std::string token;

    while (iss >> token)
    {
        if (isOperator(token))
        {
            if (values.size() < 2)
                throw std::runtime_error("RPN: not enough operands");

            int b = values.top();
            values.pop();
            int a = values.top();
            values.pop();
            int result = 0;

            switch (token[0])
            {
                case '+':
                    result = a + b;
                    break;
                case '-':
                    result = a - b;
                    break;
                case '*':
                    result = a * b;
                    break;
                case '/':
                    if (b == 0)
                        throw std::runtime_error("RPN: division by zero");
                    result = a / b;
                    break;
            }
            values.push(result);
        }
        else if (token.size() == 1 && std::isdigit(static_cast<unsigned char>(token[0])))
        {
            values.push(token[0] - '0');
        }
        else
        {
            throw std::runtime_error("RPN: invalid token");
        }
    }

    if (values.size() != 1)
        throw std::runtime_error("RPN: invalid expression");

    return values.top();
}

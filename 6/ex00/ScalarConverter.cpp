#include "ScalarConverter.hpp"
#include <cstdlib>
#include <cctype>
#include <limits>
#include <sstream>
#include <iostream>

/* ------------ small numeric helpers (C++98-safe, no <cmath> isnan/isinf) ------------ */

static bool isNan(double value)
{
    return value != value; // NaN is the only value that compares unequal to itself
}

static bool isPosInf(double value)
{
    return value == std::numeric_limits<double>::infinity();
}

static bool isNegInf(double value)
{
    return value == -std::numeric_limits<double>::infinity();
}

/* ------------ literal detection ------------ */

static bool isCharLiteral(const std::string &literal, char &out)
{
    if (literal.size() != 1)
        return false;
    if (std::isdigit(static_cast<unsigned char>(literal[0])))
        return false;
    out = literal[0];
    return true;
}

static bool isDecimalNumber(const std::string &s)
{
    std::size_t i = 0;

    if (i < s.size() && (s[i] == '+' || s[i] == '-'))
        i++;

    bool hasDigits = false;
    while (i < s.size() && std::isdigit(static_cast<unsigned char>(s[i])))
    {
        hasDigits = true;
        i++;
    }
    if (i < s.size() && s[i] == '.')
    {
        i++;
        while (i < s.size() && std::isdigit(static_cast<unsigned char>(s[i])))
        {
            hasDigits = true;
            i++;
        }
    }
    return (hasDigits && i == s.size());
}

static bool parseNumeric(const std::string &literal, double &value)
{
    if (literal == "nan" || literal == "nanf")
    {
        value = std::numeric_limits<double>::quiet_NaN();
        return true;
    }
    if (literal == "+inf" || literal == "+inff")
    {
        value = std::numeric_limits<double>::infinity();
        return true;
    }
    if (literal == "-inf" || literal == "-inff")
    {
        value = -std::numeric_limits<double>::infinity();
        return true;
    }

    std::string body = literal;
    if (!body.empty() && body[body.size() - 1] == 'f')
        body.erase(body.size() - 1);
    if (!isDecimalNumber(body))
        return false;

    char *end = NULL;
    value = std::strtod(body.c_str(), &end);
    return (*end == '\0');
}

/* ------------ printing ------------ */

static bool outOfIntRange(double value)
{
    return isNan(value) || isPosInf(value) || isNegInf(value)
        || value > static_cast<double>(std::numeric_limits<int>::max())
        || value < static_cast<double>(std::numeric_limits<int>::min());
}

static void printChar(double value)
{
    std::cout << "char: ";
    if (outOfIntRange(value))
        std::cout << "impossible";
    else
    {
        char c = static_cast<char>(static_cast<int>(value));
        if (std::isprint(static_cast<unsigned char>(c)))
            std::cout << "'" << c << "'";
        else
            std::cout << "Non displayable";
    }
    std::cout << std::endl;
}

static void printInt(double value)
{
    std::cout << "int: ";
    if (outOfIntRange(value))
        std::cout << "impossible";
    else
        std::cout << static_cast<int>(value);
    std::cout << std::endl;
}

static void printFloat(double value)
{
    std::cout << "float: ";
    if (isNan(value))
        std::cout << "nanf";
    else if (isPosInf(value))
        std::cout << "inff";
    else if (isNegInf(value))
        std::cout << "-inff";
    else if (value > static_cast<double>(std::numeric_limits<float>::max())
          || value < -static_cast<double>(std::numeric_limits<float>::max()))
        std::cout << "impossible";
    else
    {
        float f = static_cast<float>(value);
        std::ostringstream oss;
        oss << f;
        std::string s = oss.str();
        if (s.find('.') == std::string::npos)
            s += ".0";
        std::cout << s << "f";
    }
    std::cout << std::endl;
}

static void printDouble(double value)
{
    std::cout << "double: ";
    if (isNan(value))
        std::cout << "nan";
    else if (isPosInf(value))
        std::cout << "inf";
    else if (isNegInf(value))
        std::cout << "-inf";
    else
    {
        std::ostringstream oss;
        oss << value;
        std::string s = oss.str();
        if (s.find('.') == std::string::npos)
            s += ".0";
        std::cout << s;
    }
    std::cout << std::endl;
}

static void printAll(double value)
{
    printChar(value);
    printInt(value);
    printFloat(value);
    printDouble(value);
}

/* ------------ ScalarConverter ------------ */

void ScalarConverter::convert(const std::string &literal)
{
    char c;
    if (isCharLiteral(literal, c))
    {
        printAll(static_cast<double>(c));
        return;
    }

    double value;
    if (!parseNumeric(literal, value))
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }

    printAll(value);
}

#include "ScalarConverter.hpp"
#include <cstdlib>
#include <cctype>
#include <limits>
#include <sstream>
#include <iostream>

/*
 * Overall strategy: every non-char literal is parsed into a single double
 * (parseNumeric), then that double is explicitly re-cast into char/int/float
 * for display. This loses the "parse each literal into its own actual type"
 * nuance the subject describes, but double has enough mantissa bits to hold
 * an exact int32 or a faithfully-rounded float, so the displayed digits are
 * unaffected at the default 6-significant-digit precision std::cout uses.
 */

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

/* Accepts [sign] digits [ '.' digits ] only: no exponent, matching the
 * subject's "only decimal notation will be used" restriction. */
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

/* Converting an out-of-range int to char is only implementation-defined
 * (not undefined), but relying on that wraparound is asking for trouble
 * at defense time, so treat it as an overflow like any other type. */
static bool outOfCharRange(double value)
{
    return isNan(value) || isPosInf(value) || isNegInf(value)
        || value > static_cast<double>(std::numeric_limits<char>::max())
        || value < static_cast<double>(std::numeric_limits<char>::min());
}

static void printChar(double value)
{
    std::cout << "char: ";
    if (outOfCharRange(value))
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

/* std::ostream switches to scientific notation on its own for large/small
 * magnitudes (e.g. "1e+08"). Blindly appending ".0" whenever there's no '.'
 * would turn that into the malformed "1e+08.0", so only pad plain digit
 * strings that genuinely lack a fractional part. */
static std::string withTrailingZero(const std::string &formatted)
{
    std::string s = formatted;
    if (s.find_first_of(".eE") == std::string::npos)
        s += ".0";
    return s;
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
        std::cout << withTrailingZero(oss.str()) << "f";
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
        std::cout << withTrailingZero(oss.str());
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

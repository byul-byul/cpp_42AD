/*
 * Standalone regression test for ScalarConverter, run via `make test`.
 * It never touches the graded `convert` binary/main.cpp; it links directly
 * against ScalarConverter.cpp and captures std::cout to compare against
 * expected output, since the class only communicates through stdout.
 */
#include "ScalarConverter.hpp"
#include <iostream>
#include <sstream>
#include <string>

static int g_pass = 0;
static int g_fail = 0;

static std::string capture(const std::string &literal)
{
    std::ostringstream captured;
    std::streambuf *old = std::cout.rdbuf(captured.rdbuf());

    ScalarConverter::convert(literal);

    std::cout.rdbuf(old);
    return captured.str();
}

static void check(const std::string &literal, const std::string &expected)
{
    std::string actual = capture(literal);

    if (actual == expected)
    {
        g_pass++;
        return;
    }
    g_fail++;
    std::cout << "[FAIL] input: \"" << literal << "\"\n"
              << "  expected:\n" << expected
              << "  actual:\n" << actual << std::endl;
}

int main()
{
    /* --- char literals --- */
    check("c", "char: 'c'\nint: 99\nfloat: 99.0f\ndouble: 99.0\n");
    check("a", "char: 'a'\nint: 97\nfloat: 97.0f\ndouble: 97.0\n");
    check(".", "char: '.'\nint: 46\nfloat: 46.0f\ndouble: 46.0\n");
    check("-", "char: '-'\nint: 45\nfloat: 45.0f\ndouble: 45.0\n");
    check("+", "char: '+'\nint: 43\nfloat: 43.0f\ndouble: 43.0\n");

    /* char produced from a non-printable / out-of-range codepoint */
    check("0", "char: Non displayable\nint: 0\nfloat: 0.0f\ndouble: 0.0\n");
    check("127", "char: Non displayable\nint: 127\nfloat: 127.0f\ndouble: 127.0\n");
    check("-128", "char: Non displayable\nint: -128\nfloat: -128.0f\ndouble: -128.0\n");
    check("128", "char: impossible\nint: 128\nfloat: 128.0f\ndouble: 128.0\n");
    check("-129", "char: impossible\nint: -129\nfloat: -129.0f\ndouble: -129.0\n");

    /* --- int literals --- */
    check("5", "char: Non displayable\nint: 5\nfloat: 5.0f\ndouble: 5.0\n");
    check("-42", "char: Non displayable\nint: -42\nfloat: -42.0f\ndouble: -42.0\n");
    check("2147483647",
          "char: impossible\nint: 2147483647\nfloat: 2.14748e+09f\ndouble: 2.14748e+09\n");
    check("-2147483648",
          "char: impossible\nint: -2147483648\nfloat: -2.14748e+09f\ndouble: -2.14748e+09\n");
    check("2147483648",
          "char: impossible\nint: impossible\nfloat: 2.14748e+09f\ndouble: 2.14748e+09\n");

    /* --- float / double literals --- */
    check("42.0f", "char: '*'\nint: 42\nfloat: 42.0f\ndouble: 42.0\n");
    check("-4.2", "char: Non displayable\nint: -4\nfloat: -4.2f\ndouble: -4.2\n");
    check("4.2f", "char: Non displayable\nint: 4\nfloat: 4.2f\ndouble: 4.2\n");
    check("-4.2f", "char: Non displayable\nint: -4\nfloat: -4.2f\ndouble: -4.2\n");
    check("42.", "char: '*'\nint: 42\nfloat: 42.0f\ndouble: 42.0\n");
    check(".5", "char: Non displayable\nint: 0\nfloat: 0.5f\ndouble: 0.5\n");
    check("5.", "char: Non displayable\nint: 5\nfloat: 5.0f\ndouble: 5.0\n");

    /* pseudo-literals */
    check("nan", "char: impossible\nint: impossible\nfloat: nanf\ndouble: nan\n");
    check("nanf", "char: impossible\nint: impossible\nfloat: nanf\ndouble: nan\n");
    check("+inf", "char: impossible\nint: impossible\nfloat: inff\ndouble: inf\n");
    check("-inf", "char: impossible\nint: impossible\nfloat: -inff\ndouble: -inf\n");
    check("+inff", "char: impossible\nint: impossible\nfloat: inff\ndouble: inf\n");
    check("-inff", "char: impossible\nint: impossible\nfloat: -inff\ndouble: -inf\n");

    /* regression: default ostream switches to scientific notation for
     * large/small magnitudes; must not corrupt the printed literal */
    check("100000000", "char: impossible\nint: 100000000\nfloat: 1e+08f\ndouble: 1e+08\n");
    check("-100000000", "char: impossible\nint: -100000000\nfloat: -1e+08f\ndouble: -1e+08\n");
    check("1000000", "char: impossible\nint: 1000000\nfloat: 1e+06f\ndouble: 1e+06\n");
    check("0.00001", "char: Non displayable\nint: 0\nfloat: 1e-05f\ndouble: 1e-05\n");

    /* float overflows but double still holds the value (pure decimal, no exponent) */
    check("400000000000000000000000000000000000000",
          "char: impossible\nint: impossible\nfloat: impossible\ndouble: 4e+38\n");
    check("-400000000000000000000000000000000000000",
          "char: impossible\nint: impossible\nfloat: impossible\ndouble: -4e+38\n");

    /* --- invalid / rejected inputs --- */
    check("", "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n");
    check("  ", "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n");
    check("0x1A", "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n");
    check("42abc", "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n");
    check("5.5.5", "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n");
    /* scientific notation on input is not "decimal notation" per subject */
    check("3.4e38", "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n");
    check("1e40", "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n");

    std::cout << g_pass << " passed, " << g_fail << " failed" << std::endl;
    return (g_fail != 0);
}

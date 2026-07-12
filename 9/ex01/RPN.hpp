#ifndef RPN_HPP
# define RPN_HPP

# include <string>

class RPN
{
    public:
        static int evaluate(std::string const &expression);

    private:
        RPN();
        RPN(RPN const &other);
        RPN &operator=(RPN const &other);
        ~RPN();
};

#endif

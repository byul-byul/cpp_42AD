/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bh <bh@student.42.fr>                      #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-11-27 21:34:53 by bh                #+#    #+#             */
/*   Updated: 2025-11-27 21:34:53 by bh               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>
# include <exception>

class Bureaucrat; // forward declaration

class Form
{
    public:
                            Form( void );
                            Form( const std::string &name, int gradeToSign, int gradeToExecute) ;
                            Form(const Form &other);
                            Form&  operator=(const Form &other);
                           ~Form();

        const std::string&  getName( void ) const;
        bool                isSigned( void ) const;
        int                 getGradeToSign( void ) const;
        int                 getGradeToExecute( void ) const;

        void                beSigned(const Bureaucrat &b);

        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };

    private:

        const std::string _name;
        bool              _isSigned;
        const int         _gradeToSign;
        const int         _gradeToExecute;
};

std::ostream &operator<<(std::ostream &os, const Form &f);

#endif

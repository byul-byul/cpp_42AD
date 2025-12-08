/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bh <bh@student.42.fr>                      #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-11-30 03:54:08 by bh                #+#    #+#             */
/*   Updated: 2025-11-30 03:54:08 by bh               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>
# include <iostream>
# include <exception>

class Bureaucrat;

class AForm
{
    public:

        AForm();
        AForm(const std::string &name,
            const std::string &target,
            int gradeToSign,
            int gradeToExecute);
        AForm(const AForm &other);
        AForm &operator=(const AForm &other);
        virtual ~AForm();

        // Getters
        const std::string &getName() const;
        const std::string &getTarget() const;
        bool              isSigned() const;
        int               getGradeToSign() const;
        int               getGradeToExecute() const;

        // Actions
        void              beSigned(const Bureaucrat &b);
        void              execute(const Bureaucrat &executor) const;

        // Exceptions
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

        class FormNotSignedException : public std::exception
            {
            public:
                virtual const char *what() const throw();
        };

    private:
        const std::string _name;
        bool              _isSigned;
        const int         _gradeToSign;
        const int         _gradeToExecute;
        const std::string _target;

        virtual void      executeAction() const = 0;
};

std::ostream &operator<<(std::ostream &os, const AForm &f);

#endif

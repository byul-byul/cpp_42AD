/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bh <bh@student.42.fr>                      #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-11-27 11:44:14 by bh                #+#    #+#             */
/*   Updated: 2025-11-27 11:44:14 by bh               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <exception>

class Bureaucrat
{
    public:

                        Bureaucrat( void );
                        Bureaucrat( const std::string &name, int grade );
                        Bureaucrat( const Bureaucrat &other );
             Bureaucrat &operator=( const Bureaucrat &other );
                       ~Bureaucrat( void );

        const std::string&  getName() const;
        int                 getGrade() const;

        void                incrementGrade();
        void                decrementGrade();

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

        const std::string   _name;
        int                 _grade;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b);

#endif

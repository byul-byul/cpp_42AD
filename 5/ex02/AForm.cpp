/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bh <bh@student.42.fr>                      #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-11-30 03:56:36 by bh                #+#    #+#             */
/*   Updated: 2025-11-30 03:56:36 by bh               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

/* ------------ Orthodox Canonical Form ------------ */

AForm::AForm()
    : _name("DefaultForm"),
      _isSigned(false),
      _gradeToSign(150),
      _gradeToExecute(150),
      _target("DefaultTarget")
{
}

AForm::AForm(const std::string &name,
             const std::string &target,
             int gradeToSign,
             int gradeToExecute)
    : _name(name),
      _isSigned(false),
      _gradeToSign(gradeToSign),
      _gradeToExecute(gradeToExecute),
      _target(target)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw AForm::GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &other)
    : _name(other._name),
      _isSigned(other._isSigned),
      _gradeToSign(other._gradeToSign),
      _gradeToExecute(other._gradeToExecute),
      _target(other._target)
{
}

AForm &AForm::operator=(const AForm &other)
{
    if (this != &other)
        _isSigned = other._isSigned;
    return *this;
}

AForm::~AForm()
{
}

/* ---------------------- Getters ---------------------- */

const std::string &AForm::getName() const
{
    return _name;
}

const std::string &AForm::getTarget() const
{
    return _target;
}

bool AForm::isSigned() const
{
    return _isSigned;
}

int AForm::getGradeToSign() const
{
    return _gradeToSign;
}

int AForm::getGradeToExecute() const
{
    return _gradeToExecute;
}

/* --------------------- beSigned / execute --------------------- */

void AForm::beSigned(const Bureaucrat &b)
{
    if (b.getGrade() > _gradeToSign)
        throw AForm::GradeTooLowException();
    _isSigned = true;
}

void AForm::execute(const Bureaucrat &executor) const
{
    if (!_isSigned)
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > _gradeToExecute)
        throw AForm::GradeTooLowException();
    executeAction();
}

/* ---------------------- Exceptions ---------------------- */

const char *AForm::GradeTooHighException::what() const throw()
{
    return "Form grade is too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "Form grade is too low";
}

const char *AForm::FormNotSignedException::what() const throw()
{
    return "Form is not signed";
}

/* ------------------- Insertion operator ------------------- */

std::ostream &operator<<(std::ostream &os, const AForm &f)
{
    os << "Form \"" << f.getName()
       << "\", target: \"" << f.getTarget() << "\""
       << ", signed: " << (f.isSigned() ? "yes" : "no")
       << ", grade to sign: " << f.getGradeToSign()
       << ", grade to execute: " << f.getGradeToExecute()
       << ".";
    return os;
}

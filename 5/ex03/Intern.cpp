#include "Intern.hpp"

/* ------------ Canonical ------------ */

Intern::Intern() {}

Intern::Intern(const Intern &other)
{
    (void)other;
}

Intern &Intern::operator=(const Intern &other)
{
    (void)other;
    return *this;
}

Intern::~Intern() {}

/* ------------ Static creators ------------ */

AForm* Intern::createShrub(const std::string &target)
{
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobo(const std::string &target)
{
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPardon(const std::string &target)
{
    return new PresidentialPardonForm(target);
}

/* ------------ makeForm ------------ */

AForm *Intern::makeForm(const std::string &formName,
                        const std::string &target) const
{
    std::string names[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    FormCreator creators[3] = {
        &Intern::createShrub,
        &Intern::createRobo,
        &Intern::createPardon
    };

    for (int i = 0; i < 3; i++)
    {
        if (formName == names[i])
        {
            std::cout << "Intern creates " << formName << std::endl;
            return creators[i](target);
        }
    }

    std::cout << "Intern: unknown form \"" << formName << "\"" << std::endl;
    return NULL;
}

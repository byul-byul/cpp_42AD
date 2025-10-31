/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bh <bh@student.42.fr>                      #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-30 16:16:21 by bh                #+#    #+#             */
/*   Updated: 2025-10-30 16:16:21 by bh               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Brain.hpp"
# include <iostream>

Brain::Brain(void)
{
    std::cout << "Brain: Default constructor called" << std::endl;
}

Brain::Brain(const Brain& other)
{
    std::cout << "Brain: Copy constructor called" << std::endl;
    for (int i = 0; i < 100; ++i)
        _ideas[i] = other._ideas[i];
}

Brain&  Brain::operator=(const Brain& rhs)
{
    std::cout << "Brain: Copy assignment operator called" << std::endl;
    if (this != &rhs)
        for (int i = 0; i < 100; ++i)
            _ideas[i] = rhs._ideas[i];
    return *this;
}

Brain::~Brain(void)
{
    std::cout << "Brain: Destructor called" << std::endl;
}

const std::string&  Brain::getIdea(int idx) const
{
    static const std::string empty = "";
    if (idx < 0 || idx >= 100)
        return empty;
    return _ideas[idx];
}

void    Brain::setIdea(int idx, const std::string& idea)
{
    if (idx < 0 || idx >= 100)
        return;
    _ideas[idx] = idea;
}

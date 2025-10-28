/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 13:01:51 by bhajili           #+#    #+#             */
/*   Updated: 2025/09/15 13:39:29 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    // 1) Basic heap case + manual delete
    Zombie* heap = newZombie("Heapman");
    heap->announce();
    delete heap;

    // 2) Stack case via helper (auto-destruction at function end)
    randomChump("Stackman");

    // 3) Multiple heap zombies; delete in reverse order
    Zombie* a = newZombie("Alice");
    Zombie* b = newZombie("Bob");
    a->announce();
    b->announce();
    delete b; // ensure destructor messages work out of creation order
    delete a;

    // 4) Scoped stack zombie (destructor at block end)
    {
        Zombie scoped("Scoped");
        scoped.announce();
    }

    // 5) Name with special ASCII characters
    randomChump("Zed-42_[!]?");

    return 0;
}

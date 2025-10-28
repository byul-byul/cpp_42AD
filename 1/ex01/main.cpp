/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 13:01:51 by bhajili           #+#    #+#             */
/*   Updated: 2025/09/15 15:36:20 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

int main(void)
{
    std::cout << std::endl << "[T1] Basic horde N=9\n";
    int N = 9;
    Zombie* h1 = zombieHorde(N, "Heapman");
    for (int i = 0; i < N; ++i) h1[i].announce();
    delete [] h1;

    std::cout << std::endl << "[T2] Single-element horde N=1\n";
    Zombie* h2 = zombieHorde(1, "Solo");
    if (h2) { h2[0].announce(); delete [] h2; }

    std::cout << std::endl << "[T3] Edge N=0 (expect NULL, no allocation)\n";
    Zombie* h3 = zombieHorde(0, "Zero");
    std::cout << "h3 is " << (h3 ? "NOT NULL (ERROR)" : "NULL (OK)") << "\n";

    std::cout << std::endl << "[T4] Edge N=-3 (expect NULL, no allocation)\n";
    Zombie* h4 = zombieHorde(-3, "Negative");
    std::cout << "h4 is " << (h4 ? "NOT NULL (ERROR)" : "NULL (OK)") << "\n";

    std::cout << std::endl << "[T5] Special chars in name\n";
    Zombie* h5 = zombieHorde(3, "Zed-42_[!]?");
    for (int i = 0; i < 3; ++i) h5[i].announce();
    delete [] h5;

    std::cout << std::endl << "[T6] Small batches N=2..4\n";
    for (int k = 2; k <= 4; ++k) {
        std::cout << "  - Batch N=" << k << "\n";
        Zombie* hk = zombieHorde(k, "Batch");
        for (int i = 0; i < k; ++i) hk[i].announce();
        delete [] hk;
    }

    std::cout << "[DONE]\n";
    return 0;
}

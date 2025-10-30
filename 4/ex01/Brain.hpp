/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bh <bh@student.42.fr>                      #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-30 16:16:18 by bh                #+#    #+#             */
/*   Updated: 2025-10-30 16:16:18 by bh               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>

class Brain
{
    public:

                             Brain( void );
                             Brain( const Brain& other) ;
                             Brain& operator=( const Brain& rhs );
                            ~Brain( void );

        const std::string&  getIdea( int idx ) const;
        void                setIdea( int idx, const std::string& idea );

    private:

        std::string         _ideas[100];
};

#endif

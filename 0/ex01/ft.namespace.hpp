/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.namespace.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 13:40:46 by bhajili           #+#    #+#             */
/*   Updated: 2025/05/04 13:43:36 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NAMESPACE_H
# define FT_NAMESPACE_H

# include <string>

namespace	ft
{
	int			ft_isdigits(std::string str);
	int			ft_isalphas(std::string str);
	std::string	ft_toupper(std::string str);
}

#endif
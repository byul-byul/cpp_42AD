/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.namespace.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 13:40:46 by bhajili           #+#    #+#             */
/*   Updated: 2025/09/13 14:08:42 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NAMESPACE_H
# define FT_NAMESPACE_H

# include <string>
# include <cstddef>

namespace	ft
{
	bool		ft_isdigits(const std::string& str);
	bool		ft_isalphas(const std::string& str);
	int			ft_atoi(const std::string& str);
	void		ft_toupper(std::string& str);
}

#endif
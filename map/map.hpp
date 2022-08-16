/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 15:42:01 by fmauguin          #+#    #+#             */
/*   Updated: 2022/08/11 15:49:20 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

namespace ft
{

	class map
	{
	public:
		map(void) {}
		map(map const &src) { *this = src; }
		~map(void) {}

		map &operator=(map const &rhs)
		{
			(void)rhs;
			return *this;
		}
	};
} // namespace ft

#endif
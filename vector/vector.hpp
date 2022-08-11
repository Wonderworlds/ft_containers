/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 15:31:04 by fmauguin          #+#    #+#             */
/*   Updated: 2022/08/11 15:47:31 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

namespace ft
{

#include <iostream>

	class vector
	{
	private:
	public:
		vector(void) {}
		vector(vector const &src) { *this = src; }
		~vector(void) {}

		vector &operator=(vector const &rhs)
		{
			(void)rhs;
			return *this;
		}
	};

} // namespace ft

#endif

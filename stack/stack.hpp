/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 15:40:58 by fmauguin          #+#    #+#             */
/*   Updated: 2022/08/11 15:48:06 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
#define STACK_HPP

namespace ft
{

	class stack
	{
	public:
		stack(void) {}
		stack(stack const &src) { *this = src; }
		~stack(void) {}

		stack &operator=(stack const &rhs)
		{
			(void)rhs;
			return *this;
		}
	};
} // namespace ft

#endif
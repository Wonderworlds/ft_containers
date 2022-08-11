/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 14:58:31 by fmauguin          #+#    #+#             */
/*   Updated: 2022/08/11 14:59:53 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Vector.hpp"

#ifndef __GNUC__
#pragma region Constructor &&Destructor
#endif

Vector::Vector(void)
{
	DEBUG_LOG("Vector: Default Constructor called");
	return;
}

Vector::Vector(Vector const &src)
{
	DEBUG_LOG("Vector: Copy Constructor called");
	*this = src;

	return;
}

Vector::~Vector(void)
{
	DEBUG_LOG("Vector: Destructor called");
	return;
}

#ifndef __GNUC__
#pragma endregion Constructor &&Destructor
#endif

Vector &Vector::operator=(Vector const &rhs)
{
	DEBUG_LOG("Vector: Assignment operator called");

	(void)rhs;
	return *this;
}

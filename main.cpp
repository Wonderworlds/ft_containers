/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 15:00:27 by fmauguin          #+#    #+#             */
/*   Updated: 2022/08/16 18:51:11 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#if DEBUG // CREATE A REAL STL EXAMPLE
#include <map>
#include <stack>
#include <vector>
namespace ft = std;
#else
#include <map.hpp>
#include <stack.hpp>
#include <vector.hpp>
#endif

#define PRINT(A) std::cout << A << std::endl

#ifdef DEBUG
#define DEBUG_LOG(A) PRINT(A)
#else
#define DEBUG_LOG(A)
#endif

int main(void)
{
	ft::vector<long double> a;
	ft::vector<double> b;

	PRINT("Hello World!");
	PRINT(a.max_size());
	PRINT(b.max_size());
	DEBUG_LOG("debug");
	return (0);
}
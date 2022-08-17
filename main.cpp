/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 15:00:27 by fmauguin          #+#    #+#             */
/*   Updated: 2022/08/17 15:59:14 by fmauguin         ###   ########.fr       */
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
	{
		ft::vector<long double> a;
		ft::vector<double> b;

		PRINT("Hello World!");
		PRINT(a.size());
		PRINT(b.size());
		PRINT(a.empty());
		PRINT(b.empty());
		PRINT(a.capacity());
		PRINT(b.capacity());
		PRINT(a.max_size());
		PRINT(b.max_size());
		DEBUG_LOG("debug");
	}
	{
		ft::vector<int> myvector;
		int *p;
		unsigned int i;

		// allocate an array with space for 5 elements using vector's allocator:
		p = myvector.get_allocator().allocate(5);

		// construct values in-place on the array:
		for (i = 0; i < 5; i++)
			myvector.get_allocator().construct(&p[i], i);

		std::cout << "The allocated array contains:";
		for (i = 0; i < 5; i++)
			std::cout << ' ' << p[i];
		std::cout << '\n';

		// destroy and deallocate:
		for (i = 0; i < 5; i++)
			myvector.get_allocator().destroy(&p[i]);
		myvector.get_allocator().deallocate(p, 5);
	}
	return (0);
}
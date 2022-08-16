/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 15:31:04 by fmauguin          #+#    #+#             */
/*   Updated: 2022/08/16 18:48:05 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
#include <cstddef>

namespace ft
{

	template <class T, class Alloc = std::allocator<T> >
	class vector
	{
	public:
		typedef T value_type;
		typedef Alloc allocator_type;
		typedef typename Alloc::reference reference;
		typedef typename Alloc::const_reference const_reference;
		typedef typename Alloc::pointer pointer;
		typedef typename Alloc::const_pointer const_pointer;
		typedef typename std::ptrdiff_t difference_type;
		typedef typename std::size_t size_type;

		explicit vector(const allocator_type &alloc = allocator_type())
			: _alloc(alloc), _start(NULL), _end(NULL), _max_end(NULL) {}
		// explicit vector (size_type n, const value_type& val = value_type(),
		//          const allocator_type& alloc = allocator_type()) {}

		// template <class InputIterator>
		// vector (InputIterator first, InputIterator last,
		//          const allocator_type& alloc = allocator_type()) {}
		// vector(const vector &x)
		// 	: _alloc(x._alloc), _start(NULL), _end(NULL), _max_end(NULL) {}

		virtual ~vector()
		{
		}

		size_type size() const
		{
			if(this->_start == NULL)
				return (0);
			return (this->_end - this->_start);
		}
		
		size_type max_size() const
		{
			return (_alloc.max_size());
		}
		
	private:
		allocator_type _alloc;
		pointer _start;
		pointer _end;
		pointer _max_end;
	};

} // namespace ft

#endif

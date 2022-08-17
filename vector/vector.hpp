/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 15:31:04 by fmauguin          #+#    #+#             */
/*   Updated: 2022/08/17 17:11:10 by fmauguin         ###   ########.fr       */
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

		explicit vector(size_type n, const value_type &val = value_type(),
						const allocator_type &alloc = allocator_type())
			: _alloc(alloc), _start(NULL), _end(NULL), _max_end(NULL)
		{
			this->_start = this->_alloc.allocate(n);
			this->_max_end = this->_start + n;
			this->_end = this->_start;
			while (n--)
			{
				this->_alloc.construct(this->_end, val);
				this->_end++;
			}
		}

		// template <class InputIterator>
		// vector (InputIterator first, InputIterator last,
		//          const allocator_type& alloc = allocator_type()) {}
		vector(const vector &x)
			: _alloc(x._alloc), _start(NULL), _end(NULL), _max_end(NULL)
		{
			// insert
			return;
		}

		virtual ~vector()
		{
			this->clear();
			this->_alloc.deallocate(this->_start, this->capacity());
			return;
		}

		vector &operator=(const vector &x)
		{
			if (this != &x)
			{
				this->clear();
				this->_alloc = x.get_allocator();
				// insert
			}
			return *this;
		}
		size_type size() const
		{
			return (this->_end - this->_start);
		}

		size_type max_size() const
		{
			return (_alloc.max_size());
		}
		size_type capacity() const
		{
			return (this->_max_end - this->_start);
		}

		bool empty() const
		{
			return ((this->size()) ? false : true);
		}
		allocator_type get_allocator() const
		{
			return (this->_alloc);
		}

		void clear()
		{
			size_type save_size = this->size();
			for (size_type i = 0; i < save_size; i++)
			{
				_end--;
				_alloc.destroy(_end);
			}
		}

	private:
		allocator_type _alloc;
		pointer _start;
		pointer _end;
		pointer _max_end;
	};

} // namespace ft

#endif

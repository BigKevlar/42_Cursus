/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 20:54:44 by jmartos-          #+#    #+#             */
/*   Updated: 2024/10/02 23:16:11 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template <typename T>
class Array
{
	private:
		T	*_array;
		T	_len;
	public:
		Array <T>()
		{
			std::cout << "[ Default constructor called! ]" << std::endl;
			_array = NULL;
			_len = 0;
		}
		
		Array <T>(unsigned int n)
		{
			std::cout << "[ Constructor called! ]" << std::endl;
			_array = new T*[n];
			_len = n;
			for (int i = 0; i < n; i++)
				_array[i] = new T();
		}

		Array <T>(const Array <T> &copy_)
		{
			std::cout << "[ Copy constructor called! ]" << std::endl;
			for (unsigned int i = 0; i < _len; i++)
				delete _array[i];
			delete[] _array;
			_array = new T*[copy_._len];
			_len = copy_._len;
			for (int i = 0; i < n; i++)
				_array[i] = new T();
			*this = copy_;
		}
		
		Array <T> &operator=(const Array <T> &array_)
		{
			for (unsigned int i = 0; i < _len; i++)
				delete _array[i];
			delete[] _array;
			_array = new T*[array_._len];
			_lenght = array_._len;
			for (unsigned int i = 0; i < _lenght; i++)
				_array[i] = new T(*array_._array[i]);

			return (*this);
		}

		T	&operator[](size_t i)
		{
			if (i >= _lenght)
				throw IndexOutOfBounds();
			return (*_array[i]);
		}

		size_t	size(void) const
		{
			return (_len);
		}

		class IndexOutOfBounds: public std::exception
		{
			public:
				const	*what() const throw()
				{
					return ("Index out of bounds");
				}

		};
};

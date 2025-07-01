/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 20:54:44 by jmartos-          #+#    #+#             */
/*   Updated: 2024/10/03 11:47:39 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cstdlib>

template <typename T>
class Array
{
	private:
		T				*_array;
		unsigned int	_len;
	public:
		Array <T> ()
		{
			std::cout << "[ Default constructor called! ]" << std::endl;
			_len = 0;
			_array = NULL;
		}

		~Array <T> ()
		{
			if (_array != NULL)
				delete [] _array;
		}
		
		Array <T> (unsigned int n)
		{
			std::cout << "[ Constructor called! ]" << std::endl;
			_len = n;
			_array = new T[_len];
		}

		Array <T> (const Array <T> &copy_)
		{
			std::cout << "[ Copy constructor called! ]" << std::endl;
			_len = copy_._len;
			_array = new T[copy_._len];
			for (unsigned int i = 0; i < _len; i++)
				_array[i] = copy_._array[i];
			*this = copy_;
		}
		
		Array <T> &operator=(const Array <T> &array_)
		{
			if (_array != NULL)
				delete [] _array;
			_array = new T[array_._len];
			_len = array_._len;
			for (unsigned int i = 0; i < _len; i++)
				_array[i] = array_._array[i];
			return (*this);
		}

		T &operator[](size_t i)
		{
			if (i >= _len)
				throw IndexIsOutOfBounds();
			return (_array[i]);
		}

		class IndexIsOutOfBounds: public std::exception
		{
			public:
				virtual char const	*what() const throw()
				{
					return ("Index out of bounds");
				}

		};

		size_t	size(void) const
		{
			return (_len);
		}
};

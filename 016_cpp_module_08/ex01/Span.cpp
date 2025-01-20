/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:05:18 by jmartos-          #+#    #+#             */
/*   Updated: 2025/01/17 15:59:00 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _size(0), _position(0), _storage() {
    std::cout << "[ Default constructor called! ]" << std::endl;
}

Span::Span(unsigned int N_) : _size(N_), _position(0), _storage() {
    std::cout << "[ Constructor called! ] -> " << "Making a '" << N_ << "' container size of storage." << std::endl;
    _storage.reserve(N_);
}

Span::Span(const Span &copy_) : _size(copy_._size), _position(copy_._position), _storage(copy_._storage) {
	std::cout << "[ Copy constructor called! ]" << std::endl;
}

Span::~Span() {
    std::cout << "[ Destructor called! ]" << std::endl;
}

Span &Span::operator=(const Span &src) {
    std::cout << "[ Overload assignation operator called! ]" << std::endl;
    if (this != &src) {
        _size = src._size;
        _position = src._position;
        _storage = src._storage;
    }
    else {
        std::cout << "[ Same info. Copy abort! ]" << std::endl;
    }
    return (*this);
}

void Span::addNumber(int number_) {
    if (this->_position < this->_size) {
        this->_storage.push_back(number_);
        this->_position++;
    }
    else {
        throw StorageFullException();
    }
}

int Span::shortestSpan() {
    if (this->_storage.empty()) {
        throw StorageEmptyException();
    }
    else if (this->_storage.size() < 2) {
        throw StorageFullException();
    }
    std::vector<int> tmp = _storage;
    std::sort(tmp.begin(), tmp.end());
    int min = tmp[1] - tmp[0];
    for (unsigned int i = 1; i < tmp.size(); i++) {
        if ((tmp[i] - tmp[i - 1]) < min)
            min = tmp[i] - tmp[i - 1];
    }
    return min;
}

int Span::longestSpan() {
    if (this->_storage.empty()) {
        throw StorageEmptyException();
    }
    else if (this->_size < 2) {
        throw StorageFullException();
    }
    std::vector<int> tmp = _storage;
    std::sort(tmp.begin(), tmp.end());
    int max = tmp[tmp.size() - 1] - tmp[0];
    return max;
}

char const *Span::StorageFullException::what() const throw() {
    return ("Storage is full!");
}

char const *Span::StorageEmptyException::what() const throw() {
    return ("Storage is empty!");
}
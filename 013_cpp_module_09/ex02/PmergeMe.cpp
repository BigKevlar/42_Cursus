/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:12:17 by jmartos-          #+#    #+#             */
/*   Updated: 2025/02/10 19:48:53 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : _v(), _d()
{
    std::cout << "[ Default constructor called! ]" << std::endl;
}

PmergeMe::~PmergeMe()
{
    std::cout << "[ Destructor called! ]" << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe &copy) : _v(copy._v), _d(copy._d)
{
    std::cout << "[ Copy constructor called! ]" << std::endl;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &src)
{
    std::cout << "[ Overload assignation operator called! ]" << std::endl;
    if (this != &src) {
        this->_v = src._v;
        this->_d = src._d;
    }
    else {
        std::cout << "[ Same info. Copy abort! ]" << std::endl;
    }
    return (*this);
}

std::string PmergeMe::itoa(int number) {
    std::stringstream ascii;
    ascii << number;
    return ascii.str();
}

int PmergeMe::errorControl(int ac, char **av)
{
    if (ac < 3) {
        std::cout << "ERROR" << std::endl;
        return 1;
    }
    for (int i = 1; i < ac; i++) {
        for (int j = 0; av[i][j]; j++) {
            if (av[i][j] < '0' || av[i][j] > '9') {
                std::cout << "ERROR" << std::endl;
                return 1;
            }
        }
    }
    return 0;
}

void PmergeMe::makePairs(std::vector<std::pair<int, int> > &v, std::deque<std::pair<int, int> > &d)
{
    for (size_t i = 0; i < v.size(); i++) {
        std::pair<int, int> tmp;
        if (v[i].first > v[i].second) {
            tmp = std::make_pair(v[i].second, v[i].first);
        } else {
            tmp = v[i];
        }
        v[i] = tmp;         // RELLENAMOS UN VECTOR.
        d.push_back(tmp);   // RELLENAMOS UN DEQUE.
    }
}

void PmergeMe::separateVector(std::vector<std::pair<int, int> > &v)
{
    _v.clear(); // LIMPIAMOS EL VECTOR PRIVADO (OJO, ES DIFERENTE A LA DEL DEQUE).
    for (size_t i = 0; i < v.size(); i++) {
        if (v[i].first < v[i].second) {
            _v.push_back(v[i].first);
            _v.push_back(v[i].second);
        } else {
            _v.push_back(v[i].second);
            _v.push_back(v[i].first);
        }
    }
}

void PmergeMe::separateDeque(std::deque<std::pair<int, int> > &d)
{
    std::deque<int>().swap(_d);     // LIMPIAMOS EL DEQUE PRIVADO (OJO, ES DIFERENTE A LA DEL VECTOR).
    for (size_t i = 0; i < d.size() / 2; i++) {
        if (d[i].first < d[i].second) {
            _d.push_back(d[i].first);
            _d.push_back(d[i].second);
        } else {
            _d.push_back(d[i].second);
            _d.push_back(d[i].first);
        }
    }
}

void PmergeMe::orderVector(containerV &_v, int last)
{
    if (last != INT_MIN) {
        _v.push_back(last);
    }
    std::sort(_v.begin(), _v.end());
}

void PmergeMe::orderDeque(containerD &_d, int last)
{
    if (last != INT_MIN) {
        _d.push_back(last);
    }
    std::sort(_d.begin(), _d.end());
}

void PmergeMe::fillContainers(int ac, char **av)
{
    for (int i = 1; i < ac; i++) {
        _v.push_back(std::atoi(av[i]));
        _d.push_back(std::atoi(av[i]));
    }    
    std::vector<std::pair<int, int> > v;    // AQUI GUARDAREMOS LA LISTA DE PARES DESORDENADA.
    std::deque<std::pair<int, int> > d;     // AQUI GUARDAREMOS LA LISTA DE PARES ORDENADA.
    int last = INT_MIN;                     // AQUI GUARDAREMOS EL ULTIMO ELEMENTO SI EXISTE.
    for (int i = 1; i < ac; i += 2) {
        if (i + 1 < ac) {
            v.push_back(std::make_pair(_v[i - 1], _v[i]));
            d.push_back(std::make_pair(_d[i - 1], _d[i]));
        } else {
            last = _v[i - 1];
            break ;
        }
    }
    // COMPROBACION QUE SE HAN RELLENADO BIEN 'V' y 'D'.
    //for (size_t i = 0; i < v.size(); i++) {
    //    std::cout << "v1 (" << v[i].first << " - " << v[i].second << ") ";
    //}
    //std::cout << std::endl;
    //for (size_t i = 0; i < d.size(); i++) {
    //    std::cout << "d1 (" << d[i].first << " - " << d[i].second << ") ";
    //}
    //std::cout << std::endl;
    // ORDENADOMOS EL CONTENEDOR 'V' E INSERTAMOS LOS CAMBIO EN EL 'D'.
    makePairs(v, d);
    // COMPROBACION QUE SE HAN ORDENADO BIEN 'V' Y 'D', DE - A +.
    //std::cout << "v.size() --> " << v.size() << std::endl;
    //for (size_t i = 0; i < v.size(); i++) {
    //    std::cout << "v2 (" << v[i].first << " - " << v[i].second << ") ";
    //}
    //std::cout << std::endl;
    //std::cout << "d.size() --> " << v.size() << std::endl;
    //for (size_t i = 0; i < d.size(); i++) {
    //    std::cout << "d2 (" << d[i].first << " - " << d[i].second << ") ";
    //}
    //std::cout << std::endl;
    // SEPARAMOS LOS ELEMENTOS GRANDES DE LOS PEQUEÑOS PARA METERLOS EN LA CLASE PRIVADA.
    separateVector(v);
    separateDeque(d);
    // COMPROBACION QUE SE HAN RELLENADO BIEN EL CONTENEDOR PRIVADO '_V' CON LOS MENORES.
    //for (size_t i = 0; i < _v.size(); i++) {
    //    std::cout << "v3 (" << _v[i] << ") ";
    //}
    //std::cout << std::endl;
    // COMPROBACION QUE SE HAN RELLENADO BIEN EL CONTENEDOR PRIVADO '_D' CON LOS MAYORES.
    //for (size_t i = 0; i < _d.size(); i++) {
    //    std::cout << "d3 (" << _d[i] << ") ";
    //}
    // ORDENAMOS LOS CONTENEDORES PRIVADOS '_V' Y '_D' Y LOS MOSTRAMOS, AL IGUAL QUE LAST (SI EXISTE).
    orderVector(_v, last);
    orderDeque(_d, last);
}
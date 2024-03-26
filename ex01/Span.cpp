/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 18:55:14 by gasouza           #+#    #+#             */
/*   Updated: 2024/03/25 21:22:16 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>
#include <climits>

Span::Span( void ): _sizeLimit(0) {}

Span::Span( int n ): _sizeLimit(n) {}

Span::Span( const Span & ref )
{
    *this = ref;
}

Span::~Span( void )
{
    this->_numbers.clear();
}

void    Span::addNumber( int n )
{
    if (this->_numbers.size() >= static_cast<size_t>(this->_sizeLimit)) {
        throw ElementsLimitReachedException();
    }

    this->_numbers.push_back(n);
}

int     Span::shortestSpan( void )
{
    if (this->_numbers.size() < 2) {
        throw MinimumElementsRequiredException();
    }

    std::vector<int> copyVec(this->_numbers);
    int minSpan = INT_MAX;

    std::sort(copyVec.begin(), copyVec.end());

    for(size_t i = 0; i < copyVec.size(); i++)
    {
        int n = copyVec[i];
        
        for(size_t q = 0; q < copyVec.size() - 1; q++)
        {
            int cmp = copyVec[q];
            int span = (cmp > n) ? cmp - n : n - cmp;
            
            if (n != cmp && span < minSpan) {
                minSpan = span;
            }
        }
    }
    
    return (minSpan != INT_MAX)? minSpan : 0;
}

int     Span::longestSpan( void )
{
    if (this->_numbers.size() < 2) {
        throw MinimumElementsRequiredException();
    }

    std::vector<int> copyVec(this->_numbers);
    int maxSpan = INT_MIN;

    std::sort(copyVec.begin(), copyVec.end());

    for(size_t i = 0; i < copyVec.size(); i++)
    {
        int n = copyVec[i];
        
        for(size_t q = 0; q < copyVec.size() - 1; q++)
        {
            int cmp = copyVec[q];
            int span= (cmp > n) ? cmp - n : n - cmp;
            
            if (n != cmp && span > maxSpan) {
                maxSpan = span;
            }
        }
    }
    
    return (maxSpan != INT_MIN)? maxSpan : 0;
}


Span &  Span::operator=( const Span & ref )
{
    if (this != &ref) {
        this->_numbers = ref._numbers;
        this->_sizeLimit = ref._sizeLimit;
    }
    
    return *this;
}

const char *Span::ElementsLimitReachedException::what( void ) const  throw()
{
    return "Already reached to max elements into Span";
}

const char *Span::MinimumElementsRequiredException::what( void ) const  throw()
{
    return "Must have at least 2 elements into span";
}
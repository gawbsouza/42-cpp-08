/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 18:55:26 by gasouza           #+#    #+#             */
/*   Updated: 2024/03/31 13:03:10 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_H
# define SPAN_H

# include <vector>
# include <exception>

class Span
{
    
private:

    std::vector<int>    _content;
    unsigned int        _spanSize;
    
public:

    Span( void );
    Span( unsigned int n );
    Span( const Span & ref );
    ~Span( void );

    static unsigned int MIN_ELEMENTS;

    void    addNumber( int n );
    int     shortestSpan( void );
    int     longestSpan( void );

    template < typename T >
    void addNumbers( T begin, T end )
    {
        this->_spanSize = std::distance(begin, end);
        this->_content.clear();
        
        while (begin != end) {
            this->addNumber(*begin);
            ++begin;
        }
    }

    Span &  operator=( const Span & ref );

    class ElementsLimitReachedException: public std::exception
    {
        public:
            virtual const char * what( void ) const  throw();
    };

    class MinimumElementsRequiredException: public std::exception
    {
        public:
            virtual const char * what( void ) const  throw();
    };
};


#endif
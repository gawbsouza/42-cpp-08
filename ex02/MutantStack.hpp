/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 21:40:22 by gasouza           #+#    #+#             */
/*   Updated: 2024/03/31 13:20:00 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANT_STACK_H
# define MUTANT_STACK_H

# include <stack>

template < typename T >
class MutantStack: public std::stack<T>
{

public:

    MutantStack( void ): std::stack<T>() {};
    MutantStack( const MutantStack & mus ): std::stack<T>() { *this = mus; };
    ~MutantStack( void ) {};

    MutantStack & operator=( const MutantStack & mus ) {
        if (this != &mus) {
            this->c = mus.c; // container -> https://en.cppreference.com/w/cpp/header/stack
        }
        return *this;
    }

    typedef typename std::stack<T>::container_type::iterator        iterator;
	typedef typename std::stack<T>::container_type::const_iterator  const_iterator;

	iterator begin( void )              { return this->c.begin();  }
	iterator end( void )                { return this->c.end();    }

	const_iterator cbegin( void ) const { return this->c.cbegin(); }
	const_iterator cend( void )   const { return this->c.cend();   }
};

#endif
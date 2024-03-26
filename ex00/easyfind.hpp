/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 17:46:21 by gasouza           #+#    #+#             */
/*   Updated: 2024/03/24 18:34:42 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASY_FIND_H
# define EASY_FIND_H

# include <iostream> 

template< typename T >
int easyFind( T const & src, int find )
{

    typename T::const_iterator  it  = src.begin();
    int                         pos = 0;
    
    while(it != src.end())
    {
        if (*it == find) {
            return pos;
        }
        
        it++;
        pos++;
    }

    return -1;
}

template < typename T >
void  printResult(T const & ref, int find )
{
    int foundAt = easyFind< T >(ref, find);
    
    if (foundAt == -1) {
        std::cout << "not found" << std::endl;
        return;
    }
    
    std::cout << "found at index " << foundAt << std::endl;
}

template < typename T >
void printElements(T const & ref)
{
    typename T::const_iterator  it  = ref.begin();
    
    std::cout << "[ ";
    while(it != ref.end())
    {
        std::cout << *it << " ";
        it++;
    }
    std::cout << "]" << std::endl;
}

#endif
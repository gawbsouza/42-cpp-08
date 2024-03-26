/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 17:52:59 by gasouza           #+#    #+#             */
/*   Updated: 2024/03/24 22:01:09 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

void testsWithVector()
{
    std::cout << "--- Tests With (Vector) ---" << std::endl << std::endl;
    
    std::vector<int> vec;

    vec.push_back(99);
    vec.push_back(-42);
    vec.push_back(21);

    std::cout << "Vector Size: " << vec.size() << std::endl;
    std::cout << "Vector Elements: "; printElements< std::vector<int> >(vec);
    
    std::cout << "Finding value 45: ";  printResult< std::vector<int> >(vec, 45);
    std::cout << "Finding value -42: "; printResult< std::vector<int> >(vec, -42);
    std::cout << "Finding value 99: ";  printResult< std::vector<int> >(vec, 99);

    std::cout << std::endl;
}

void testsWithList()
{
    std::cout << "--- Tests With (List) ---" << std::endl << std::endl;
    
    std::list<int> lst;

    lst.push_front(67);
    lst.push_front(-31);
    lst.push_back(99);
    lst.push_back(-42);

    std::cout << "List Size: " << lst.size() << std::endl;
    std::cout << "List Elements: "; printElements< std::list<int> >(lst);
    
    std::cout << "Finding value 35: ";  printResult< std::list<int> >(lst, 35);
    std::cout << "Finding value -31: "; printResult< std::list<int> >(lst, -31);
    std::cout << "Finding value 99: ";  printResult< std::list<int> >(lst, 99);
    
    std::cout << std::endl;
}

void testsWithDeque()
{
    std::cout << "--- Tests With (Deque) ---" << std::endl << std::endl;
    
    std::deque<int> deq;

    deq.push_front(26);
    deq.push_front(98);
    deq.push_back(-78);
    deq.push_back(-42);

    std::cout << "Deque Size: " << deq.size() << std::endl;
    std::cout << "Deque Elements: "; printElements< std::deque<int> >(deq);
    
    std::cout << "Finding value 99: ";  printResult< std::deque<int> >(deq, 99);
    std::cout << "Finding value -78: "; printResult< std::deque<int> >(deq, -78);
    std::cout << "Finding value 26: ";  printResult< std::deque<int> >(deq, 26);
    
    std::cout << std::endl;
}

int main()
{
    testsWithVector();
    testsWithList();
    testsWithDeque();

    return 0;
}
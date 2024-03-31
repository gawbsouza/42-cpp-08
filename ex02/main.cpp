/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 22:03:32 by gasouza           #+#    #+#             */
/*   Updated: 2024/03/31 13:29:50 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>

void subjectTests()
{
    std::cout << "--- Subject Tests ---" << std::endl << std::endl;
    
    MutantStack<int> mstack;
    
    mstack.push(5);
    mstack.push(17);
    
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    
    std::stack<int> s(mstack);

    std::cout << std::endl << std::endl;
}

void listTests()
{
    std::cout << "--- List Tests ---" << std::endl << std::endl;
    
    std::list<int> myList;
    
    myList.push_back(5);
    myList.push_back(17);
    
    std::cout << myList.back() << std::endl;
    myList.pop_back();
    std::cout << myList.size() << std::endl;
    
    myList.push_back(3);
    myList.push_back(5);
    myList.push_back(737);
    myList.push_back(0);
    
    std::list<int>::iterator it = myList.begin();
    std::list<int>::iterator ite = myList.end();
    ++it;
    --it;
    
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    
    std::list<int> s(myList); 

    std::cout << std::endl << std::endl;
}

int main()
{
    subjectTests();
    listTests();
    
    return 0;
}
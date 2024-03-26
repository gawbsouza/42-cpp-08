/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 19:44:33 by gasouza           #+#    #+#             */
/*   Updated: 2024/03/25 21:24:44 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <cstdlib>
#include <list>

void subjectTest()
{
    std::cout << "--- Subject Test ---" << std::endl << std::endl;

    Span sp = Span(5);
    
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;   

    std::cout << std::endl;
}

void minimumElementsTest()
{
    std::cout << "--- Minimum Elements Test ---" << std::endl << std::endl;

    Span sp;

    try {
        sp.shortestSpan();
    } catch( std::exception & e ) {
        std::cout << "An error was occured: " << e.what() << std::endl;
    }

    sp = Span(2);
    sp.addNumber(42);

    try {
        sp.shortestSpan();
    } catch( std::exception & e ) {
        std::cout << "An error was occured: " << e.what() << std::endl;
    }

    sp.addNumber(59);
    
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;   

    std::cout << std::endl;
}

void exceedLimitTest()
{
    std::cout << "--- Exceed Limit Test ---" << std::endl << std::endl;

    Span sp = Span(1);

    try {
        sp.addNumber(42);
        sp.addNumber(43);
    } catch( std::exception & e ) {
        std::cout << "An error was occured: " << e.what() << std::endl;
    }

    std::cout << std::endl;
}

void repeteadedNumbersTest()
{
    std::cout << "--- Repeteaded Numbers Test ---" << std::endl << std::endl;

    Span sp = Span(5);
    
    sp.addNumber(5);
    sp.addNumber(5);
    sp.addNumber(5);

    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    
    std::cout << std::endl;
}

void bigAmountTest()
{
    std::cout << "--- Big Amount of Elements Test ---" << std::endl << std::endl;
    
    int numElements = 10000;
    Span sp = Span(numElements);

    for (int i = 0; i < numElements; i++) {
        int randNum = rand() % numElements + 100;
        sp.addNumber(randNum);
    }

    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    
    std::cout << std::endl;
}

void iteratorTest()
{
    std::cout << "--- Add With Iterator Test ---" << std::endl << std::endl;
    
    std::list<int> numbers;
    
    numbers.push_back(6);
    numbers.push_back(3);
    numbers.push_back(17);
    numbers.push_back(9);
    numbers.push_back(11);

    Span sp = Span(1);

    sp.addNumbers(numbers.begin(), numbers.end());
    
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    
    std::cout << std::endl;
}

int main()
{

    subjectTest();
    repeteadedNumbersTest();
    exceedLimitTest();
    bigAmountTest();
    minimumElementsTest();
    iteratorTest();

    // TODO: adiconar metodo que recebe iterator
    // TODO: adicionar testes

    return 0;
}
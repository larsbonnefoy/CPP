/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbonnefo <lbonnefo@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 15:11:46 by lbonnefo          #+#    #+#             */
/*   Updated: 2023/05/31 15:11:47 by lbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/MutantStack.hpp"
#include <iostream>
#include <list>

int main()
{
	{
		std::cout << "---MutantStack---\n";
		MutantStack<int> mstack;

		mstack.push(5);
		mstack.push(17);

		std::cout << "First element = "<< mstack.top() << std::endl;

		mstack.pop();
		std::cout << "Size = " << mstack.size() << std::endl;

		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		++it;
		--it;
        std::cout << ">> Content of MutantStack" << std::endl;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::cout << "---Copy && Assignation MutantStack---\n";
        MutantStack<int> mstackCopy(mstack);

		MutantStack<int>::iterator itCopy = mstackCopy.begin();
		MutantStack<int>::iterator iteCopy = mstackCopy.end();

		++itCopy;
		--itCopy;
        std::cout << ">> Content of MutantStack Copy" << std::endl;
		while (itCopy != iteCopy)
		{
			std::cout << *itCopy << std::endl;
			++itCopy;
		}
        MutantStack<int> mstackAssgn;
        mstackAssgn = mstack;

		MutantStack<int>::iterator itAssgn = mstackAssgn.begin();
		MutantStack<int>::iterator iteAssign = mstackAssgn.end();

		++itAssgn;
		--itAssgn;
        std::cout << ">> Content of MutantStack Assignation" << std::endl;
		while (itAssgn != iteAssign)
		{
			std::cout << *itAssgn << std::endl;
			++itAssgn;
		}

	}
	
	{
		std::cout << "\n\n---List---\n";
		std::list<int> list;

		list.push_back(5);
		list.push_back(17);

		std::cout << "First element = " << list.back() << std::endl;

		list.pop_back();
		std::cout << "Size = "<< list.size() << std::endl;

		list.push_back(3);
		list.push_back(5);
		list.push_back(737);
		list.push_back(0);

		std::list<int>::iterator it = list.begin();
		std::list<int>::iterator ite = list.end();

		++it;
		--it;
        std::cout << ">> Content of List" << std::endl;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}
	return 0;
}

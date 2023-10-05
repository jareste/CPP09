/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jareste- <jareste-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 17:33:36 by jareste-          #+#    #+#             */
/*   Updated: 2023/10/05 17:55:38 by jareste-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}

PmergeMe::PmergeMe( const PmergeMe &pmergeme )
{
	(void)pmergeme;
}

PmergeMe::~PmergeMe(){}

PmergeMe	&PmergeMe::operator=( const PmergeMe& pmergeme )
{
	(void)pmergeme;
	return (*this);
}

void	PmergeMe::printVector(std::string msg, const std::vector<int> &vectorM)
{
	std::cout << msg ;
	for (int i = 0; i < (int)vectorM.size(); i++)
		std::cout << " " << vectorM[i];
	std::cout << std::endl;

}

void	PmergeMe::printDeque(std::string msg, const std::deque<int> &dequeM)
{
	std::cout << msg ;
	for (int i = 0; i < (int)dequeM.size(); i++)
		std::cout << " " << dequeM[i];
	std::cout << std::endl;

}

void	PmergeMe::mergeauxvec(std::vector<int>& vectorM, int left, int mid, int right)
{
	int n1 = mid - left + 1;
	int n2 = right - mid;

	std::vector<int> leftvectorM(n1);
	std::vector<int> rightvectorM(n2);
	for (int i = 0; i < n1; i++)
		leftvectorM[i] = vectorM[left + i];
	for (int j = 0; j < n2; j++)
		rightvectorM[j] = vectorM[mid + 1 + j];
	int i = 0;
	int j = 0;
	int k = left;
	while (i < n1 && j < n2)
	{
		if (leftvectorM[i] <= rightvectorM[j])
			vectorM[k] = leftvectorM[i++];
		else 
			vectorM[k] = rightvectorM[j++];
		k++;
	}
	while (i < n1)
		vectorM[k++] = leftvectorM[i++];
	while (j < n2)
		vectorM[k] = rightvectorM[j++];
}

void	PmergeMe::mergeSortvec(std::vector<int>& vectorM, int left, int right)
{
	if (left < right)
	{
		if (right - left < INSERTIONAUX)
		{
			for (int i = left + 1; i <= right; i++)
			{
				int key = vectorM[i];
				int j = i - 1;
				while (j >= left && vectorM[j] > key)
				{
					vectorM[j + 1] = vectorM[j];
					j--;
				}
				vectorM[j + 1] = key;
			}
		}
		else
		{
			int mid = left + (right - left) / 2;
			mergeSortvec(vectorM, left, mid);
			mergeSortvec(vectorM, mid + 1, right);
			mergeauxvec(vectorM, left, mid, right);
		}
	}
}

void	PmergeMe::mergeauxdeq(std::deque<int>& dequeM, int left, int mid, int right)
{
	int n1 = mid - left + 1;
	int n2 = right - mid;

	std::deque<int> leftdequeM(n1);
	std::deque<int> rightdequeM(n2);
	for (int i = 0; i < n1; i++)
		leftdequeM[i] = dequeM[left + i];
	for (int j = 0; j < n2; j++)
		rightdequeM[j] = dequeM[mid + 1 + j];
	int i = 0;
	int j = 0;
	int k = left;
	while (i < n1 && j < n2)
	{
		if (leftdequeM[i] <= rightdequeM[j])
			dequeM[k] = leftdequeM[i++];
		else 
			dequeM[k] = rightdequeM[j++];
		k++;
	}
	while (i < n1)
		dequeM[k++] = leftdequeM[i++];
	while (j < n2)
		dequeM[k] = rightdequeM[j++];
}

void	PmergeMe::mergeSortdeq(std::deque<int>& dequeM, int left, int right)
{
	if (left < right)
	{
		if (right - left < INSERTIONAUX)
		{
			for (int i = left + 1; i <= right; i++)
			{
				int key = dequeM[i];
				int j = i - 1;
				while (j >= left && dequeM[j] > key)
				{
					dequeM[j + 1] = dequeM[j];
					j--;
				}
				dequeM[j + 1] = key;
			}
		}
		else
		{
			int mid = left + (right - left) / 2;
			mergeSortdeq(dequeM, left, mid);
			mergeSortdeq(dequeM, mid + 1, right);
			mergeauxdeq(dequeM, left, mid, right);
		}
	}
}


void	PmergeMe::CheckRepeated(const std::vector<int>& vectorM)
{
	for (int i = 0; i <  (int)vectorM.size(); i++)
	{
		for (int j = 0; j < (int)vectorM.size(); j++)
		{
			if (j == i)
				continue ;
			if (vectorM[i] == vectorM[j])
				throw std::invalid_argument("Found a repeated number.");
		}
	}

}

void	PmergeMe::merge(std::string *av)
{
	std::vector<int>	vectorM;
	std::deque<int>		dequeM;

	try
	{
		for (int i = 0; av[i].length() > 0 ; i++)
			vectorM.push_back(stoi(av[i]));
		for (int i = 0; av[i].length() > 0 ; i++)
			dequeM.push_back(stoi(av[i]));
		CheckRepeated(vectorM);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		return ;
	}
	printVector("Before:", vectorM);
	clock_t startTimeVec = clock();
	mergeSortvec(vectorM, 0, vectorM.size() - 1);
	clock_t endTimeVec = clock();
	clock_t startTimeDeq = clock();
	mergeSortdeq(dequeM, 0, dequeM.size() - 1);
	clock_t endTimeDeq = clock();
	double elapsedTimeVec = static_cast<double>(endTimeVec - startTimeVec) / CLOCKS_PER_SEC * 1000000.0;
	double elapsedTimeDeq = static_cast<double>(endTimeDeq - startTimeDeq) / CLOCKS_PER_SEC * 1000000.0;
	printDeque("After:", dequeM);
	std::cout << std::fixed;
	std::cout << "Time to process a range of " << vectorM.size() << " elements with std::vector<int> : " << elapsedTimeVec << " us" << std::endl;
	std::cout << "Time to process a range of " << dequeM.size() << " elements with std::deque<int> : " << elapsedTimeDeq << " us" <<  std::endl;
}

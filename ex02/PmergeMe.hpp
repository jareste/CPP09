/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jareste- <jareste-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 17:33:44 by jareste-          #+#    #+#             */
/*   Updated: 2023/10/05 15:25:09 by jareste-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <ctime>
# include <chrono>

class PmergeMe
{
	private:
		PmergeMe();
		PmergeMe( const PmergeMe &pmergeme );
		~PmergeMe();
		PmergeMe	&operator=( const PmergeMe& pmergeme );
		static void	printDeque(std::string msg, const std::deque<int> &dequeM);
		static void	printVector(std::string msg, const std::vector<int> &vectorM);
		static void mergeauxvec(std::vector<int>& vectorM, int left, int mid, int right);
		static void	mergeSortvec(std::vector<int>& vectorM, int left, int right);
		static void mergeauxdeq(std::deque<int>& dequeM, int left, int mid, int right);
		static void mergeSortdeq(std::deque<int>& dequeM, int left, int right);
	public:
		static void	merge(std::string *av);
};

	// list
	// vector

#endif

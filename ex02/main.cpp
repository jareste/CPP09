/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jareste- <jareste-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 17:33:51 by jareste-          #+#    #+#             */
/*   Updated: 2023/10/05 17:53:37 by jareste-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int ac, char **av)
{
	if (ac < 3)
	{
		std::cerr << "Please introduce more than 2 numbers" << std::endl;
		return (1);
	}
	std::string *avc = new std::string[ac - 1];
	for (int i = 1; i  < ac; i++)
		avc[i - 1] = av[i];
	PmergeMe::merge(avc);
}
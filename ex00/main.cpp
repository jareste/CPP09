/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jareste- <jareste-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 00:47:59 by jareste-          #+#    #+#             */
/*   Updated: 2023/10/06 00:14:49 by jareste-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int ac, char **av)
{
	(void)av;
	if (ac < 2)
	{
		std::cerr << "Please introduce an argument." << std::endl;
		return (1);
	}
	int i = 0;
	try
	{
		for (i = 1; i < ac; i++)
		{
			if (i > 1)
				std::cout << std::endl << std::endl << std::endl;
			std::cout << "########## " << av[i] << " ##########" << std::endl;
			BitcoinExchange::btc(av[i]);
			std::cout << "########## " << av[i] << " ##########" << std::endl;
		}
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		std::cout << "########## " << av[i] << " ##########" << std::endl;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jareste- <jareste-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 00:48:21 by jareste-          #+#    #+#             */
/*   Updated: 2023/10/05 23:36:47 by jareste-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iomanip>
# include <map>
# include <iostream>
# include <fstream>
# include <sstream>
# include <string>

class BitcoinExchange
{
	private:
		BitcoinExchange();
		BitcoinExchange( const BitcoinExchange &bitcoinExchange );
		~BitcoinExchange();
		BitcoinExchange	&operator=( const BitcoinExchange& bitcoinExchange );
		static bool	getCSV(std::map<std::string, float> &data);
		static bool	getBTC(const std::map<std::string, float> &data, std::string file);
		static void	parseDate(std::string date);
		static void	printCSV(const std::map<std::string, float> &data);
	public:
		static void	btc(std::string av);
};

#endif

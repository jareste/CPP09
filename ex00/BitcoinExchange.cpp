/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jareste- <jareste-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 00:48:17 by jareste-          #+#    #+#             */
/*   Updated: 2023/10/06 00:13:57 by jareste-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{}

BitcoinExchange::BitcoinExchange( const BitcoinExchange &bitcoinExchange )
{
	(void)bitcoinExchange;
}

BitcoinExchange::~BitcoinExchange()
{}

BitcoinExchange	&BitcoinExchange::operator=( const BitcoinExchange& bitcoinExchange )
{
	(void)bitcoinExchange;
	return (*this);
}

void	BitcoinExchange::parseDate(std::string date)
{
	for (int i = 0; i < (int)date.length(); i++)
	{
		if (i == 4 || i == 7)
		{
			if (date[i] == '-')
				continue ;
			else
			{
				std::cout << date << " " << date[i] << std::endl;
				throw std::runtime_error("There's an error in a date.");
			}
		}
		else
		{
			if (date[i] >= '0' && date[i] <= '9')
				continue ;
			else
				throw std::runtime_error("There's an error in a date.");
		}

	}
}

bool	BitcoinExchange::getCSV(std::map<std::string, float> &data)
{
	std::ifstream file("data.csv");
	if (!file.is_open())
		throw std::runtime_error("No se pudo abrir el archivo CSV.");
	int linecount = 0;
	std::string line;
	while (std::getline(file, line))
	{
		std::istringstream linestream(line);
		std::string date;
		std::string value;

		if (std::getline(linestream, date, ',') && std::getline(linestream, value))
		{
			try
			{
				float fvalue = std::stof(value);
				parseDate(date);
				data[date] = fvalue;
			}
			catch (const std::exception& e)
			{
				if (linecount > 0)
					return true;
			}
			linecount++;
		}
	}
	return false;
}

void	parseFileLine(std::string date, float value)
{
	bool	error = false;

	if (value < 0)
		throw std::out_of_range("Error: not a positive number.");
	if (value > 1000)
		throw std::out_of_range("Error: number too large.");
	if (date.length() >= 10)
	{
		std::string	year = date.substr(0, 4);
		for (int i = 0; i < (int)year.length(); i++)
			if (!std::isdigit(year[i]))
				error = true;
		if (error == false && (std::stoi(year) > 2023 || std::stoi(year) < 2009))
			error = true;		
		std::string	month = date.substr(5, 2);
		for (int i = 0; i < (int)month.length(); i++)
			if (error == false && !std::isdigit(month[i]))
				error = true;
		if (error == false && std::stoi(month) > 12)
			error = true;
		std::string	day = date.substr(8, 2);
		for (int i = 0; i < (int)day.length(); i++)
			if (error == false && !std::isdigit(day[i]))
				error = true;
		if (error == false && std::stoi(day) > 31)
			error = true;
		if (error == false && std::stoi(day) < 2 && std::stoi(year) == 2009)
			error = true;
	}
	else
		error = true;
	if (error)
	{
		std::string	error = "Error: date ";
		error.append(date);
		error.append(" is invalid.");
		throw std::invalid_argument(error);
	}
}


bool	BitcoinExchange::getBTC(const std::map<std::string, float> &data, std::string infile)
{
	std::ifstream file(infile);
	if (!file.is_open())
	{
		std::string error;
		error = "No se pudo abrir el archivo ";
		error.append(infile);
		error.append(".");
		throw std::runtime_error(error);
	}
	(void)data;
	std::string	line;
	int	linecount = 0;
	while (std::getline(file, line))
	{
		std::istringstream linestream(line);
		std::string	date;
		std::string value;
		if (std::getline(linestream, date, '|') && std::getline(linestream, value))
		{
			try
			{
				date = date.substr(0,10);
				float fvalue = std::stof(value);
				parseFileLine(date, fvalue);
				std::map<std::string, float>::const_iterator it = data.lower_bound(date);
				if (it == data.begin() || (it != data.end() && it->first != date))
					--it;
				std::cout << date << " => " << fvalue << " = " << it->second * fvalue << std::endl;


			}
			catch (const std::exception& e)
			{
				if (linecount > 0)
					std::cout << e.what() << std::endl;
			}
			linecount++;
		}
		else
			std::cout << "Error: date " << line << " is invalid." << std::endl;
	}
	return false;
}


void	BitcoinExchange::printCSV(const std::map<std::string, float> &data)
{
	for (std::map<std::string, float>::const_iterator it = data.begin(); it != data.end(); ++it)
		std::cout << "Fecha: " << it->first << ", Valor: " << it->second << std::endl;
}

void	BitcoinExchange::btc(std::string av)
{
	(void)av;
	std::map<std::string, float> data;

	if (getCSV(data))
		throw std::runtime_error("There's an error in a date on CSV.");
	getBTC(data, av);


	// printCSV(data);


}

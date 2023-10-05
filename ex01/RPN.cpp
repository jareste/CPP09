/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jareste- <jareste-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:48:24 by jareste-          #+#    #+#             */
/*   Updated: 2023/10/06 00:38:30 by jareste-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(){}

RPN::RPN( const RPN &rpn )
{
	(void) rpn;
}

RPN::~RPN(){}

RPN	&RPN::operator=( const RPN& rpn )
{
	(void) rpn;
	return (*this);
}

int	RPN::doOpertion(char c, std::stack<int> &arr)
{
	int	first = arr.top();
	arr.pop();
	int	second = arr.top();
	arr.pop();

	std::string sign[4] = {"-","+","/","*"};
	int	i;
	for (i = 0; sign[i][0] != c; i++)
		;
	switch (i)
	{
		case 0:
			return (second - first);
		case 1:
			return (second + first);
		case 2:
			if (first == 0)
				throw std::invalid_argument("Please be smart and enter a valid input.");
			return (second / first);
		case 3:
		{
			double overflow = (static_cast<double>(second) * static_cast<double>(first));
			if (overflow > 2147483647 || overflow < -2147483648)
				throw std::invalid_argument("Overflow detected, please introduce a valid input.");
			return (second * first);
		}
	}
	return (0);
}

void	RPN::parse(std::string rpn, std::stack<int> &arr)
{
	for (int i = 0; rpn[i]; i++)
	{
		if (rpn[i] >= '0' && rpn[i] <= '9')
		{
			if ((i > 0 && rpn [i - 1] == ' ' )|| i == 0)
				arr.push(rpn[i] - '0');
			else		
				throw std::invalid_argument("Please be smart and enter a valid input.");
		}
		else if (rpn[i] == '-' || rpn[i] == '+' || rpn[i] == '/' || rpn[i] == '*')
		{
			if (i > 0 && rpn [i - 1] == ' ')
			{
				if (arr.size() > 1)
					arr.push(RPN::doOpertion(rpn[i], arr));
				else
					throw std::invalid_argument("Please enter a valid input.");
			}
			else		
				throw std::invalid_argument("Please  valid input.");
		}
		else if (rpn[i] != ' ')
			throw std::invalid_argument("Please be smart and enter a valid input.");
	}
}

int	RPN::solveRPN(std::string rpn)
{
	std::stack<int> arr;

	parse(rpn, arr);
	if (arr.size() == 1)
		return (arr.top());
	throw std::invalid_argument(" enter a valid input.");
}

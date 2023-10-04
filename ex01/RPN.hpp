/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jareste- <jareste-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:48:27 by jareste-          #+#    #+#             */
/*   Updated: 2023/10/04 17:31:23 by jareste-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>

class RPN
{
	private:
		RPN();
		RPN( const RPN &rpn );
		~RPN();
		RPN	&operator=( const RPN& rpn );
		static int		doOpertion(char c, std::stack<int> &arr);
		static void	parse(std::string rpn, std::stack<int> &arr);
	public:
		static int	solveRPN(std::string rpn);
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riamaev <riamaev@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 10:48:05 by riamaev           #+#    #+#             */
/*   Updated: 2025/01/05 10:48:10 by riamaev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

void GetStrings(int ac, char **av)
{
	for (int i = 1; i < ac; i++)
	{
		std::string str = av[i];
		for (int j = 0; j < (int)str.length(); j++)
		{
			str[j] = std::toupper(str[j]);
		}
		std::cout << str;
	}
}

int main(int ac, char **av)
{
    if (ac == 1)
    {
    	std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    }
    else
    {
    	GetStrings(ac, av);
    	std::cout << std::endl;
    }
}

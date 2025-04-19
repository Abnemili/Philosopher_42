/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnemili <abnemili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 14:37:33 by abnemili          #+#    #+#             */
/*   Updated: 2025/04/18 17:07:00 by abnemili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac != 6)
	{
		ft_putstr("Error\nInvlaide agrument number\n");
	}
	else 
	{
		while (av[i])
		{
			if (is_digit(av[i]) == 1)
			{
				ft_putstr("Error\nInvlaide input\n");
				return (1);
			}
			if (check_valide_arv(av[i]) == 1)
			{
				ft_putstr("Error\nNumber is less then 1\n");
				return (1);
			}
			i++;
		}
	}
	
}

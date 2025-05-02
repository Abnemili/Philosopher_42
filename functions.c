/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnemili <abnemili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 15:00:13 by abnemili          #+#    #+#             */
/*   Updated: 2025/05/01 15:00:14 by abnemili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "philosophers.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	write(1, "\033[31m", 5);
	while (str[i])
		ft_putchar(str[i++]);
	write(1, "\033[0m", 4);
}
int is_digit(char *av)
{
	int	i;

	i = 0;
	if (!av )
		return (1);
	while (av[i])
	{
		if (av[i] < '0' || av[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int					i;
	int					sign;
	unsigned long long	nb;

	i = 0;
	sign = 1;
	nb = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb = (nb * 10) + (nptr[i++] - 48);
		if (nb >= LLONG_MAX && sign == -1)
			return (0);
		else if (nb >= LLONG_MAX && sign == 1)
			return (-1);
	}
	return (nb * sign);
}

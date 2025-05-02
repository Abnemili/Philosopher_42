/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnemili <abnemili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 14:50:31 by abnemili          #+#    #+#             */
/*   Updated: 2025/04/21 17:16:48 by abnemili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int check_valide_av(char **av)
{
    if (ft_atoi(av[1]) > PHILO_MAX || is_digit(av[1]))
        return (ft_putstr("Error\nInvalid philosophers number\n"), 1);
    if (ft_atoi(av[2]) <= 0 || is_digit(av[2]))
        return (ft_putstr("Error\nInvalid time to die\n"), 1);
    if (ft_atoi(av[3]) <= 0 || is_digit(av[3]))
        return (ft_putstr("Error\nInvalid time to eat\n"), 1);
    if (ft_atoi(av[4]) <= 0 || is_digit(av[4]))
        return (ft_putstr("Error\nInvlalid time to sleep\n"), 1);
    if (ft_atoi(av[5]) < 0 || is_digit(av[5]))
        return (ft_putstr("Error\nInvalid times each philo should eat\n"), 1);       
    return (0);
} 
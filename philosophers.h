/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnemili <abnemili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 14:35:53 by abnemili          #+#    #+#             */
/*   Updated: 2025/04/18 16:42:49 by abnemili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>

void	ft_putstr(char *str);
void	ft_putchar(char c);
int     is_digit(char *av);
int	ft_atoi(const char *nptr);
int check_valide_arv(char *av);

#endif
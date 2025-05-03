/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnemili <abnemili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 14:35:53 by abnemili          #+#    #+#             */
/*   Updated: 2025/05/03 20:44:45 by abnemili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# include <limits.h>


# define PHILO_MAX 300

typedef pthread_mutex_t my_mutex;

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				eating;
	int				meals_eaten;
	size_t			last_meal;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			start_time;
	int				num_of_philos;
	int				num_times_to_eat;
	int				*dead;
	my_mutex	*r_fork;
	my_mutex	*l_fork;
	my_mutex	*write_lock;
	my_mutex	*dead_lock;
	my_mutex	*meal_lock;
}					t_philo;

typedef struct s_program
{
	int				dead_flag;
	my_mutex	dead_lock;
	my_mutex	meal_lock;
	my_mutex	write_lock;
	my_mutex		*philos;
}					t_program;

// parssing functions 
void	ft_putstr(char *str);
void	ft_putchar(char c);
int     is_digit(char *av);
int		ft_atoi(const char *nptr);
int		check_valide_av(char **av);

// execution part
void	init_the_program(t_program *program, t_philo *philos);
void 	init_the_forks(my_mutex *forks, int num_of_philos);
void 	init_input(t_philo*philo, char **av); // same file 
size_t	get_current_time(void);
void	*monitor(void *pointer);
void 	init_philos(t_philo *philos, t_program *program, my_mutex *forks, char **av);
int 	thread_creation (t_program *program, my_mutex *forks);
void	destory_all(char *str, t_program *program, my_mutex *forks);

// routing functions
void	*philo_routine(void *pointer);
void 	ft_eat(t_philo *philo);
void	print_mssg(char *str, t_philo *philo, int id);

#endif
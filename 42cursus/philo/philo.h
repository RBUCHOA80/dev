/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruchoa <ruchoa@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 21:17:20 by ruchoa            #+#    #+#             */
/*   Updated: 2023/08/31 21:45:25 by ruchoa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/*		INCLUDES		*/
# include <stdio.h> //printf
# include <unistd.h> //sleep
# include <stdlib.h> //malloc | free
# include <pthread.h> //pthread_lib
# include <sys/time.h> //gettimeofday

/* 
nop <- number_of_philosophers;
ttd <- time_to_die;
tte <- time_to_eat;
tts <- time_to_sleep;
pme <- number_of_times_each_philosopher_must_eat;
 */

/*		STRUCS		*/
typedef struct s_philo	t_philo;

typedef struct s_rules
{
	unsigned int	nop;
	time_t			ttd;
	time_t			tte;
	time_t			tts;
	unsigned int	pme;
	pthread_mutex_t	m_dead;
	unsigned int	dead;
	time_t			start_time;
	t_philo			**philos;
	pthread_mutex_t	**forks;
}	t_rules;

typedef struct s_philo
{
	pthread_t		thread;
	unsigned int	index;
	unsigned int	n_meals;
	pthread_mutex_t	*fork[2];
	pthread_mutex_t	m_last_meal;
	time_t			last_meal;
	t_rules			*rules;
}	t_philo;

/*		PROTOTYPES		*/
int		philo(t_rules *rules);
int		ft_atoi(const char *str);
int		ft_check_arg(int argc, char **argv);
void	ft_error_msg(void);
int		ft_free(t_rules *rules);
time_t	ft_get_time(void);
void	*ft_hunger(void *rules);
t_rules	*ft_init(char **argv);
char	*ft_itoa(int n);
int		ft_msg(t_philo *philo, char *str);
void	*ft_routine(void *rules);
int		ft_strcmp(char *s1, char *s2);
void	ft_take_eat_sleep_think(t_philo *philo);

#endif

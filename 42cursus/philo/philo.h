/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruchoa <ruchoa@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 21:17:20 by ruchoa            #+#    #+#             */
/*   Updated: 2023/08/26 00:00:23 by ruchoa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/*		INCLUDES  */
# include <stdio.h> //printf
# include <stdlib.h> //malloc | free
# include <pthread.h> //pthread_lib
# include <sys/time.h> //gettimeofday

/* 
nop -> number_of_philosophers;
ttd -> time_to_die;
tte -> time_to_eat;
tts -> time_to_sleep;
pme -> number_of_times_each_philosopher_must_eat;
 */

typedef struct s_philo	t_philo;

typedef struct s_rules
{
	unsigned int	nop;
	time_t			ttd;
	time_t			tte;
	time_t			tts;
	unsigned int	pme;
	time_t			start_time;
	t_philo			**philos;
	pthread_mutex_t	mutex;
}	t_rules;

typedef struct s_philo
{
	pthread_t		thread;
	unsigned int	id;
	t_rules			*rules;
}	t_philo;

/*		PROTOTYPES  */
int		philo(t_rules *rules);
void	*ft_routine(void *rules);
int		ft_atoi(const char *str);
int		ft_check_arg(int argc, char **argv);
t_rules	*ft_create_rules(char **argv);
int		ft_free_rule(t_rules *rules);
char	*ft_itoa(int n);
void	ft_msg(void);
int		ft_strcmp(char *s1, char *s2);
time_t	ft_get_time(void);

#endif

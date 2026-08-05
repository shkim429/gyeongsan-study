/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 20:24:03 by sohuikim          #+#    #+#             */
/*   Updated: 2026/08/05 19:26:12 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define NO_EAT_LIMIT 0
# define INVALID_NUM -1

# include <stdbool.h>
# include <pthread.h>

typedef enum e_thread_status
{
	THREAD_SUCCESS,
	THREAD_FAILURE
}	t_thread_status;

typedef enum e_philo_state
{
	PHILO_ALIVE,
	PHILO_FULL,
	PHILO_DEAD
}	t_philo_state;

typedef enum e_task_state
{
	TASK_RUNNING,
	TASK_END,
	TASK_ERROR,
}	t_task_state;

typedef struct s_end
{
	bool			is_end;
	pthread_mutex_t	mutex;
}	t_end;

typedef struct s_start
{
	bool			is_start;
	pthread_mutex_t	mutex;
}	t_start;

typedef struct s_meal
{
	long long		last_time;
	int				eat_cnt;
	pthread_mutex_t	mutex;
}	t_meal;

typedef struct s_fork
{
	bool			is_taken;
	pthread_mutex_t	mutex;
}	t_fork;

typedef struct s_shared_data
{
	int				philo_num;
	int				time_to_eat;
	int				time_to_die;
	int				time_to_sleep;
	int				must_eat_cnt;
	long long		time_to_start;
	t_start			start;
	t_end			end;
	pthread_mutex_t	print_mutex;
}	t_shared_data;

typedef struct s_philo
{
	int				id;
	t_meal			meal;
	pthread_t		thread;
	t_thread_status	thread_status;
	t_fork			*first_fork;
	t_fork			*second_fork;
	t_shared_data	*data;
}	t_philo;

typedef struct s_table
{
	t_philo			*philos;
	t_fork			*forks;
	t_shared_data	data;
	pthread_t		monitor_thread;
	t_thread_status	monitor_status;
}	t_table;

/* cleanup.c */

void		cleanup_table(t_table *table);

/* init_philo.c */

bool		init_philos(t_table *table);
void		set_last_meal_times(t_philo *philos, long long start_time);

/* init_table.c */

bool		init_table(int argc, char **argv, t_table *table);

/* monitor.c */

void		*run_monitor_task(void *arg);

/* mutex_destroy.c */

void		destroy_meal_mutex(t_philo *philos, int init_cnt);
void		destroy_fork_mutex(t_fork *forks, int init_cnt);
void		destroy_shared_data_mutex(t_shared_data *data);

/* philo_parse.c */

bool		parse_args(int argc, char **argv, t_shared_data *data);

/* philo_print.c */

bool		print_philo_action(t_philo *philo, char *message);
bool		print_philo_taken_forks(t_philo *philo);
bool		print_philo_death(t_philo *philo);

/* philo_tasks_fork.c */

t_task_state	pickup_forks(t_philo *philo);
bool			put_down_forks(t_philo *philo);

/* philo_task_single.c */

void		*run_single_philo_task(void *arg);

/* philo_tasks.c */

void		*run_philo_task(void *arg);

/* state.c */

bool		set_philos_end(t_shared_data *data);
bool		check_philos_end(t_shared_data *data, bool *is_end);
bool		update_meal_time(t_meal *meal, long long start_time);
bool		update_meal_cnt(t_meal *meal);
bool		wait_for_start(t_shared_data *data);

/* thread.c */

bool		start_philos(t_table *table);

/* time.c */

bool		get_time_ms(long long *now);

/* wait.c */

bool		wait_for_start(t_shared_data *data);
bool		delay_even_philo(t_philo *philo);

#endif
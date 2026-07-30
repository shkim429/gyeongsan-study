/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 20:24:03 by sohuikim          #+#    #+#             */
/*   Updated: 2026/07/30 17:22:45 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define NO_EAT_LIMIT 0
# define INVALID_NUM -1

#include <stdbool.h>
#include <pthread.h>

typedef enum e_fork_status
{
	FORK_SUCCESS,
	FORK_FAILURE,
	FORK_BUSY
}	t_fork_status;
typedef enum e_thread_status
{
	TRHEAD_SUCCESS,
	TRHEAD_FAILURE
}	t_thread_status;

typedef enum e_philo_state
{
	PHILO_ALIVE,
	PHILO_FULL,
	PHILO_DEAD
}	t_philo_state;

typedef struct s_end
{
	bool			is_end;
	pthread_mutex_t	mutex;
}	t_end;

typedef struct s_meal
{
	long long		last_time; /* 마지막 식사 시각 */
	int				eat_cnt; /* 식사 횟수 */
	pthread_mutex_t	mutex;
}	t_meal;

typedef struct s_fork
{
	int				id; /* 나중에 지우기 */
	bool			is_taken; /* who is taken */
	pthread_mutex_t	mutex; /* lock 도구 */
}	t_fork;

typedef struct s_shared_data
{
	int			philo_num; /* 철학작 수 */
	int				time_to_eat; /* 식사 시간 */
	int				time_to_die; /* 굶은 시간 */
	int				time_to_sleep; /* 잠자는 시간 */
	int				must_eat_cnt; /* 식사해야만 하는 횟수 */
	long long		time_to_start;/*  프로그램 시작 시간 */
	t_end			end;
	pthread_mutex_t	print_mutex;
}	t_shared_data;

typedef struct s_philo
{
	int			id; /* 철학자 식별 번호 */
	t_meal			meal; /* 마지막 식사 시각 */
	pthread_t		thread; /* 철학자 스레드 식별자 */
	t_thread_status	thread_status;
	t_fork			*first_fork; 
	t_fork			*second_fork;
	t_shared_data	*data;
}	t_philo;

typedef struct s_table // 공유되는 자원
{
	t_philo			*philos;
	t_fork			*forks;
	t_shared_data	data;
	pthread_t		monitor_thread;
	t_thread_status	monitor_status;
}	t_table;

/* cleanup.c */

void	free_table(t_table *table);

/* init_philo.c */

bool	init_philos(t_table *table);
void	set_last_meal_times(t_philo *philos, long long start_time);

/* init_table.c */

bool	init_table(int argc, char **argv, t_table *table);

/* monitor.c */

void	*run_monitor_task(void *arg);

/* mutex_destroy.c */

void	destroy_meal_mutex(t_philo *philos, int init_cnt);
void	destroy_fork_mutex(t_fork *forks, int init_cnt);

/* philo_parse.c */

bool	parse_args(int argc, char **argv, t_shared_data *data);

/* philo_print.c */

bool	print_philo_action(t_philo *philo, char *message);
bool	print_philo_taken_forks(t_philo *philo);
bool	print_philo_death(t_philo *philo);

/* philo_state.c */

bool	set_philos_end(t_shared_data *data);
bool	check_philos_end(t_shared_data *data, bool *is_end);
bool	update_meal_state(t_meal *meal, long long start_time);

/* philo_tasks_fork.c */

bool		pick_up_forks(t_philo *philo);
bool		put_down_forks(t_philo *philo);

/* philo_tasks.c */

void	*run_philo_task(void *arg);

/* time.c */

long long	get_time_ms(void);

#endif
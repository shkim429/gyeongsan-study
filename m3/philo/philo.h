/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 20:24:03 by sohuikim          #+#    #+#             */
/*   Updated: 2026/03/10 16:17:27 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

typedef struct s_philo
{
	long	*input_arr;
	int		*philo_arr;
	int		*fork_arr;
	int		philo_num;
}	t_philo;

typedef enum s_state_msg
{
	EATING,
	SLEEP,
	THINKING,
	DIE
}	t_state_msg;

#endif

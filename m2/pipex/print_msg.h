/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_msg.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 03:15:02 by sohuikim          #+#    #+#             */
/*   Updated: 2026/02/11 03:15:41 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_MSG_H

# define PRINT_MSG_H

void	print_cur_exe_name(char **argv);
void	print_errno(char **argv, char *error_obj);
void	print_error_msg(char **argv, char *error_obj);

#endif
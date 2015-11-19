/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebena <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/06 19:50:19 by arebena           #+#    #+#             */
/*   Updated: 2015/11/19 14:37:49 by arebena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../srcs/Libft/srcs/libft.h"
# include "../srcs/GNL/get_next_line.h"
# include "lem_struct.h"


int		*str_to_tab(char *str, char c);
char	map_anthill(t_lem *lem);
char	islink(char *line);
char	*get_name(char *line);
char	isroom(char *line);
int     room_by_name(t_lem *lem, char *name);
char	ft_isnbrs(char *str);
char	check_for_room(t_lem *lem, char *line, char *stat);
char	check_for_link(t_lem *lem, char *line, char *stat);
char	check_for_lems(t_lem *lem, char *line, char *stat);
int		*dup_tab(int *tab);

#endif

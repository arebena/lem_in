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

# include "libft.h"
# include "get_next_line.h"
# include "lem_struct.h"

int     *new_buffer(int len);
void    way_upload(t_lem *lem, int *buff, int stase, int turn);
void    matrix_run(t_lem *lem, int *buff, int room, int turn);
void    show_way(t_way *way);
t_lemin *lem_del(t_lem *lem, int id);
void    print_result(t_lem *lem);
void    lem_through(t_lem *lem);
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_struct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebena <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/06 19:54:00 by arebena           #+#    #+#             */
/*   Updated: 2015/11/21 04:58:18 by arebena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_STRUCT_H
# define LEM_STRUCT_H

# define ON 1
# define OFF 0
# define ERROR -1
# define STDIN 0
# define OFLAG lem->order_flag
# define ROOMS lem->rooms

typedef struct		s_opt
{
	char			mx;
	char			gway;
	char			sall;
}					t_opt;

typedef struct		s_lemin
{
	int				id;
	char			*name;
	int				id_way;
	int				pos;
	struct s_lemin	*next;
}					t_lemin;

typedef struct		s_way
{
	int				id;
	int				*way;
	int				len;
	int				lem_on;
	struct s_way	*next;
}					t_way;

typedef struct		s_lem
{
	t_opt			opt;
	t_way			*way;
	t_way			*shorter;
	t_lemin			*lem_in;
	int				short_size;
	unsigned int	lems;
	char			order_flag;
	char			**rooms;
	char			**matrix;
	char			*anthill;
	char			*m_esc;
	int				mlen;
	int				in_n_out;
	int				w_flag;
	int				s_flag;
}					t_lem;

#endif

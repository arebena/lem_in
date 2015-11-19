/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_struct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebena <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/06 19:54:00 by arebena           #+#    #+#             */
/*   Updated: 2015/11/19 15:00:09 by arebena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_STRUCT_H
# define LEM_STRUCT_H

# define ON 1
# define OFF 0
# define STDIN 0
# define ERROR -1
# define OFLAG lem->order_flag
# define ROOMS lem->rooms

# define DB while(1);

typedef struct		s_lem
{
	unsigned int	lems;
	char			order_flag;
	char			**rooms;
	char			**matrix;
}					t_lem;

#endif

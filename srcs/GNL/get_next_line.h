/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebena <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/17 16:25:10 by arebena           #+#    #+#             */
/*   Updated: 2015/10/22 16:38:59 by arebena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "../Libft/srcs/libft.h"

# define ON 1
# define OFF 0
# define FAIL -1
# define BUFF_SIZE 20
# define MAX_BUFF_SIZE 10000000
# define LXN(a,b) ft_lstxnew(a,b)
# define SDUP(a) ft_strdup(a)

int		get_next_line(int const fd, char **line);
char	line_sorter(char **line, char *buf, int fd);
char	archiving(char **line, char *page, int fd, int del);

#endif

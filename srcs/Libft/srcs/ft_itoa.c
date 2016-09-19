/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebena <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 22:25:13 by arebena           #+#    #+#             */
/*   Updated: 2014/11/26 16:06:19 by arebena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int			i;
	int			digit;
	long int	nb;
	char		*str;
	char		*mem;

	if (!(str = (char *)malloc(ft_intlen(n) + 1)))
		return (NULL);
	if (mem = str, n == 0)
		return (str = "0", ft_strcpy(mem, str));
	if (nb = n, n < 0)
		if ((nb = -nb) > 0)
			str[ft_intlen(-nb) - 1] = '-';
	i = 0;
	while (digit = nb % 10, nb != 0 && (i < (ft_intlen(n))))
		if (nb /= 10, digit < 10)
			str[i++] = '0' + digit;
		else
			str[i++] = 'A' + digit - 10;
	str[ft_intlen(n)] = '\0';
	str = ft_strrev (str);
	ft_strcpy(mem, str);
	return (mem);
}

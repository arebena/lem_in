/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebena <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 18:40:58 by arebena           #+#    #+#             */
/*   Updated: 2014/11/11 16:26:28 by arebena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isalnum(int c)
{
	if (c >= 304)
		return (0);
	else if ((unsigned char)c >= 'A' && (unsigned char)c <= 'Z')
		return (1);
	else if ((unsigned char)c >= 'a' && (unsigned char)c <= 'z')
		return (1);
	else if ((unsigned char)c >= '0' && (unsigned char)c <= '9')
		return (1);
	else
		return (0);
}

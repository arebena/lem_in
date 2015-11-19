/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebena <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 18:31:14 by arebena           #+#    #+#             */
/*   Updated: 2014/11/11 16:34:57 by arebena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isalpha(int c)
{
	if (c > 300)
		return (0);
	else if ((unsigned char)c >= 'A' && (unsigned char)c <= 'Z')
		return (1);
	else if ((unsigned char)c >= 'a' && (unsigned char)c <= 'z')
		return (1);
	else
		return (0);
}

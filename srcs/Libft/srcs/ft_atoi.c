/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebena <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 21:19:14 by arebena           #+#    #+#             */
/*   Updated: 2014/11/26 16:13:00 by arebena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	int nb;
	int i;
	int flag;

	i = -1;
	nb = 0;
	while (((char)str[++i] < '0' || (char)str[i] > '9') && (char)str[i] != '-')
		if ((char)str[i] >= 9 && (char)str[i] <= 13)
			;
		else if ((char)str[i] != '+' && (char)str[i] != ' ')
			return (0);
		else if ((char)str[i] == '+' || (char)str[i] == '-')
			if (((char)str[i + 1] < '0' || (char)str[i + 1] > '9'))
				return (0);
	if (flag = 0, (char)str[i++] == '-')
		flag = 1;
	else
		i--;
	while ((char)str[i] != '\0' && (char)str[i] >= '0' && (char)str[i] <= '9')
		nb = nb * 10 + (char)str[i++] - '0';
	if (flag == 1)
		nb *= -1;
	return (nb);
}

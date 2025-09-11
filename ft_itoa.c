/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahhammad <ahhammad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 10:55:19 by ahhammad          #+#    #+#             */
/*   Updated: 2025/09/11 17:00:41 by ahhammad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	return_string(char *str, long num, int len)
{
	if (num < 0)
	{
		str[0] = '-';
		num = -num;
	}
	if (num == 0)
		str[0] = '0';
	while (num)
	{
		str[--len] = (num % 10) + '0';
		num /= 10;
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	long	num;
	int		len;

	num = n;
	if (num <= 0)
		len = 1;
	else
		len = 0;
	while (n)
	{
		n /= 10;
		len++;
	}
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	return_string(str, num, len);
	return (str);
}

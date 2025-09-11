/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahhammad <ahhammad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 14:55:03 by ahhammad          #+#    #+#             */
/*   Updated: 2025/09/10 10:21:05 by ahhammad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	index;

	index = 0;
	while ((char)c != s[index])
	{
		if (!s[index])
			return (0);
		index++;
	}
	return ((char *)&s[index]);
}

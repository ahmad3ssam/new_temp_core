/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahhammad <ahhammad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 21:38:31 by ahhammad          #+#    #+#             */
/*   Updated: 2025/09/11 17:00:52 by ahhammad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*str;
	size_t				index;

	str = (const unsigned char *)s;
	index = 0;
	while (index < n)
	{
		if (str[index] == (unsigned char)c)
			return ((void *)&str[index]);
		index++;
	}
	return (NULL);
}

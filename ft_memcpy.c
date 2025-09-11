/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahhammad <ahhammad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 21:20:36 by ahhammad          #+#    #+#             */
/*   Updated: 2025/09/11 17:00:57 by ahhammad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*ptr_dest;
	unsigned char	*ptr_src;
	size_t			i;

	i = 0;
	ptr_src = (void *)src;
	ptr_dest = dest;
	while (ptr_src[i] != '\0' && i < n)
	{
		ptr_dest[i] = ptr_src[i];
		i++;
	}
	return (ptr_dest);
}

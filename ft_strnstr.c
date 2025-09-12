/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahhammad <ahhammad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 01:11:31 by ahhammad          #+#    #+#             */
/*   Updated: 2025/09/11 17:22:27 by ahhammad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!str && !len)
		return (0);
	if (to_find[0] == '\0' || to_find == str)
		return ((char *)str);
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i + j] == to_find[j] && (i + j) < len)
		{
			if (str[i + j] == '\0' && to_find[j] == '\0')
				return ((char *)&str[i]);
			j++;
		}
		if (to_find[j] == '\0')
			return ((char *)&(str[i]));
		i++;
	}
	return (0);
}
// #include <stdio.h>
// #include "libft.h"   // your ft_strnstr prototype

// int main(void)
// {
//     const char *s = "Hello world!";
//     char *res;

//     // Case 1: substring in the middle
//     res = ft_strnstr(s, "world", 12);
//     printf("Case 1: %s\n", res ? res : "NULL");

//     // Case 2: substring present but len too small
//     res = ft_strnstr(s, "world", 5);
//     printf("Case 2: %s\n", res ? res : "NULL");

//     // Case 3: empty needle -> must return haystack
//     res = ft_strnstr(s, "", 5);
//     printf("Case 3: %s\n", res ? res : "NULL");

//     // Case 4: empty haystack, non-empty needle
//     res = ft_strnstr("", "test", 4);
//     printf("Case 4: %s\n", res ? res : "NULL");

//     // Case 5: both haystack and needle empty
//     res = ft_strnstr("", "", 0);
//     printf("Case 5: %s\n", res ? res : "NULL");

//     // Case 6: needle longer than haystack
//     res = ft_strnstr("short", "longneedle", 10);
//     printf("Case 6: %s\n", res ? res : "NULL");

//     // Case 7: match at the very end
//     res = ft_strnstr("abcdef", "def", 6);
//     printf("Case 7: %s\n", res ? res : "NULL");

//     // Case 8: match at the very end, but len shorter than match position
//     res = ft_strnstr("abcdef", "def", 5);
//     printf("Case 8: %s\n", res ? res : "NULL");

//     return 0;
// }

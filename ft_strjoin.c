/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahhammad <ahhammad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 08:13:07 by ahhammad          #+#    #+#             */
/*   Updated: 2025/09/11 17:01:47 by ahhammad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*str;
	size_t	len;

	if (s1 && !s2)
		return (ft_strdup(s1));
	if (!s1 && s2)
		return (ft_strdup(s2));
	if (!s1 && !s2)
		return (NULL);
	
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = malloc(len);
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, len);
	ft_strlcat(str, s2, len);
	return (str);
}

#include <stdio.h>
#include "libft.h"

int main(void)
{
    char *s1 = "Hello, ";
    char *s2 = "World!";
    char *result;

    // Normal case
    result = ft_strjoin(s1, s2);
    if (result)
    {
        printf("Join normal: %s\n", result);
        free(result);
    }

    // s1 is NULL
    result = ft_strjoin(NULL, s2);
    if (result)
    {
        printf("Join with s1 NULL: %s\n", result);
        free(result);
    }
    else
        printf("Join with s1 NULL: NULL\n");

    // s2 is NULL
    result = ft_strjoin(s1, NULL);
    if (result)
    {
        printf("Join with s2 NULL: %s\n", result);
        free(result);
    }
    else
        printf("Join with s2 NULL: NULL\n");

    // Both NULL
    result = ft_strjoin(NULL, NULL);
    if (result)
    {
        printf("Join with both NULL: %s\n", result);
        free(result);
    }
    else
        printf("Join with both NULL: NULL\n");

    return 0;
}

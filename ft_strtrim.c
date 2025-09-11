/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahhammad <ahhammad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 21:35:04 by ahhammad          #+#    #+#             */
/*   Updated: 2025/09/11 17:16:55 by ahhammad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int		to_trim(const char *set, char c);
char	*new_str(const char *s1, int start, int end);

char	*ft_strtrim(const char *s1, const char *set)
{
	int	i;
	int	j;

	i = 0;
	j = strlen(s1) - 1;
	if (j <= 0)
		return (NULL);
	while (to_trim(set, s1[i]))
		i++;
	while (to_trim(set, s1[j]))
		j--;
	return (new_str(s1, i, j));
}

char	*new_str(const char *s1, int head, int tail)
{
	char	*str;
	int		i;

	if (tail < 0 || head > (int)strlen(s1))
	{
		printf("%d\n%d\n", tail, head);
		return (ft_strdup(""));
	}
	str = malloc((abs(tail - head) + 1));
	printf("len %d\n", (abs(tail - head) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while ((head + i) <= tail)
	{
		str[i] = s1[head + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int	to_trim(const char *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
		{
			return (1);
		}
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	char *result;

	// 1. Basic trim with spaces
	result = ft_strtrim("   Hello World   ", " ");
	printf("Case 1: |%s|\n", result); // Expected: |Hello World|
	free(result);

	// 2. Trim dashes and spaces
	result = ft_strtrim(" ---Hello--- ", " -");
	printf("Case 2: |%s|\n", result); // Expected: |Hello|
	free(result);

	// 3. Nothing to trim (set does not match anything)
	result = ft_strtrim("Hello", "xyz");
	printf("Case 3: |%s|\n", result); // Expected: |Hello|
	free(result);

	// 4. Whole string trimmed away
	result = ft_strtrim("aaaaaa", "a");
	printf("Case 4: |%s|\n", result); // Expected: ||
	free(result);
	// printf("asddsa\n");

	// 5. Empty input string
	result = ft_strtrim("", " ");
	printf("Case 5: |%s|\n", result); // Expected: ||
	free(result);

	// 6. Set is empty (nothing removed)
	result = ft_strtrim("   abc   ", "");
	printf("Case 6: |%s|\n", result); // Expected: |   abc   |
	free(result);

	// 7. Custom example from your comment
	result = ft_strtrim("ababaaaMy name is Simonbbaaabbad", "ab");
	printf("Case 7: |%s|\n", result); // Expected: |My name is Simon|
	free(result);

	return (0);
}8*/
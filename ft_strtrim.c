/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahhammad <ahhammad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 21:35:04 by ahhammad          #+#    #+#             */
/*   Updated: 2025/09/13 10:31:50 by ahhammad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	len;
	size_t	j;
	char	*trim;

	if (!s1)
		return (NULL);
	i = 0;
	j = 0;
	len = ft_strlen(s1);
	if (len == 0)
		return (ft_strdup(""));
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	while (len && len >= i && ft_strchr(set, s1[len]))
		len--;
	trim = malloc((len - i + 2));
	if (!trim)
		return (NULL);
	while (i <= len)
		trim[j++] = s1[i++];
	trim[j] = '\0';
	return (trim);
}

/*
int	main(void)
{
	char	*result;

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
	result = ft_strtrim(" . abcd", " ");
	printf("Case 5: |%s|\n", result); // Expected: ||
	free(result);
	// 6. Set is empty (nothing removed)
	result = ft_strtrim("   abc   ", "");
	printf("Case 6: |%s|\n", result); // Expected: |   abc   |
	free(result);
	// 7. Custom example from your comment
	result=ft_strtrim("xxxz  test with x and z and x .  zx  xx z", "z x");
	printf("Case 7: |%s|\n", result); // Expected: |My name is Simon|
	printf("Case 7: |%zu|\n", ft_strlen(result));
	free(result);
	return (0);
}
*/
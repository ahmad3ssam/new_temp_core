/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahhammad <ahhammad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 11:36:28 by ahhammad          #+#    #+#             */
/*   Updated: 2025/09/12 11:00:00 by ahhammad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	words_count(const char *s, char c)
{
	int count = 0;
	int i = 0;

	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

static void	word_len(const char *s, char c, int *lenWord)
{
	int len = 0;
	int i = 0;
	int j = 0;

	while (s[i])
	{
		len = 0;
		while (s[i] && s[i] != c)
		{
			i++;
			len++;
		}
		if (len > 0)
			lenWord[j++] = len;
		if (s[i])
			i++;
	}
}

static int	allocate_words(char **arr, int *words_len_arr, int words)
{
	int i = 0;

	while (i < words)
	{
		arr[i] = (char *)malloc(words_len_arr[i] + 1);
		if (!arr[i])
		{
			while (i > 0)
				free(arr[--i]);
			return (0);
		}
		i++;
	}
	return (1);
}

static void	set_data(char **arr, const char *s, int *words_len_arr, char c)
{
	int i = 0, j, k = 0;

	while (s[i])
	{
		j = 0;
		while (j < words_len_arr[k] && s[i] != c)
		{
			arr[k][j++] = s[i++];
		}
		if (j == words_len_arr[k])
		{
			arr[k][j] = '\0';
			k++;
		}
		if (s[i])
			i++;
	}
	arr[k] = NULL;
}

char	**ft_split(const char *s, char c)
{
	int		words;
	char	**arr;
	int		*words_len_arr;

	if (!s)
		return (NULL);
	words = words_count(s, c);
	words_len_arr = (int *)malloc(words * sizeof(int));
	arr = (char **)malloc((words + 1) * sizeof(char *));
	if (!arr || !words_len_arr)
		return (NULL);
	word_len(s, c, words_len_arr);
	if (!allocate_words(arr, words_len_arr, words))
	{
		free(arr);
		free(words_len_arr);
		return (NULL);
	}
	set_data(arr, s, words_len_arr, c);
	free(words_len_arr);
	return (arr);
}

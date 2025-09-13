/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_old.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahhammad <ahhammad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 11:36:28 by ahhammad          #+#    #+#             */
/*   Updated: 2025/09/13 14:39:23 by ahhammad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	word_len(char const *s, char c, int *lenWord)
{
	int	len;
	int	i;
	int	j;

	len = 0;
	i = 0;
	j = 0;
	while (s[i])
	{
		len = 0;
		while (s[i] && s[i] != c)
		{
			i++;
			len++;
		}
		if (len > 0)
		{
			lenWord[j] = len;
			j++;
		}
		if (s[i])
			i++;
	}
}

static int	words_count(char const *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
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

void	set_data(char **arr, char const *s, int *Words_len_arr, char c)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (s[i])
	{
		j = 0;
		while (j < Words_len_arr[k] && s[i] != c)
		{
			arr[k][j] = s[i];
			j++;
			i++;
		}
		if (j != 0 && j == Words_len_arr[k] && (s[i] == c || s[i] == '\0'))
		{
			arr[k][j] = '\0';
			k++;
		}
		i++;
	}
	arr[k] = NULL;
}

char	**ft_split(char const *s, char c)
{
	int		words;
	char	**arr;
	int		*words_len_arr;
	int		i;

	if (!s)
		return (NULL);
	words = words_count(s, c);
	words_len_arr = (int *)malloc(words * sizeof(int));
	arr = (char **)malloc((words + 1) * sizeof(char *));
	if (!arr || !words_len_arr)
		return (NULL);
	word_len(s, c, words_len_arr);
	i = 0;
	while (i < words)
	{
		arr[i] = (char *)malloc(words_len_arr[i] + 1);
		if (!arr[i])
			return (NULL);
		i++;
	}
	set_data(arr, s, words_len_arr, c);
	return (arr);
}

/*
int	main(void)
{
	char	**arr;
	int		i;

	arr = ft_split("dddgH e zlo  ** World  This is   a test  ", ' ');
	i = 0;
	while (arr[i])
	{
		printf("arr[%d]: '%s'\n", i, arr[i]);
		i++;
	}
	return (0);
}
*/
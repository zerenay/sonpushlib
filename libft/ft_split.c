/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeraydog <zeraydog@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 19:32:08 by zeraydog          #+#    #+#             */
/*   Updated: 2025/07/08 02:38:13 by zeraydog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	count_words(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i] && str[i] != c)
		{
			count++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (count);
}

static int	get_word_len(char *str, char c)
{
	int	len;

	len = 0;
	while (str[len] && str[len] != c)
		len++;
	return (len);
}

static void	free_all(char **split, int words)
{
	int	i;

	i = 0;
	while (i < words)
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static char	**fill_words(char *str, char c, char **split, int word_count)
{
	int	i;
	int	j;
	int	k;
	int	len;

	i = 0;
	j = 0;
	while (str[i] && j < word_count)
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i] && str[i] != c)
		{
			len = get_word_len(&str[i], c);
			split[j] = (char *)malloc(sizeof(char) * (len + 1));
			if (!split[j])
				return (free_all(split, j), NULL);
			k = 0;
			while (str[i] && str[i] != c)
				split[j][k++] = str[i++];
			split[j][k] = '\0';
			j++;
		}
	}
	return (split);
}

char	**ft_split(char *str, char c)
{
	char	**split;
	int		word_count;

	if (!str)
		return (NULL);
	word_count = count_words(str, c);
	split = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!split)
		return (NULL);
	split = fill_words(str, c, split, word_count);
	if (!split)
		return (NULL);
	split[word_count] = NULL;
	return (split);
}

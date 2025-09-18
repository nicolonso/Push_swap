/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalfonso <nalfonso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 21:29:10 by nalfonso          #+#    #+#             */
/*   Updated: 2025/09/18 20:46:01 by nalfonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/push_swap.h"

static int	count_words(const char *s, char c)
{
	int		count;
	bool	inside_word;

	count = 0;
	while (*s)
	{
		inside_word = false;
		while (*s == c)
			++s;
		while (*s != c && *s)
		{
			if (!inside_word)
			{
				++count;
				inside_word = true;
			}
			++s;
		}
	}
	return (count);
}

/* static char	*get_next_word(char *s, char c)
{
	static int	cursor = 0;
	char		*next_word;
	int			len;
	int			i;

	len = 0;
	i = 0;
	while (s[cursor] == c)
		++cursor;
	while ((s[cursor + len] != c) && (s[cursor + len]))
		++len;
	next_word = malloc((size_t)len * sizeof(char) + 1);
	if (!next_word)
		return (NULL);
	while ((s[cursor] != c) && s[cursor])
		next_word[i++] = s[cursor++];
	next_word[i] = '\0';
	return (next_word);
} */

static char	*get_word(const char *s, int start, int end)
{
	char	*word;
	int		i;

	word = malloc((end - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (start < end)
		word[i++] = s[start++];
	word[i] = '\0';
	return (word);
}

/* char	**split(char *s, char c)
{
	int		words_count;
	char	**result_array;
	int		i;

	i = 0;
	words_count = count_words(s, c);
	if (!words_count)
		exit(1);
	result_array = malloc(sizeof(char *) * (size_t)(words_count + 2));
	if (!result_array)
		return (NULL);
	while (words_count-- >= 0)
	{
		if (i == 0)
		{
			result_array[i] = malloc (sizeof(char));
			if (!result_array)
				return (NULL);
			result_array[i++][0] = '\0';
			continue ;
		}
		result_array[i++] = get_next_word(s, c);
	}
	result_array[i] = NULL;
	return (result_array);
} */

char	**split(const char *s, char c)
{
	char	**result;
	int		i = 0, j = 0, k = 0;

	if (!s)
		return (NULL);
	result = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > j)
			result[k++] = get_word(s, j, i);
	}
	result[k] = NULL;
	return (result);
}

void	free_split(char **split)
{
	int	i;

	i = -1;
	if (!split)
		return ;
	while (split[++i])
		free(split[i]);
	free(split);
}

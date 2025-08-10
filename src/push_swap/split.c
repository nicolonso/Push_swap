/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalfonso <nalfonso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 21:29:10 by nalfonso          #+#    #+#             */
/*   Updated: 2025/08/10 13:34:45 by nalfonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/push_swap.h"

static int count_words(char *s, char c)
{
	int		count;//To store the substring count
	bool	inside_word;// A flag to indicate wheter we are inside a substring or a delimeter
	
	count = 0;
	while(*s)//Loop until the end of the string is reached
	{
		inside_word = false;//Sert the bool false to start the loop
		while (*s == c)
			++s;//Move to the next Character
		while (*s != c && *s)
		{
			if (!inside_word)//If we are not currently inside the substring
			{
				++count;//increment the count as we are about to move inside a substring
				inside_word = true;
			}
			++s;//Move to the nect character of the strin
		}
	}
	return (count);	
}
static char *get_next_word(char *s, char c)
{
	static int	cursor = 0;//To keep track of the position whitin the string 's' across multiple function calls, needed to continue processing the string from where we left off in previous calls, essential for tokenizing a string
	char		*next_word; //To store a pointer of the new substring
	int			len;//To store the lenght of the substring
	int			i;//Used dor indexing characters in the new substring

	len = 0;
	i = 0;
	while (s[cursor] == c)//Skip past any consecutive delieter characters at the current position in the sring
		++cursor;
	while ((s[cursor + len] != c) && (s[cursor + len]))//Calculate the lenght of the substring by counting characteres until either a delimiter or the end of the string is encountered
		++len;
next_word = malloc((size_t)len * sizeof(char) + 1);
if (!next_word)
	return (NULL);
while ((s[cursor] != c) && s[cursor])
	next_word[i++] = s[cursor++];
next_word[i] = '\0';
return (next_word);
}

char **split(char *s, char c)
{
	int		words_count;//used to keep track of the number of the substrings in the string
	char	**result_array;//To store a pointer to pointer, the array of all substrings
	int		i;

	i = 0;
	words_count = count_words(s, c);
	if (!words_count)//Check for '0' words
		exit(1);
	result_array = malloc(sizeof(char *) * (size_t)(words_count + 2));//Allocate memory for the result_array based on the number of words (words_count) plus two additional slots to account for the null terminator at the end of the last string, and to null terminate the entire array
	if (!result_array)
		return (NULL);
	while (words_count-- >= 0)//Iterates through the words to be split all words have been processed
	{
		if (i == 0)//check if the first characther of the input string is a delimeter
		{
			result_array[i] = malloc (sizeof(char));//Allocate memory for an empty string (a single NULL terminator)
			if (!result_array)
				return (NULL);
			result_array[i++][0] = '\0';//Include in the result array as distinct elements
			continue;
		}
		result_array[i++] = get_next_word(s, c);	
	}
	result_array[i] = NULL;//Properly NULL terminate the array
	return (result_array);
}

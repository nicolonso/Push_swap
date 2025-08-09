/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalfonso <nalfonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 20:45:23 by nalfonso          #+#    #+#             */
/*   Updated: 2025/05/06 18:20:29 by nalfonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	size_t	j;
	size_t	i;

	if (*little == '\0')
		return ((char *)big);
	i = 0;
	while (big[i] && i < n)
	{
		j = 0;
		while (little[j] && (i + j) < n && big[i + j] == little[j])
			j++;
		if (little[j] == '\0')
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}

/*#include <stdio.h>

int main()
{
	char *str = "You need to find me Ahahahhaha you got it";
	char *find = "Ahahahha";
	int n = 35;
	char *result = ft_strnstr(str,find, n);
	
	printf("%s\n", result);
	return (0);
}*/
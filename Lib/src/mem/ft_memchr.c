/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalfonso <nalfonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 20:39:40 by nalfonso          #+#    #+#             */
/*   Updated: 2025/05/03 18:29:56 by nalfonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*ptr;

	ptr = s;
	while (n--)
	{
		if (*ptr == (char)c)
			return ((void *)ptr);
		ptr++;
	}
	return (NULL);
}

/*#include <stdio.h>

int main()
{
	char *str = "Hellooo baby";
	int c = 101;
	char *result = ft_memchr(str, c,5);

	printf ("%s\n", result);
	return (0);
}*/
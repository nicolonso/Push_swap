/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalfonso <nalfonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 19:27:54 by nalfonso          #+#    #+#             */
/*   Updated: 2025/05/03 18:35:47 by nalfonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const char	*st1;
	const char	*st2;

	st1 = s1;
	st2 = s2;
	if (n == 0)
		return (0);
	while (n-- > 0)
	{
		if ((unsigned char)*st1 != (unsigned char)*st2)
			return ((unsigned char)*st1 - (unsigned char)*st2);
		st1++;
		st2++;
	}
	return (0);
}
/*#include <stdio.h>

int  main()
{
	char *s1 = "12345679";
	char *s2 = "12345688";
	int result = ft_memcmp(s1,s2,7);

	printf("%d\n", result);
	return (0);
}*/

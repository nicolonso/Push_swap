/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalfonso <nalfonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 18:21:18 by nalfonso          #+#    #+#             */
/*   Updated: 2025/05/05 18:30:21 by nalfonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, s + i);
		i++;
	}
}

/*void print_index_and_char(unsigned int i, char *c) 
{
    printf("Index: %u, Char: %c\n", i, *c);
    *c += 1; 
}

int main(void)
{
	char str[] = "abc";
	
    ft_striteri(str, print_index_and_char);
    printf("Modified string: %s\n", str);
    return (0);
}*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeraydog <zeraydog@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 14:54:43 by zeraydog          #+#    #+#             */
/*   Updated: 2025/07/08 11:37:11 by zeraydog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)(unsigned char)c)
			return ((char *)s);
		s++;
	}
	if ((char)(unsigned char)c == '\0')
		return ((char *)s);
	return (NULL);
}

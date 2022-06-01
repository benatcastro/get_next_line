/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 07:26:41 by bena              #+#    #+#             */
/*   Updated: 2022/06/01 20:55:17 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	counter;

	counter = 0;
	if (dstsize > 0)
	{
		while (src[counter] && counter < dstsize - 1)
		{
			dst[counter] = src[counter];
			counter++;
		}
		dst[counter] = '\0';
	}
	return (ft_strlen(src));
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (start >= ft_strlen(s))
	{
		str = (char *)malloc(1);
		*str = '\0';
		return (str);
	}
	str = NULL;
	s += start;
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	str = malloc(len + 1);
	if (!(str))
		return (NULL);
	ft_strlcpy(str, s, len + 1);
	return (str);
}

char	*ft_strjoin(char *str1, char *str2)
{
	int		i;
	int		j;
	char	*n_str;

	i = -1;
	j = -1;
	if (!str1)
	{
		str1 = malloc(1);
		str1[0] = '\0';
	}
	n_str = malloc(ft_strlen(str1) + 2);
	if (!n_str)
		return (NULL);
	while (str1[++i])
		n_str[i] = str1[i];
	n_str[i] = str2[0];
	n_str[i + 1] = '\0';
	free(str1);
	return (n_str);
}

size_t	ft_strlen(const char *s)
{
	size_t	counter;

	counter = 0;
	if (!s)
		return (0);
	while (s[counter])
		counter++;
	return (counter);
}

char	*ft_strdup(const char *s1)
{
	char	*str;

	str = malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, ft_strlen(s1) + 1);
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 07:26:41 by bena              #+#    #+#             */
/*   Updated: 2022/05/29 20:30:31 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
// {
// 	size_t	counter;

// 	counter = 0;
// 	if (dstsize > 0)
// 	{
// 		while (src[counter] && counter < dstsize - 1)
// 		{
// 			dst[counter] = src[counter];
// 			counter++;
// 		}
// 		dst[counter] = '\0';
// 	}
// 	return (ft_strlen(src));
// }

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
	n_str = malloc(ft_strlen(str1) + ft_strlen(str2) + 1);
	if (!n_str)
		return (NULL);
	while (str1[++i])
		n_str[i] = str1[i];
	while (str2[++j])
		n_str[i + j] = str2[j];
	n_str[j + i] = '\0';
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
	int		i;

	i = -1;
	str = malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (++i < (int)ft_strlen(s1) + 1)
		str[i] = s1[i];
	str[i] = '\0';
	return (str);
}

void	ft_free_node(t_fd **head, t_fd *node)
{
	t_fd	*tmp_head;
	t_fd	*aux;

	(void)aux;
	tmp_head = *head;
	if (tmp_head == node)
	{
		free(node->str);
		free(node);
		(*head) = (*head)->next;
	}
	else
	{
		while (tmp_head != node)
		{
			aux = tmp_head;
			tmp_head = tmp_head->next;
		}
		aux->next = tmp_head->next;
		if (node->str)
			free(node->str);
		free(node);
	}
}

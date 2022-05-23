/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 03:21:49 by bena              #+#    #+#             */
/*   Updated: 2022/05/20 17:28:58y becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static	t_fd	*ft_get_node(int fd, t_fd *node)
{
	if (!node)
	{
		node = malloc(sizeof(t_fd));
		node->fd = fd;
	}
	return (node);
}

static	void	get_str(int fd, t_fd *node)
{
	int		rd;
	char	*buffer;
	char	*aux;

	rd = 1;
	buffer = malloc(sizeof(char *));
	node->str = malloc(1);
	node->str[0] = 0;
	while (rd != 0)
	{
		rd = read(fd, buffer, 1);
		if (rd == 0)
			break ;
		buffer[1] = 0;
		aux = ft_strjoin(node->str, buffer);
		node->str = ft_strdup(aux);
		free(aux);
		if (node->str[ft_strlen(node->str) - 1] == '\n')
			break ;
	}
	free(buffer);
}

char	*get_next_line(int fd)
{
	static t_fd	*node;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	node = ft_get_node(fd, node);
	get_str(fd, node);
	if (node->str[0] == 0)
		return (NULL);
	return (node->str);
}

int	main(void)
{
	int		fd;
	char	*str;

	fd = open("tests/alternate_line_nl_with_nl", O_RDONLY);
	for (size_t i = 0; i < 10; i++)
	{
		str = get_next_line(fd);
		printf ("Return%lu : |%s|\n", i, str);
		free(str);
	}
	close(fd);
}

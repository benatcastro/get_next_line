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

#include "get_next_line.h"

static	t_fd	*ft_get_node(int fd, t_fd *node)
{
	if (!node)
	{
		node = malloc(sizeof(t_fd));
		node->fd = fd;
	}
	return (node);
}

static	int	get_str(int fd, t_fd *node, int rd)
{
	char	*buffer;
	char	*aux;

	buffer = malloc(sizeof(char *));
	node->str = malloc(1);
	node->str[0] = 0;
	while (rd > 0)
	{
		rd = read(fd, buffer, 1);
		if (rd <= 0 && node->str[0] == 0)
		{
			free(buffer);
			return (1);
		}
		else if (rd == 0)
			break ;
		buffer[1] = 0;
		aux = ft_strjoin(node->str, buffer);
		node->str = ft_strdup(aux);
		free(aux);
		if (node->str[ft_strlen(node->str) - 1] == '\n' )
			break ;
	}
	free(buffer);
	return (0);
}

char	*get_next_line(int fd)
{
	static t_fd	*node;
	int			eof;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	node = ft_get_node(fd, node);
	eof = get_str(fd, node, 1);
	if (eof == 1)
	{
		free(node->str);
		free(node);
		node = NULL;
		return (NULL);
	}
	if (node->str[0] == 0 || node->eof == 1)
		return (NULL);
	return (node->str);
}

int	main(void)
{
	int		fd;
	char	*str;

	fd = open("tests/big_line_no_nl", O_RDONLY);
	printf("FD: (%d)\n", fd);
	for (size_t i = 0; i < 15; i++)
	{
		str = get_next_line(fd);
		printf ("Return%lu : |%s|\n", i, str);
		free(str);
	}
	close(fd);
}

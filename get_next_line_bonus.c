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

static	t_fd	*ft_create_node(int fd)
{
	t_fd	*node;

	printf("NODE BEING CREATED (%d)\n", fd);
	node = malloc(sizeof(t_fd));
	node->fd = fd;
	node->next = NULL;
	return (node);
}

static	t_fd	*ft_get_node(int fd, t_fd **node)
{
	if (!node)
	{
		*node = ft_create_node(fd);
		node = *node;
	}
	while (!(*node)->next)
	{
		printf("WHILE FD(%d)\n", (*node)->fd);
		if ((*node)->fd == fd)
			return ((*node));
		else
			(*node)->next = ft_create_node(fd);
	}
	return ((*node));
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
	*node = ft_get_node(fd, node);
	eof = get_str(fd, *node, 1);
	if (eof == 1)
	{
		free((*node)->str);
		free((*node));
		node = NULL;
		return (NULL);
	}
	if ((*node)->str[0] == 0 || (*node)->eof == 1)
		return (NULL);
	return ((*node)->str);
}

int	main(void)
{
	int		fd;
	int		fd2;
	int		fd3;
	char	*str;

	fd = open("tests/test1.txt", O_RDONLY);
	fd2 = open("tests/test2.txt", O_RDONLY);
	fd3 = open("tests/test3.txt", O_RDONLY);
	printf("FD1: (%d)\n", fd);
	printf("FD2: (%d)\n", fd2);
	printf("FD3: (%d)\n", fd3);
	for (size_t i = 0; i < 5; i++)
	{
		str = get_next_line(fd);
		printf ("Return : |%s|\n", str);
		free(str);
		str = get_next_line(fd2);
		printf ("Return : |%s|\n", str);
		free(str);
		str = get_next_line(fd3);
		printf ("Return : |%s|\n", str);
		free(str);
	}
	close(fd);
	close(fd2);
	close(fd3);
}

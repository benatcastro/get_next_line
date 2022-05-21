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



// static	t_fd	ft_get_node(int fd)
// {
// 	static t_fd	data[MAX_FD];
// 	int			i;

// 	i = 0;
// 	if (data[i].fd == 0 && fd != 0)
// 	{
// 		data[i].fd = fd;
// 	}
// 	else
// 	{
// 		data[i].fd = fd;
// 	}
// 	return (data[i]);
// }

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
		buffer[1] = 0;
		if (rd == 0)
			break ;
		aux = ft_strjoin(node->str, buffer);
		free(node->str);
		node->str = ft_strdup(aux);
		printf("aux %s", aux);
		free(aux);
	}
	free(buffer);
}

char	*get_next_line(int fd)
{
	static t_fd	*node;

	node = malloc(sizeof(t_fd));
	get_str(fd, node);
	return (node->str);
}

int	main(void)
{
	int		fd;
	char	*str;

	fd = open("tests/test1.txt", O_RDONLY);
	for (size_t i = 0; i < 10; i++)
	{
		str = get_next_line(fd);
		printf ("Return%lu : |%s|\n", i, str);
		free(str);
	}
	close(fd);
}

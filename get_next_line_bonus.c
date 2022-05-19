/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 03:21:49 by bena              #+#    #+#             */
/*   Updated: 2022/05/19 09:17:27 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static	t_fd	*ft_get_node(int fd)
{
	static t_fd	data[MAX_FD];
	int			i;

	i = 0;
	if (data[i].fd == 0 && fd != 0)
	{
		data[i].fd = fd;
	}
	else
	{
		data[i].fd = fd;
	}

}

static	char	*get_str(int fd)
{
	int		rd;
	int		counter;
	char	*buffer;
	char	*str;
	char	*aux;

	rd = 1;
	counter = 0;
	buffer = malloc(1);
	str = malloc(1);
	while (rd != 0)
	{
		counter++;
		rd = read(fd, buffer, 1);
		if (rd == 0)
			break ;
		printf("(%s)", buffer);
		str = ft_strjoin(str, buffer);
	}
	printf("counter (%d)\n", counter);
	free(buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	static t_fd	data;
	char		*test;

	printf("getStr (%s)\n", get_str(fd));
	return ("test");
}

int	main(void)
{
	int fd;

	fd = open("tests/test1.txt", O_RDONLY);
	printf ("Return : (%s)", get_next_line(fd));
	close(fd);
}

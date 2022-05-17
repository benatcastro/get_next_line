/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 03:21:49 by bena              #+#    #+#             */
/*   Updated: 2022/05/17 07:33:57 by bena             ###   ########.fr       */
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

char	*get_next_line(int fd)
{
	char		*buffer;
	int			rd;
	int			counter;
	char		*str;
	static t_fd	data;

	counter = 0;
	while (rd != 0 || counter == 0)
	{
		buffer = calloc(1, 1);
		rd = read(fd, buffer, 1);
		str = ft_strjoin(str, buffer);
		//printf("(%s)", buffer);
		if (buffer[0] == '\n')
			return (ft_substr(str, 0, data.index));
		free(buffer);
		data.index++;
	}

	//ft_get_node(fd);
}

int	main(void)
{
	int fd;

	fd = open("tests/test1.txt", O_RDONLY);
	printf ("Return : (%s)", get_next_line(fd));
}

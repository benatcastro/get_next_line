/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 03:21:49 by bena              #+#    #+#             */
/*   Updated: 2022/05/17 06:41:28 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static	t_fd	*ft_get_node(int fd)
{
	static t_fd	data[MAX_FD][sizeof(t_fd)];
	int			i;

	i = 0;
	data[0]->fd = 10;
	printf("data %d", data[0]->fd);
}

char	*get_next_line(int fd)
{

	ft_get_node(fd);
}

int	main(void)
{
	get_next_line(10);
	get_next_line(12);
	get_next_line(12);
}

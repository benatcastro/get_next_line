/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 03:21:49 by bena              #+#    #+#             */
/*   Updated: 2022/05/15 03:36:32 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	char	*buffer;
	t_fds	*data;

	buffer = malloc(100);
	data = malloc(sizeof(t_fds));
	data->fd = fd;
	read(data->fd, buffer, 100);
	printf("Buffer(%s)\n", buffer);
}

int	main(void)
{
	int fd = open("tests/")
}

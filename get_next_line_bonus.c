/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 03:21:49 by bena              #+#    #+#             */
/*   Updated: 2022/05/20 07:28:30 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strdup(const char *s1)
{
	char	*str;

	str = malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, ft_strlen(s1) + 1);
	return (str);
}

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
	str = malloc(0);
	while (rd != 0)
	{
		counter++;
		rd = read(fd, buffer, 1);
		if (rd == 0)
			break ;
		aux = ft_strjoin(str, buffer);
		free(str);
		str = ft_strdup(aux);
		free(aux);

	}
	free(buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	static t_fd	data;
	int			j;
	char		*s;

	if (!data.str)
		data.str = ft_strdup(get_str(fd));
	j = data.index;
	while (data.str[data.index])
	{
		if (data.str[data.index] == '\n')
		{
			data.index++;
			return (ft_substr(data.str, j, data.index));
		}
		data.index++;
	}
	return(NULL);
}

int	main(void)
{
	int fd;

	fd = open("tests/test1.txt", O_RDONLY);
	//get_next_line(fd);
	//get_next_line(fd);
	printf ("Return : %s\n", get_next_line(fd));

	// printf ("Return : %s\n", get_next_line(fd));
	// printf ("Return : %s\n", get_next_line(fd));
	// printf ("Return : %s\n", get_next_line(fd));
	// printf ("Return : %s\n", get_next_line(fd));
	close(fd);
}

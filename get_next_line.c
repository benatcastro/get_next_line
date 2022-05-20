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

char	*ft_strdup(const char *s1)
{
	char	*str;

	str = malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, ft_strlen(s1) + 1);
	return (str);
}

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

static	char	*get_str(int fd)
{
	int		rd;
	int		i;
	char	*buffer;
	char	*str;
	char	*aux;

	BUFFER_SIZE = 1;
	rd = 1;
	buffer = malloc(sizeof(char *));
	str = malloc(0);
	str[0] = 0;
	while (rd != 0)
	{
		rd = read(fd, buffer, i);
		buffer[1] = 0;
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

static	int	ft_add_i(char *str)
{
	if (str[0] == '\n')
		return (0);
	return (-1);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*aux;
	char		*aux2;
	int			i;

	aux = NULL;
	if (!str)
		str = get_str(fd);
	i = ft_add_i(str);
	while (str[++i])
	{
		if (str[i] == '\n' || str[i + 1] == '\n')
		{
			aux = ft_substr(str, 0, i);
			if (str[i + 1] == '\n')
				aux = ft_substr(str, 0, i + 1);
			aux2 = ft_strdup(str);
			free(str);
			str = ft_substr(aux2, i + 1, ft_strlen(aux2) - ft_strlen(aux));
			free(aux2);
			break ;
		}
		i++;
	}
	return (aux);
}

// int	main(void)
// {
// 	int fd;
// 	char	*str;


// 	fd = open("tests/test1.txt", O_RDONLY);
// 	str = get_next_line(fd);
// 	printf ("Return1 : %s\n", str);
// 	free(str);
// 	str = get_next_line(fd);
// 	printf ("Return2 : %s\n", str);
// 	free(str);str = get_next_line(fd);
// 	printf ("Return3 : %s\n", str);
// 	free(str);str = get_next_line(fd);
// 	printf ("Return4 : %s\n", str);
// 	free(str);	str = get_next_line(fd);
// 	printf ("Return5 : %s\n", str);
// 	free(str);

// 	// printf ("Return : %s\n", get_next_line(fd));
// 	// printf ("Return : %s\n", get_next_line(fd));
// 	// printf ("Return : %s\n", get_next_line(fd));
// 	// printf ("Return : %s\n", get_next_line(fd));
// 	close(fd);
// }

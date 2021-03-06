/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 03:18:38 by bena              #+#    #+#             */
/*   Updated: 2022/05/30 08:48:17 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define MAX_FD 4096

typedef struct t_fd
{
	int				fd;
	char			*str;
	struct t_fd		*next;

}	t_fd;

char	*get_next_line(int fd);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char *str1, char *str2);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
#endif // MACRO

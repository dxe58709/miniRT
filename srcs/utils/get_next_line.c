/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 20:13:06 by nsakanou          #+#    #+#             */
/*   Updated: 2024/07/11 16:48:15 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <stdio.h>

char	*ft_free(char *str)
{
	free(str);
	return (NULL);
}

char	*join_line(int fd, char *line)
{
	char	*buf;
	int		readbyte;
	char	*tmpline;

	buf = malloc((BUFFER_SIZE + 1) * (sizeof(char)));
	if (!buf && line)
		return (ft_free(line));
	readbyte = 1;
	while (readbyte > 0)
	{
		readbyte = read(fd, buf, BUFFER_SIZE);
	printf("[rb:%d]",readbyte);
		if (readbyte == -1)
			ft_free(buf);
		buf[readbyte] = '\0';
		tmpline = line;
		line = ft_strjoin_gnl(line, buf);
		free (tmpline);
		if (!line)
			return (ft_free(buf));
		if (ft_strchr(line, '\n'))
			break ;
	}
	free (buf);
	return (line);
}

char	*get_line(char *memo)
{
	size_t	i;
	char	*line;

	i = 0;
	if (!memo[i])
		return (NULL);
	while (memo[i] && memo[i] != '\n')
		i++;
	line = (char *)malloc((i + 2) * (sizeof(char)));
	if (!line)
		return (NULL);
	ft_strlcpy(line, memo, (i + 2));
	return (line);
}

char	*save_tmp(char *memo)
{
	char	*tmp;
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(memo);
	while (memo[i] && memo[i] != '\n')
		i++;
	if (!memo[i])
	{
		free(memo);
		return (NULL);
	}
	tmp = (char *)malloc((len - i) * (sizeof(char)));
	if (!tmp)
		return (ft_free(memo));
	ft_strlcpy(tmp, memo + i + 1, (len - i));
	free(memo);
	return (tmp);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	save = join_line(fd, save);
	if (!save)
		return (ft_free(save));
	line = get_line(save);
	save = save_tmp(save);
	return (line);
}

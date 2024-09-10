/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 20:13:06 by nsakanou          #+#    #+#             */
/*   Updated: 2024/09/10 18:23:00 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "libft.h"
#include <stdio.h>

static char	*gnl_strchr(const char *s, int c)
{
	const char	cc = (const char)c;

	if (s == NULL)
		return (NULL);
	while (*s != cc)
	{
		if (*s == '\0')
			return (NULL);
		s++;
	}
	return ((char *)s);
}

static char	*gnl_strjoin(char *target, char *str)
{
	size_t	tlen;
	size_t	slen;
	char	*ret;

	tlen = 0;
	if (target != NULL)
		tlen = ft_strlen(target);
	slen = 0;
	if (str != NULL)
		slen = ft_strlen(str);
	ret = NULL;
	if (tlen + slen != 0)
	{
		ret = malloc(tlen + slen + 1);
		if (ret)
		{
			ft_memcpy(ret, target, tlen);
			ft_memcpy(ret + tlen, str, slen);
			ret[tlen + slen] = '\0';
		}
	}
	if (target)
		free(target);
	return (ret);
}

static char	*gnl_nread(int fd, char *cache)
{
	char	*buf;
	ssize_t	len;

	if (BUFFER_SIZE < 0)
		return (NULL);
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	len = 1;
	while (gnl_strchr(cache, '\n') == NULL)
	{
		len = read(fd, buf, BUFFER_SIZE);
		if (len <= 0)
			break ;
		buf[len] = '\0';
		cache = gnl_strjoin(cache, buf);
		if (cache == NULL)
			break ;
	}
	free(buf);
	if (len < 0 && cache != NULL)
		free(cache);
	if (len < 0)
		cache = NULL;
	return (cache);
}

char	*get_next_line(int fd)
{
	static char	*cache;
	char		*ptr;
	char		*tmp;
	char		*ret;

	cache = gnl_nread(fd, cache);
	if (cache == NULL)
		return (NULL);
	ptr = gnl_strchr(cache, '\n');
	if (ptr == NULL)
	{
		ptr = cache;
		cache = NULL;
		return (ptr);
	}
	tmp = gnl_strjoin(NULL, ptr + 1);
	ret = malloc(ptr - cache + 2);
	if (ret == NULL)
		return (NULL);
	ret[ptr - cache + 1] = '\0';
	ft_memcpy(ret, cache, ptr - cache + 1);
	free(cache);
	cache = tmp;
	return (ret);
}

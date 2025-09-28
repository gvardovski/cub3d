/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolkau <gvardovski@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 15:46:49 by svolkau           #+#    #+#             */
/*   Updated: 2025/01/24 14:58:58 by svolkau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_free(char *content)
{
	free(content);
	return (NULL);
}

char	*find_line( int fd, char *buf, char *content)
{
	ssize_t	c_bytes;
	char	*tmp;

	c_bytes = 1;
	while (c_bytes)
	{
		c_bytes = read(fd, buf, BUFFER_SIZE);
		if (c_bytes < 0)
			return (ft_free(content));
		else if (!c_bytes)
			return (content);
		buf[c_bytes] = '\0';
		if (!content)
			content = ft_strdup("");
		tmp = ft_strjoin(content, buf);
		free(content);
		content = tmp;
		if (ft_strchr(content, '\n'))
			return (content);
	}
	return (content);
}

char	*get_line(char *line)
{
	int		i;
	char	*tmp;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	tmp = ft_substr(line, i + 1, ft_strlen(line) - i - 1);
	if (line[i] == '\n')
		line[i + 1] = '\0';
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*content;
	char		*buf;
	char		*line;
	char		*tmp;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	content = find_line(fd, buf, content);
	free(buf);
	if (!content || *content == '\0')
		return (ft_free(content));
	line = ft_strdup(content);
	tmp = get_line(line);
	free(content);
	content = tmp;
	return (line);
}

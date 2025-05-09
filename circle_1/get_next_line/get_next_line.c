/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhong <juhong@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 16:50:24 by juhong            #+#    #+#             */
/*   Updated: 2025/05/09 20:40:10 by juhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*extract_line(char *remainder)
{
	size_t	i;
	char	*line;

	i = 0;
	if (!remainder || !remainder[0])
		return (NULL);
	while (remainder[i] && remainder[i] != '\n')
		i++;
	if (remainder[i] == '\n')
		i++;
	line = ft_substr(remainder, 0, i, 0);
	return (line);
}

static char	*update_remainder(char *remainder)
{
	size_t	i;
	char	*new_remain;

	i = 0;
	while (remainder[i] && remainder[i] != '\n')
		i++;
	if (!remainder[i])
	{
		free(remainder);
		return (NULL);
	}
	i++;
	new_remain = ft_substr(remainder, i, ft_strlen(remainder) - i, 0);
	free(remainder);
	return (new_remain);
}

static char	*finalize_line(char **remainder)
{
	char	*line;

	line = extract_line(*remainder);
	if (!line)
	{
		free(*remainder);
		*remainder = NULL;
		return (NULL);
	}
	*remainder = update_remainder(*remainder);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*remainder;
	char		*buffer;
	ssize_t		bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(remainder, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		buffer[bytes_read] = '\0';
		remainder = ft_strjoin(remainder, buffer, 0, 0);
	}
	free(buffer);
	if (bytes_read < 0)
	{
		free(remainder);
		return (remainder = NULL, NULL);
	}
	return (finalize_line(&remainder));
}

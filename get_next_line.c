/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sael-kha <sael-kha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 12:34:51 by sael-kha          #+#    #+#             */
/*   Updated: 2025/02/23 11:35:55 by sael-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*gbed_text(int fd, char *text)
{
	int		bytes;
	char	*buffer;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes = 1;
	while (bytes)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(text);
			free(buffer);
			return (NULL);
		}
		buffer[bytes] = '\0';
		text = strjoin(text, buffer);
		if ((is_on_str(buffer, '\n')) == 1)
			break ;
	}
	free(buffer);
	return (text);
}

static char	*gbed_line(char *text)
{
	int		i;
	char	*line;

	i = 0;
	if (text[0] == '\0')
		return (NULL);
	while (text[i] && text[i] != '\n')
		i++;
	if (text[i] == '\n')
		i++;
	line = (char *)malloc(i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (text[i] && text[i] != '\n')
	{
		line[i] = text[i];
		i++;
	}
	if (text[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static char	*update_text(char *text)
{
	int		i;
	char	*new_text;
	int		j;

	if (!text)
		return (NULL);
	j = 0;
	i = 0;
	while (text[i] && text[i] != '\n')
		i++;
	if (!text[i])
	{
		free(text);
		return (NULL);
	}
	new_text = (char *)malloc(gnl_strlen(text + i + 1) + 1);
	if (!new_text)
		return (NULL);
	i++;
	while (text[i])
		new_text[j++] = text[i++];
	new_text[j] = '\0';
	free(text);
	return (new_text);
}

char	*get_next_line(int fd)
{
	static char	*text;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
	{
		if (text)
		{
			free(text);
			text = NULL;
		}
		return (NULL);
	}
	text = gbed_text(fd, text);
	if (!text)
		return (NULL);
	line = gbed_line(text);
	if (!line)
	{
		free(text);
		text = NULL;
		return (NULL);
	}
	text = update_text(text);
	return (line);
}

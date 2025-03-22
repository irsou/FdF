/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isousa-s <isousa-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:01:16 by isousa-s          #+#    #+#             */
/*   Updated: 2025/02/02 15:19:53 by isousa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_and_join(int fd, char *storage, char *buffer)
{
	int		bytes_read;

	bytes_read = 1;
	while ((!storage || !ft_strchr(storage, '\n')) && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(storage);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		if (bytes_read > 0)
			storage = ft_strjoin(storage, buffer);
		if (!storage)
		{
			return (NULL);
		}
	}
	return (storage);
}

static char	*read_to_storage(int fd, char *storage)
{
	char	*buffer;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	storage = read_and_join(fd, storage, buffer);
	free(buffer);
	return (storage);
}

static char	*get_line(char *storage)
{
	char	*line;
	int		pos;

	pos = 0;
	if (!storage[pos])
		return (NULL);
	while (storage[pos] && storage[pos] != '\n')
		pos++;
	line = (char *)malloc(sizeof(char) * (pos + 2));
	if (!line)
		return (NULL);
	pos = 0;
	while (storage[pos] && storage[pos] != '\n')
	{
		line[pos] = storage[pos];
		pos++;
	}
	if (storage[pos] == '\n')
	{
		line[pos] = storage[pos];
		pos++;
	}
	line[pos] = '\0';
	return (line);
}

static char	*update_storage(char *storage)
{
	char	*new_sto;
	int		pos_s;
	int		pos_new;

	pos_s = 0;
	while (storage[pos_s] && storage[pos_s] != '\n')
		pos_s++;
	if (!storage[pos_s])
	{
		free(storage);
		return (NULL);
	}
	new_sto = (char *)malloc(sizeof(char) * (ft_strlen(storage) - pos_s + 1));
	if (!new_sto)
	{
		free(storage);
		return (NULL);
	}
	pos_s++;
	pos_new = 0;
	while (storage[pos_s])
		new_sto[pos_new++] = storage[pos_s++];
	new_sto[pos_new] = '\0';
	free(storage);
	return (new_sto);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	storage = read_to_storage(fd, storage);
	if (!storage)
		return (NULL);
	line = get_line(storage);
	storage = update_storage(storage);
	return (line);
}

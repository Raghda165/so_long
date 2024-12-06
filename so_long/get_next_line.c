/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryagoub <ryagoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:56:14 by ryagoub           #+#    #+#             */
/*   Updated: 2024/03/02 17:23:09 by ryagoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*join_line(char *line, char *word)
{
	char	*tmp;

	tmp = line;
	line = ft_strjoin(line, word);
	free(tmp);
	free(word);
	return (line);
}

char	*get_lines(char *line, int fd)
{
	char	*word;
	int		b;

	b = 1;
	if (BUFFER_SIZE <= 0 || BUFFER_SIZE >= 2147483647 || fd < 0)
		return (NULL);
	while (b != 0)
	{
		word = (char *) malloc (sizeof(char) * (BUFFER_SIZE +1));
		if (!word)
			return (free (line), NULL);
		b = read(fd, word, BUFFER_SIZE);
		if (b == -1)
			return (free(word), free(line), NULL);
		if (b == 0)
			return (free(word), line);
		word[b] = '\0';
		line = join_line(line, word);
		if (!line)
			return (NULL);
		if (ft_strchr(line, '\n'))
			break ;
	}
	return (line);
}

size_t	line_length(char *line)
{
	size_t	i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line [i] == '\n')
		return (i + 1);
	return (i);
}

int	exclude_line(char *s_line, char *line)
{
	int	i;

	i = 0;
	while (s_line[i] != '\n' && s_line[i])
	{
		line[i] = s_line[i];
		i++;
	}
	if (s_line[i] == '\n')
		line[i++] = '\n';
	line [i] = '\0';
	return (i);
}

char	*get_next_line(int fd)
{
	static char	*s_line;
	char		*line;
	int			i;
	char		*tmp;

	i = 0;
	s_line = get_lines(s_line, fd);
	if (!s_line)
		return (NULL);
	if (s_line[0] == '\0')
	{
		free(s_line);
		return (s_line = NULL, NULL);
	}
	line = (char *) malloc (sizeof(char) * (line_length(s_line) + 1));
	if (!line)
	{
		free(s_line);
		return (s_line = NULL, NULL);
	}
	i = exclude_line(s_line, line);
	tmp = s_line;
	s_line = ft_strdup(tmp + i);
	return (free(tmp), line);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knieves- <knieves-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 21:27:51 by knieves-          #+#    #+#             */
/*   Updated: 2025/02/03 13:42:52 by knieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_free(char **str)
{
	if (*str)
	{
		free(*str);
		*str = NULL;
	}
	return (NULL);
}

char	*clean_stash(char *stash)
{
	char	*new_stash;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (stash[i] != '\n' && stash[i])
		i++;
	if (stash[i] == '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	new_stash = (char *)malloc((ft_strlen(stash) - i + 1) * sizeof(char));
	if (!new_stash)
		return (ft_free(&stash));
	while (stash[i] != '\0')
		new_stash[j++] = stash[i++];
	new_stash[j] = '\0';
	free(stash);
	return (new_stash);
}

char	*extract_line(char *stash)
{
	char	*line;
	int		i;

	i = 0;
	if (!stash || !stash[0])
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	line = (char *)malloc((i + 1) * sizeof(char));
	if (!line)
		return (NULL);
	ft_strlcpy(line, stash, i + 1);
	return (line);
}

char	*read_and_store(int fd, char *stash)
{
	char	*buffer;
	ssize_t	bytes_read;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (ft_free(&stash));
	bytes_read = 1;
	while (bytes_read > 0 && !ft_strchr(stash, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		buffer[bytes_read] = '\0';
		stash = ft_strjoin(stash, buffer);
		if (!stash)
			break ;
	}
	free(buffer);
	if (bytes_read < 0)
		return (ft_free(&stash));
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash[MAX_FD];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if ((stash[fd] && !ft_strchr(stash[fd], '\n')) || !stash[fd])
		stash[fd] = read_and_store(fd, stash[fd]);
	if (!stash[fd])
		return (NULL);
	line = extract_line(stash[fd]);
	if (!line)
		return (ft_free(&stash[fd]));
	stash[fd] = clean_stash(stash[fd]);
	return (line);
}
/*
void	ft_putendl_fd(char *s, int fd)
{
	if (*s && fd > -1)
	{
		write(fd, s, ft_strlen(s));
	}
	return ;
}

int	main(void)
{
	int	fd1 = open("text.txt", O_RDONLY);
	int	fd2 = open("text2.txt", O_RDONLY);
	int	fd3 = open("text3.txt", O_RDONLY);
	char	*line;

	if (fd1 < 0 || fd2 < 0 || fd3 < 0)
		return (1);
	while ((line = get_next_line(fd1)) != NULL)
	{
		ft_putendl_fd(line, 1);
		free(line);
	}
	while ((line = get_next_line(fd2)) != NULL)
	{
		ft_putendl_fd(line, 1);
		free(line);
	}
	while ((line = get_next_line(fd3)) != NULL)
	{
		ft_putendl_fd(line, 1);
		free(line);
	}
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}*/

#include "get_next_line.h"

/*char *clean_stash(char *stash) // Limpia el contenido restante del stash para futuras llamadas.
{
    char *new_stash;
    int i;
    int j;

    i = 0;
    j = 0;
    while (stash[i] != '\n' && stash[i] != '\0')
        i++;
    if (stash[i] == '\0')
    {
        free(stash);
        return (NULL);
    }
    new_stash = (char *)malloc((ft_strlen(stash) - i) * sizeof(char));
    if(!new_stash)
    {
        free(stash);
        return (NULL);
    }
    i++;
    while (stash[i] != '\0')
        new_stash[j++] = stash[i++];
    new_stash[j] = '\0';
    free(stash);
    return (new_stash);
}

char *extract_line(char *stash) // Extrae la línea completa del stash.
{
    char *line;
    int i;

    i = 0;
    if (!stash)
        return (NULL);
    while (stash[i] != '\n' && stash[i] != '\0')
        i++;
    if (stash[i] == '\n')
        i++;
    line = (char *)malloc((i + 1) * sizeof(char));
    if(!line)
        return (NULL);
    ft_strlcpy(line, stash, i + 1);
    return (line);
}

char *get_next_line(int fd) // Función principal que controla la lógica de lectura.
{
    static char *stash;
    char    *buffer;
    ssize_t bytes_read;
    char *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (!buffer)
        return (NULL);
    bytes_read = read(fd, buffer, BUFFER_SIZE);
    while (bytes_read > 0)
    {
        buffer[bytes_read] = '\0';
        stash = ft_strjoin(stash, buffer);
        if (ft_strchr(stash, '\n'))
            break;
        bytes_read = read(fd, buffer, BUFFER_SIZE);
    }
    free(buffer);
    if (bytes_read < 0 || (!stash && bytes_read == 0))
        return (NULL);
    line = extract_line(stash);
    stash = clean_stash(stash);
    return (line);
}

void	ft_putendl_fd(char *s, int fd)
{
	if (*s && fd > -1)
	{
		write(fd, s, ft_strlen(s));
	}
	return ;
}

int main(int argc, char *argv[])
{
    int fd;
    char *line;
    
    if (argc < 2)
        return (1);
    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
	{
		perror("Error opening file");
		return (1);
	}
    while ((line = get_next_line(fd)) != NULL)
    {
        ft_putendl_fd(line, 1);
        free(line);
    }
    close(fd);
    return (0);
}*/

char	*ft_free(char **str)
{
    if (*str)
    {
        free(*str);
	    *str = NULL;
    }
	return (NULL);
}

char *clean_stash(char *stash)
{
    char *new_stash;
    int i;
    int j;

    i = 0;
    j = 0;
    while (stash[i] && stash[i] != '\n')
        i++;
    if (!stash[i])
        return (ft_free(&stash));
    new_stash = (char *)malloc((ft_strlen(stash) - i + 1) * sizeof(char));
    if(!new_stash)
        return (ft_free(&stash));
    i++;
    while (stash[i] != '\0')
        new_stash[j++] = stash[i++];
    new_stash[j] = '\0';
    free(stash);
    return (new_stash);
}

char *extract_line(char *stash)
{
    char *line;
    int i;

    i = 0;
    if (!stash || !stash[0])
        return (NULL);
    while (stash[i] && stash[i] != '\n')
        i++;
    if (stash[i] == '\n')
        i++;
    line = (char *)malloc((i + 1) * sizeof(char));
    if(!line)
        return (NULL);
    ft_strlcpy(line, stash, i + 1);
    return (line);
}

char *read_and_store(int fd, char *stash)
{
    char    *buffer;
    ssize_t bytes_read;

    buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (!buffer)
        return (ft_free(&stash));
    while (!ft_strchr(stash, '\n'))
    {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read <= 0)
            break;
        buffer[bytes_read] = '\0';
        stash = ft_strjoin(stash, buffer);
        if (!stash)
            return (ft_free(&buffer));
    }
    free(buffer);
    if (bytes_read < 0)
        return (ft_free(&stash));
    return (stash);
}

char *get_next_line(int fd)
{
    static char *stash;
    char *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    stash = read_and_store(fd, stash);
    if (!stash)
        return (NULL);
    line = extract_line(stash);
    if (!line)
        return (ft_free(&stash));
    stash = clean_stash(stash);
    return (line);
}

void	ft_putendl_fd(char *s, int fd)
{
	if (*s && fd > -1)
	{
		write(fd, s, ft_strlen(s));
	}
	return ;
}

int main(int argc, char *argv[])
{
    int fd;
    char *line;
    
    if (argc < 2)
        return (1);
    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
	{
		perror("Error opening file");
		return (1);
	}
    while ((line = get_next_line(fd)) != NULL)
    {
        ft_putendl_fd(line, 1);
        free(line);
    }
    close(fd);
    return (0);
}
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *str, int c);
size_t	ft_strlcpy(char *dest, const char *src, size_t n);
char	*ft_strjoin(char *s1, char *s2);
char *get_next_line(int fd);
char *extract_line(char *stash);
char *clean_stash(char *stash);

#endif
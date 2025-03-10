/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knieves- <knieves-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 13:15:55 by knieves-          #+#    #+#             */
/*   Updated: 2025/02/03 13:15:31 by knieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef MAX_BUFFER
#  define MAX_BUFFER 1024
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# elif BUFFER_SIZE > MAX_BUFFER
#  undef BUFFER_SIZE
#  define BUFFER_SIZE MAX_BUFFER
# endif

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *str, int c);
size_t	ft_strlcpy(char *dest, const char *src, size_t n);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);
char	*extract_line(char *stash);
char	*clean_stash(char *stash);

#endif

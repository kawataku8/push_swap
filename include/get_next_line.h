#ifndef FT_GNL
#define	FT_GNL

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <stdio.h>
#include "../libft/libft.h"

size_t	ft_strlen(const char *s);
int make_line(int fd, char **save, char **line);
int check_ret(int fd, char **save, int ret,char **line);
int get_next_line(int fd, char **line);

#endif

#ifndef GNL
# define GNL

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
# elif BUFFER_SIZE <= 0
# undef BUFFER_SIZE
# define BUFFER_SIZE 10
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

char	*get_next_line(int fd);

#endif
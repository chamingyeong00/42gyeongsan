#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main()
{
/*
    int fd = open("test.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("open");
        return 1;
    }
    */
    int fd = 0;


    char *line;
    while ((line = get_next_line(fd)))
    {
        printf("%s", line);
        free(line);
    }

    close(fd);
    return 0;
}

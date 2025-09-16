#include "brokenGNL.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

char	*ft_strchr(char *s, char c)
{
    if (!s || !*s)
        return NULL;
	int	i = 0;
	while (s[i])
    {
        if (s[i] == c)
		    return s + i;
        i++;
    }
    return NULL;
}

size_t	ft_strlen(char *s)
{
    if (!s)
        return 0;
    size_t ret = 0;
	while (s[ret])
		ret++;
	return ret;
}

void    *ft_memcpy(void *dest, const void *src, size_t n)
{
	while (n-- > 0)
		((char*)dest)[n] = ((char*)src)[n];
	return dest;
}

int	str_append_mem(char **s1, char *s2, size_t size2)
{
    size_t size1;
    if (!s1)
        size1 = 0;
	else
        size1 = ft_strlen(*s1);
	char *tmp = malloc((size2 + size1 + 1)*sizeof(char *));
	if (!tmp)
		return 0;
    if (*s1)
	    ft_memcpy(tmp, *s1, size1);
	ft_memcpy(tmp + size1, s2, size2);
	tmp [size1 + size2] = '\0';
	free(*s1);
	*s1 = tmp;
	return 1;
}

int	str_append_str(char **s1, char *s2)
{
	return str_append_mem(s1, s2, ft_strlen(s2));
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (dest > src)
		return ft_memcpy(dest, src, n);
	else if (dest == src)
		return dest;
	size_t	i = 0;
	while (i < n)
	{
		((char*)dest)[i] = ((char*)src)[i];
		i++;
	}
	return dest;
}

char    *get_next_line(int fd)
{
    static char b[BUFFER_SIZE + 1] = "";
    char    *tmp = NULL;
    int read_ret = 0;

    if (*b)
        str_append_str(&tmp, b);
    while (!ft_strchr(b, '\n'))
    {
        read_ret = read(fd, b, BUFFER_SIZE);
        if (read_ret <= 0)
        {
            b[0] = '\0';
            return NULL;
        }
        b[read_ret] = '\0';
        if (!str_append_str(&tmp, b))
            return NULL;
	}
    char *new = ft_strchr(tmp, '\n');
	if ((*new) && (*new + 1))
		ft_memmove(b, new +1 , ft_strlen(new + 1) + 1);
    else
        return NULL;
    tmp[new-tmp+1] = '\0';
	return tmp;
}

int main(void)
{
    int fd = open("test.txt", O_RDONLY);
    char *string;
    if (fd == -1)
        printf("error\n");
    while ((string = get_next_line(fd)))
        printf("%s", string);
}
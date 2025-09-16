#include "brokenGNL.h"

char	*ft_strchr(char *s, char c)
{
	int	i = 0;
	if (!s)
		return 0;
	while (s[i])
	{
		if (s[i] == c)
			return s + i;
		i++;
	}
	if (c == '\0')
		return s + i;
	return NULL;
}

size_t	ft_strlen(char *s)
{
	if (!s)
		return 0;
	size_t ret = 0;
	while (*s)
	{
		s++;
		ret++;
	}
	return ret;
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	while (n-- > 0)
		((char*)dest)[n] = ((char*)src)[n];
	return dest;
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (dest > src)
		return ft_memcpy(dest, src, n);
	else if (dest == src)
		return dest;
	size_t i = 0;
	while (i < n)
	{
		((char*)dest)[i] = ((char*)src)[i];
		i++;
	}
	return dest;
}


int	str_append_mem(char **s1, char *s2, size_t size2)
{
	if (!s2)
		return 0;
	size_t size1 = ft_strlen(*s1);
	char *tmp = malloc(size2 + size1 + 1);
	if (!tmp)
		return 0;
	if (*s1)
		ft_memcpy(tmp, *s1, size1);
	ft_memcpy(tmp + size1, s2, size2);
	tmp [size1 + size2] = '\0';
	if (*s1)
		free(*s1);
	*s1 = tmp;
	return 1;
}

int	str_append_str(char **s1, char *s2)
{
	return str_append_mem(s1, s2, ft_strlen(s2));
}

 char    *get_next_line(int fd)
{
	static char b[BUFFER_SIZE + 1] = "";
	char    *ret = NULL;
	char		*new;
	int			read_ret;
	
	if (*b)
		str_append_str(&ret, b);
	while (!ft_strchr(ret, '\n'))
	{
		read_ret = read(fd, b, BUFFER_SIZE);
		if (read_ret <= 0)
		{
			b[0] = '\0';
			return ret;
		}
		b[read_ret] = '\0';
		if (!str_append_str(&ret, b)) //
		{
			free(ret); //
			return (NULL); //
		}
	}
	new = ft_strchr(ret, '\n');
	if (new && *(new + 1))
		ft_memmove(b, new + 1, ft_strlen(new + 1) + 1);
	else
		b[0] = '\0';
	*(new + 1) = '\0';
	return ret;
}

int main()
{
	int fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("error");
		return 1;
	}

	char *line;
	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return 0;
}


#include <unistd.h>

int ft_str_len(char *str)
{
    int i;
    int len;

    i = 0;
    len = 0;
    while (str[i] != '\0')
    {
        len++;
        i++;
    }
    return (len);
}

char *ft_rev_print (char *str)
{
    int len;

    len = ft_str_len(str);
    len--;
    while (len >= 0)
    {
        write(1, &str[len], 1);
        len--;
    }
    return (str);
}

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        ft_rev_print(argv[1]);
    }
    write(1, "\n", 1);
}
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

int double_check(char *str, char c, int len)
{
    int i;

    i = 0;
    while (i < len)
    {
        if (c == str[i])
        {
            return (1);
        }
        i++;
    }
    return (0);
}

void ft_union(char *s1, char *s2)
{
    int i;
    int s1_len;
    int s2_len;

    i = 0;
    s1_len = ft_str_len(s1);
    s2_len = ft_str_len(s2);
    while (s1[i] != '\0')
    {
        if (!double_check(s1, s1[i], i))
        {
            write(1, &s1[i], 1);
        }
        i++;
    }
    i = 0;
    while (s2[i] != '\0')
    {
        if (!double_check(s1, s2[i], s1_len))
        {
            if (!double_check(s2, s2[i], i))
                write(1, &s2[i], 1);
        }
        i++;
    }
}

int main(int argc, char **argv)
{
    if (argc == 3){
        ft_union(argv[1], argv[2]);
    }
    write(1, "\n" , 1);
}
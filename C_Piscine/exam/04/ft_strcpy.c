#include <unistd.h>

char    *ft_strcpy(char *s1, char *s2)
{
    int i;
    int len;

    i = 0;
    len = 0;
    while (s2[i] != '\0')
    {
        len++;
        i++;
    }
    i = 0;
    while (len > i)
    {
        s1[i] = s2[i];
        i++;
    } 
    s1[i] = '\0';
    return (s1);
}

int main(void)
{
    char a[3] = "abc";
    char b[3];
    ft_strcpy(b, a);
    write(1, &b, 4);
}
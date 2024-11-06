#include <unistd.h>

int is_sep(char c)
{
    if (c == ' ' || (c >= 9 && c <= 13))
        return (1);
    return (0);
}

int count_world(char *str)
{
    int i;
    int cnt;

    i = 0;
    cnt = 0;
    while (str[i] != '\0')
    {
        if (!is_sep(str[i]))
        {
            cnt++;
            while (!is_sep(str[i]) != '\0' && str[i] != '\0')
        }
    }
}
char **ft_split(char *str)
{
    int i;
    int **d;

    d = (int **)malloc()
    i = 0;
    while (str[i] != '0')
    {

    }
}

int main(void)
{
    char d;

    d = "abc, def, fb";
    ft_split(d);
}
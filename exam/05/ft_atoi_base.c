int check_base(char c, int str_base)
{
    int i;
    char a[16] = "0123456789abcdef";

    i = 0;
    while (i < str_base)
    {
        if (c == a[i])
        {
            return (1);
        }
        i++;
    }
    return (0);
}

int ft_value(char c)
{
    if (c >= '0' && c <= '9')
        return (c - '0');
    if (c >= 'a' && c <= 'f')
        return (c - ('a' + 10));
    if (c >= 'A' && c <= 'F')
        return (c - ('A' + 10));
    return (0);
}

int ft_atoi_base(const char *str, int str_base)
{
    int i;
    int sign;   
    int value;

    i = 0;
    sign = 1;
    value = 0;
    while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
        i++;
    if (str[i] == '-')
        sign = -1;
    while ((str[i] == '-') || (str[i] == '+'))
        i++;
    while (check_base(str[i], str_base))
    {
        value = value * str_base + ft_value(str[i]);
        i++;
    }
    return (value * sign);
}

#include <stdio.h>

int main(void)
{
    int a;
    a = ft_atoi_base("123", 10);
    printf("%d", a);
}


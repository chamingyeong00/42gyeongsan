#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int *ft_range(int start, int end)
{
    int i;
    int *d;
    int range;
    
    if (end > start)
        range = end - start;
    else
        range = start - end;
    range++;
    i = 0;
    d = (int *)malloc(sizeof(int) * range);
    if (!d)
        return (0);
    if (end > start)
    {
        while (i < range)
        {
            d[i] = start;
            start++;
            i++;
        }
    }
    else
    {
        while (i < range)
        {
            d[i] = end;
            end--;
            i++;
        }
    }
    return (d);
}

int main(void)
{
    int *d;
    int i;

    i = 0;
    d = (int *)malloc(sizeof(int) * 3);
    d = ft_range(1, 3);
    while (i < 3)
    {
        printf("%d", d[i]);
        i++;
    }
}
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void ft_printf(int *subset, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d", subset[i]);
        if (n - 1 == i)
        {
            printf("\n");
            return;
        }
        printf(" ");
    }
}

int check(int *subset, int num, int sum)
{
    int tmp = 0;
    for (int i = 0; i < num; i++)
    {
        tmp += subset[i];
    }
    if (tmp == sum)
        return 1;
    return 0;
}

void solve(int *string, int *subset, int index1, int index2, int num, int sum, int *printed)
{
    if (index1 == num || index2 == num)
    {
        if (check(subset, index1, sum))
        {
            ft_printf(subset, index1);
            *printed = 1;
        }
        return;
    }
    subset[index1] = string[index2];
    solve(string, subset, index1 + 1, index2 + 1, num, sum, printed);
    solve(string, subset, index1, index2 + 1, num, sum, printed);
}

int main(int ac, char **av)
{
    if (ac < 2) //
        return 0; 
    int sum = atoi(av[1]);
    int num = ac - 2;
    int printed = 0;
    int *subset = malloc(sizeof(int *) * num);
    int *string = malloc(sizeof(int *) * num);
    for (int i = 0; i < num; i++)
    {
        string[i] = atoi(av[i + 2]);
    }
    solve(string, subset, 0, 0, num, sum, &printed);
    free(subset);
    free(string);

}
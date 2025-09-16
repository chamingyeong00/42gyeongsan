#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int check_sum(int *subset, int pos, int sum)
{
    int n = 0;
    int number = 0;
    for (n = 0; n < pos; n++)
        number += subset[n];

    if (sum == number)
        return 1;

    return 0;
}

void ft_printf(int *string, int n)
{
    for (int i = 0; i < n; i++)
    {
        fprintf(stdout, "%d ", string[i]);
    }
    fprintf(stdout, "\n");
}

void solve(int *string, int *subset, int sum, int pos, int pos1, int len)
{
    if (pos == len || pos1 == len)
    {
        if (check_sum(subset, pos, sum))
            ft_printf(subset, pos);
        return;
    }
    subset[pos] = string[pos1];
    solve(string, subset, sum, pos+1, pos1+1, len);
    solve(string, subset, sum, pos, pos1+1, len);

}

int main(int argc, char **argv)
{
    int sum = atoi(argv[1]);
    int *string = malloc(sizeof(int *) * (argc - 2));
    int *subset = malloc(sizeof(int *) * (argc - 2));

    for (int i = 0; i < argc - 2; i++)
        string[i] = atoi(argv[i+2]);
    
    solve(string, subset, sum, 0, 0, argc - 2);
}
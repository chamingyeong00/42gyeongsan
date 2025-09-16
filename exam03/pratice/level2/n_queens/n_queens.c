#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void ft_printf(int *string, int n)
{
    for (int i = 0; i < n; i++)
    {
        fprintf(stdout, "%d ", string[i]);
    }
    fprintf(stdout, "\n");
}


int check(int *string, int col, int row)
{
    for (int i = 0; i < col; i++)
    {
        if (string[i] == row || string[i] - row == i - col || string[i] - row == col - i)
            return 1;
    }
    return 0;

}

void solve(int *string, int col, int n)
{
    if (col == n)
    {
        ft_printf(string, n);
        return ;
    }
    for (int i = 0; i < n; i++)
    {
        if (!check(string, col, i))
        {
            string[col] = i;
            solve(string, col + 1, n);
        }
    }
}

int main(int argc, char **argv) {
    if (argc != 2)
        return 0;
    
    int queen = atoi(argv[1]);

    int string[queen];

    solve(string, 0, queen);
}
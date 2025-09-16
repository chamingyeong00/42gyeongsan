#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int ft_strlen(char *argv)
{
    int n = 0;

    while (argv[n])
        n++;
    return n;
}

void solve(char *argv, char *string, char *used, int pos, int len)
{
    if (len == pos)
    {
        puts(string);
        return;
    }
    for (int i = 0; i < len; i++)
    {
        if (!used[i])
        {
            used[i] = 1;
            string[pos] = argv[i];
            solve(argv, string, used, pos + 1, len);
            used[i] = 0;
        }
    }
}

int main(int argc, char **argv)
{
    if (argc != 2)
        return 0;
    int len = ft_strlen(argv[1]);
    char *string = malloc(sizeof(char *) * len);
    char *used = malloc(sizeof(char *) * len);

    
    solve(argv[1], string, used, 0, len);

}
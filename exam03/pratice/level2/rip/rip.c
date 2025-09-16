#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int check_parameter(char *string, int len)
{
    int start = 0;
    int end = 0;

    for (int i = 0; i < len; i++)
    {
        if (string[i] == '(')
            start++;
        else if (string[i] == ')')
        {
            if (start > 0)
                start--;
            else
                end++;
        }
    }
    return start + end;
}

void solve(char *string, int must_fix, int fix, int pos, int len)
{
    if (must_fix == fix)
    {
        if (check_parameter(string, len) == 0)
            puts(string);
        return ;
    }
    for (int i = 0; i < len; i++)
    {
        char c = string[i];
        string[i] = ' ';
        solve(string, must_fix, fix + 1, pos, len);
        string[i] = c;
    }
}

int ft_strlen(char *string)
{
    int i = 0;
    while (string[i] != '\0')
        i++;
    return i;
}

int main(int argc, char **argv)
{
    if (argc != 2)
        return 0;
    int len = ft_strlen(argv[1]);
    int must_fix = check_parameter(argv[1], len);
    // printf("%d", must_fix);
    solve(argv[1], must_fix, 0, 0, len);
}

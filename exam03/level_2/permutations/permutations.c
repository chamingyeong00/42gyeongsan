#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int ft_strlen(char *s)
{
    int len = 0;
    while (s[len])
        len++;
    return len;
}

void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

void sort(char *s, int start, int end)
{
    for (int i = start; i < end; i++)
    {
        for (int j = i+1; j <= end; j++)
        {
            if (s[i] > s[j])
                swap(&s[i], &s[j]);
        }
    }
}

void permutation(char *arr, int *used, char *result, int depth, int n)
{
    if (depth == n) {
        for (int i = 0; i < n; i++) {
            write(1, &result[i], 1);
        }
        write(1, "\n", 1);
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            used[i] = 1;
            result[depth] = arr[i];
            permutation(arr, used, result, depth + 1, n);
            used[i] = 0;
        }
    }
}

int main(int ac, char **av)
{
    if (ac != 2)
        return 0;

    int n = ft_strlen(av[1]);

    char *arr = av[1];
    int *used = malloc(n * sizeof(int *));
    char *result = malloc(n * sizeof(int *));

    sort(arr, 0, n - 1);

    permutation(arr, used, result, 0, n);

    free(used);
    free(result);

    return 0;
}

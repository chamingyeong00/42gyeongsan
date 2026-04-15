#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    float x;
    float y;
} C_city;

C_city city[11];
int used[11];
int perm[11];
int n = 0;
float min_distance = -1.0;

float cal(int a, int b)
{
    return sqrt((city[a].x - city[b].x) * (city[a].x - city[b].x) + (city[a].y - city[b].y) * (city[a].y - city[b].y));
    // sqsrt(()() + ()())
}

void check_min()
{
    int i = 0;
    float num = 0.0;
    for (i = 0; i < n - 1; i++)
        num += cal(perm[i], perm[i + 1]);
    num += cal(perm[i], perm[0]); // perm[0]
    if (min_distance < 0 || min_distance > num)
        min_distance = num;
}

void solve(int level)
{
    if (level == n)
    {
        check_min();
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (used[i] != 1)
        {
            used[i] = 1;
            perm[level] = i;
            solve(level + 1);
            used[i] = 0;
        }
    }
}

int main(void)
{
    n = 0;
    while (scanf("%f, %f", &city[n].x, &city[n].y) == 2)
        n++;

    solve(0);
    printf("%.2f", min_distance);
}
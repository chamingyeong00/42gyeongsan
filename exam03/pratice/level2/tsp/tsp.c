#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct c_city {
    float x;
    float y;
} t_city;

int n = 0;
int used[11] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int perm[11] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
float min_path = -1;
t_city city[11];

float cal_path(int a, int b)
{
    float num = 0;
    num = (city[a].x - city[b].x)*(city[a].x - city[b].x) + (city[a].y - city[b].y)*(city[a].y - city[b].y);

    return sqrtf(num);
}

void check_path()
{
    float number = 0;
    int j;
    for (j = 0; j < n - 1; j++)
        number += cal_path(perm[j], perm[j+1]);
    number += cal_path(perm[j], perm[0]);

    if (min_path > number || min_path < 0)
        min_path = number;

}

void bracktrack(int level)
{
    if (n == level)
    {
        check_path();
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (!used[i])
        {
            used[i] = 1;
            perm[level] = i;
            bracktrack(level +1);
            used[i] = 0;
        }
    }

}

int main(void) {

    while(scanf("%f, %f", &city[n].x, &city[n].y) == 2)
        n++;

    bracktrack(0);

    printf("%.2f", min_path);
}
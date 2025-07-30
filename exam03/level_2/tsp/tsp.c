#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_N 11

typedef struct {
    float x;
    float y;
} City;

City cities[MAX_N];
int perm[MAX_N];
int used[MAX_N];
int n;
float min_length = -1;

// 두 점 사이 거리
float distance(City a, City b) {
    return sqrtf((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

// 현재 순열에 따라 경로 길이 계산
void compute_path() {
    float length = 0.0;
    for (int i = 0; i < n - 1; i++)
        length += distance(cities[perm[i]], cities[perm[i+1]]);
    length += distance(cities[perm[n-1]], cities[perm[0]]); // 다시 출발지로

    if (min_length < 0 || length < min_length)
        min_length = length;
}

// 순열 생성
void backtrack(int level) {
    if (level == n) {
        compute_path();
        return;
    }
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            used[i] = 1;
            perm[level] = i;
            backtrack(level + 1);
            used[i] = 0;
        }
    }
}

int main() {
    // 표준 입력에서 읽기
    n = 0;
    while (scanf("%f, %f", &cities[n].x, &cities[n].y) == 2)
        n++;

    backtrack(0);

    printf("%.2f\n", min_length);
    return 0;
}

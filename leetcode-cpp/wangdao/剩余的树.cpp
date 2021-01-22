#include <stdio.h>
#include <string.h>
int road[10001];

int main() {
    int N, M;
    while (scanf("%d%d", &N, &M) != EOF) {
        memset(road, 1, sizeof(road));
        for (int i = 0; i < M; i++) {
            int left, right;
            scanf("%d%d", &left, &right);
            for (int j = left; j<=right; j++)
                road[j] = 0;
        }
        int cnt = 0;
        for (int i = 0; i <= N; i++) {
            if (road[i] == 0) continue;
            cnt++;
        }
        printf("%d\n", cnt);
    }
    return 0;
}

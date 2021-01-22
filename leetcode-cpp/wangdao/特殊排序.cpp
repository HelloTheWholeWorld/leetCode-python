#include <stdio.h>
#include <algorithm>
using namespace std;
int nums[1000];
int main() {
    int N;
    while (scanf("%d", &N) != EOF) {
        for (int i = 0; i < N; i++) {
            scanf("%d", &nums[i]);
        }
        sort(nums, nums+N);
        printf("%d\n", nums[N - 1]);
        if (N == 1) printf("-1\n");
        else {
            for (int i = 0; i < N - 1; i++) {
                printf("%d", nums[i]);
                if (i < N - 2) printf(" ");
            }
            printf("\n");
        }
    }
    return 0;
}

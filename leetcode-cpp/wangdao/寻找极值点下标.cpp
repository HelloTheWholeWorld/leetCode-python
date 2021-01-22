#include <stdio.h>
#include <string.h>
int nums[80];
int result[80];

int main() {
    int m;
    while (scanf("%d", &m) != EOF) {
        memset(result, 0, sizeof(result));
        for (int i = 0; i < m; i++) {
            scanf("%d", &nums[i]);
        }
        if (nums[0] != nums[1]) {
            result[0] = 1;
        }
        if (nums[m-1] != nums[m-2]){
            result[m-1] = 1;
        }
        for (int i = 1; i <= m-2; i++) {
            //printf("%d %d %d", nums[i-1],nums[i],nums[i+1]);
            if (nums[i] > nums[i-1] && nums[i] > nums[i+1]) {
                result[i] = 1;
            }
            else if (nums[i] < nums[i-1] && nums[i] < nums[i+1]) {
                result[i] = 1;
            }
        }
        for (int i = 0; i < m; i++) {
            if (result[i]) {
                if (i==m-1) printf("%d", m-1);
                else {
                    printf("%d ", i);
                }
            }
        }
        printf("\n");
    }
    return 0;
}

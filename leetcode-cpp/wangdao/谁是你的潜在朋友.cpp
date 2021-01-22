#include <stdio.h>

int people[201] = {0};
int books[201] = {0};

int main() {
    int N, M;
    scanf("%d%d", &N, &M);
    int temp;
    for (int i = 1; i <= N; i++) {
        scanf("%d", &temp);
        people[i] = temp;
        books[temp]++;
    }
    for (int i = 1; i <= N; i++) {
        if (books[people[i]] > 1) {
            printf("%d\n", books[people[i]] - 1);
        }
        else {
            printf("BeiJu\n");
        }
    }
    return 0;
}

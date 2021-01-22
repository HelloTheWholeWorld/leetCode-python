#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

struct Item{
    int id;
    char name[8];
    int score;
};

bool comp1(Item e1, Item e2) {
    return e1.id < e2.id;
};

bool comp2(Item e1, Item e2) {
    int ret = strcmp(e1.name, e2.name);
    return ret <= 0;
};

bool comp3(Item e1, Item e2) {
    if (e1.score < e2.score) {
        return true;
    }
    else if (e1.score == e2.score || strcmp(e1.name, e2.name) == 0) {
        return e1.id < e2.id;
    }
    return false;
};

Item items[100000];
int main() {
    int N;
    int type;
    scanf("%d%d", &N, &type);
    if (N == 0) {
        printf("Case:\n");
        return 0;
    } else {
        for (int i = 0; i < N; i++) {
            scanf("%d%s%d", &(items[i].id), items[i].name, &(items[i].score));
        }
    }
    switch (type) {
        case 1:
            sort(items, items + N, comp1);
            break;
        case 2:
            sort(items, items + N, comp2);
            break;
        case 3:
            sort(items, items + N, comp3);
            break;
        default:
            break;
    }
    printf("Case:\n");
    for (int i = 0; i < N; i++) {
        printf("%06d %s %d\n", items[i].id, items[i].name, items[i].score);
    }
    return 0;
}

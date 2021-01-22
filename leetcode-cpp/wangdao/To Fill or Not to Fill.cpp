#include <stdio.h>
#include <algorithm>

using namespace std;
struct Station {
    double per_price;
    int distance;
    bool operator <(const Station &b) const{
        return distance < b.distance;
    };
}stations[501];

int main() {
    int Cmax, D, Davg, N;
    while (scanf("%d%d%d%d", &Cmax, &D, &Davg, &N) != EOF) {
        double min_price = 0;
        int now = 0, min_get;
        double left = 0;
        for (int i = 0; i < N; i++) {
            scanf("%lf%d", &stations[i].per_price, &stations[i].distance);
        }
        sort(stations, stations + N);

        stations[N].distance = D;
        stations[N].per_price = 0;
        if (stations[0].distance != 0) {
            printf("The maximum travel distance = 0.00\n");
            break;
        }

        while (now < N) {
            min_get = now;
            if (stations[now].distance + Cmax * Davg < stations[now+1].distance) {
                printf("The maximum travel distance = %.2f", double(stations[now].distance+Cmax*Davg));
                break;
            }
            for (int i = now+1; i<=N; i++) {
                if (stations[now].distance+Cmax*Davg < stations[i].distance) break;
                if (stations[i].per_price <= stations[now].per_price) {
                    min_get = i;
                    break;
                }
            }
            if (min_get==now) {
                min_get = now + 1;
                for (int i = now+2; i<=N; i++) {
                    if (stations[now].distance+Cmax*Davg < stations[i].distance) break;
                    if (stations[i].per_price <= stations[min_get].per_price) {
                        min_get = i;
                        break;
                    }
                }
                min_price += (Cmax-left)*stations[now].per_price;
                left = Cmax - double((stations[min_get].distance - stations[now].distance))/Davg;
                now = min_get;
            }
            else {
                left = double((stations[min_get].distance - stations[now].distance))/Davg - left;
                min_price += left * stations[now].per_price;
                left = 0;
                now = min_get;
            }
        }
        if (now == N) {
            printf("%.2f\n", min_price);
        }
    }
    return 0;
}

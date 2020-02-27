#include <iostream>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) return x;
        long long left = 1, right = x;
        while(1){
            if (right == left + 1 && left * left < x && right * right > x)
                return (int)left;
            long long mid = (left + right) / 2;
            long long temp = mid * mid;
            if (temp == x) return mid;
            else if (temp < x) left = mid;
            else right = mid;
        }
    }
};

int main(){
    Solution a;
    for (int x = 0; x <= 30; x++)
        cout << x << " " << a.mySqrt(x) << endl;
    return 0;
}

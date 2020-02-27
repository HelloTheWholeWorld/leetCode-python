#include <iostream>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 3) return n;
        int a = 2, b = 3, c;
        int i = 3;
        while (i != n){
            i++;
            c = b;
            b += a;
            a = c;
        }
        return b;
    }
};

int main(){
    Solution a;
    for (int x = 0; x <= 10; x++)
        cout << x << " " << a.climbStairs(x) << endl;
    return 0;
}

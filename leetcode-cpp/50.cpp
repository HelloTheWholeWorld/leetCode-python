#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    unordered_map<int, double> hashmap;
    double myPow(double x, int n) {
        if (n == 0) return 1;
        int flag = false;
        if (n < 0) {
            x = 1 / x;
            if (n == INT_MIN) {
                flag = true;
                n += 1;
            }
            n *= -1;
        }
        this->hashmap[1] = x;
        if (!flag){
            return this->binary_search(x, n);
        } else {
            return this->binary_search(x, n) * x;
        }
    }

    double binary_search(double x, int n){
        if (this->hashmap.find(n) != this->hashmap.end()) {
            return hashmap[n];
        } else {
            double left = binary_search(x, n / 2);
            double right = binary_search(x, n - (n / 2));
            hashmap[n] = left * right;
            return left * right;
        }
    }
};

int main(){
    Solution s;
    cout << s.myPow(2 ,-2) << endl;
}

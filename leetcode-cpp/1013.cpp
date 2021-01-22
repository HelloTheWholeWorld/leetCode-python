#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        auto sum = 0;
        for (auto a : A) sum += a;
        if (sum % 3 != 0) return false;
        int l = 0, r = A.size() - 1, cut =  sum / 3;
        int l_sum = A[0], r_sum = A[r];
        while (l_sum != cut && l < r)
            l_sum += A[++l];
        while (r_sum != cut && l < r)
            r_sum += A[--r];
        if (l + 1 < r) return true;
        return false;
    }
};

int main(){
    Solution s;
    vector<int> temp({1, -1, 1, -1});
    cout << s.canThreePartsEqualSum(temp) <<endl;
}

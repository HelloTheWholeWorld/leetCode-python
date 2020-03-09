#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        // 逆序遍历填充
        int a_i = m - 1, b_i = n - 1;
        for (int i = m + n - 1; i >= 0; i--) {
            if (a_i >= 0 && b_i >= 0) {
                if (A[a_i] > B[b_i])
                    A[i] = A[a_i--];
                else
                    A[i] = B[b_i--];
            } else if (a_i < 0)
                A[i] = B[b_i--];
            else if (b_i < 0)
                A[i] = A[a_i--];
        }
        return ;
    }
};

int main(){
    Solution s;
    vector<int> A({1,2,3,0,0,0});
    vector<int> B({2,5,6});
    s.merge(A, 3, B, 3);
    for (auto i : A){
        cout <<i <<endl;
    }
//    int target = -11;
//    vector<vector<int>> ret = s.fourSum(nums, target);
//    for (int i = 0; i < ret.size(); i++){
//        for (int j = 0; j < ret[i].size(); j++){
//            cout << ret[i][j] << "\t";
//        }
//        cout <<endl;
//    }
    return 0;
}

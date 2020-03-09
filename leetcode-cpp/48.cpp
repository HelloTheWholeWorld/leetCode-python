#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix.size() == 1) return;
        // transpose
        int s = matrix.size();
        for (int i = 0; i < s; i++){
            for (int j = i + 1; j < s; j++){
                matrix[i][j] = matrix[i][j] ^ matrix[j][i];
                matrix[j][i] = matrix[i][j] ^ matrix[j][i];
                matrix[i][j] = matrix[i][j] ^ matrix[j][i];
            }
        }
        // reverse
        for (int i = 0; i < s; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

int main(){
    Solution s;
    vector<vector<int>> ret = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9},
    };
    s.rotate(ret);
    for (int i = 0; i < ret.size(); i++){
        for (int j = 0; j < ret[i].size(); j++){
            cout << ret[i][j] << "\t";
        }
        cout <<endl;
    }
}

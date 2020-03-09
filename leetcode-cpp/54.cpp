#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m == 0) return vector<int>();
        int n = matrix[0].size();
        int minus_inter = 0, dir = 0;
        int i = 0, j = -1;
        vector<int> ret;
        int decay_base[4] = {0, 1, 1, 2};
        while (true) {
            if (dir == 0) {
                int temp = n - decay_base[dir] - minus_inter;
                if (temp == 0) return ret;
                for (int t = 0; t < temp; t++){
                    j++;
                    ret.push_back(matrix[i][j]);
                }
                dir = 1;
            } else if (dir == 1) {
                int temp = m - decay_base[dir] - minus_inter;
                if (temp == 0) return ret;
                for (int t = 0; t < temp; t++){
                    i++;
                    ret.push_back(matrix[i][j]);
                }
                dir = 2;
            } else if (dir == 2) {
                int temp = n - decay_base[dir] - minus_inter;
                if (temp == 0) return ret;
                for (int t = 0; t < temp; t++){
                    j--;
                    ret.push_back(matrix[i][j]);
                }
                dir = 3;
            } else {
                int temp = m - decay_base[dir] - minus_inter;
                if (temp == 0) return ret;
                for (int t = 0; t < temp; t++){
                    i--;
                    ret.push_back(matrix[i][j]);
                }
                dir = 0;
                minus_inter += 2;
            }
        }
    }
};

int main(){
    Solution s;
    vector<vector<int>> matrix({{1,2,3},{4,5,6},{7,8,9}});
    vector<int> ret = s.spiralOrder(matrix);
    for (auto i : ret){
        cout <<i <<endl;
    }
}

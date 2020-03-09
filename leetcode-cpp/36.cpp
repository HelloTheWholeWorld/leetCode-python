#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int check[9];
        // 列检查
        for(int j = 0; j < board[0].size(); j++) {
            memset(check, 0, sizeof(check));
            for (int i = 0; i < board.size(); i++){
                char temp = board[i][j];
                if (temp != '.'){
                    if (check[temp - '1'] == 0)
                        check[temp - '1'] = 1;
                    else
                        return false;
                }
            }
        }
        // 行检查
        for(int i = 0; i < board.size(); i++) {
            memset(check, 0, sizeof(check));
            for (int j = 0; j < board[0].size(); j++){
                char temp = board[i][j];
                if (temp != '.'){
                    if (check[temp - '1'] == 0)
                        check[temp - '1'] = 1;
                    else
                        return false;
                }
            }
        }
        // 块检查
        for (int i = 0; i < board.size(); i+=3) {
            for (int j = 0; j < board[0].size(); j+=3){
                memset(check, 0, sizeof(check));
                for (int m = i; m < i + 3; m++){
                    for (int k = j; k < j + 3; k++) {
                        char temp = board[m][k];
                        if (temp != '.'){
                            if (check[temp - '1'] == 0)
                                check[temp - '1'] = 1;
                            else
                                return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};


int main(){
    Solution s;
    vector<vector<char>> nums({
                      {'5','3','.','.','7','.','.','.','.'},
                      {'6','.','.','1','9','5','.','.','.'},
                      {'.','9','8','.','.','.','.','6','.'},
                      {'8','.','.','.','6','.','.','.','3'},
                      {'4','.','.','8','.','3','.','.','1'},
                      {'7','.','.','.','2','.','.','.','6'},
                      {'.','6','.','.','.','.','2','8','.'},
                      {'.','.','.','4','1','9','.','.','5'},
                      {'.','.','.','.','8','.','.','7','9'},
                     });
    cout << s.isValidSudoku(nums) <<endl;
}

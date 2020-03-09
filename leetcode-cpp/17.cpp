#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <stack>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return vector<string>();
        unordered_map<char, vector<char>> hashmap;
        hashmap.insert({'2', vector<char>({'a', 'b', 'c'})});
        hashmap.insert({'3', vector<char>({'d', 'e', 'f'})});
        hashmap.insert({'4', vector<char>({'g', 'h', 'i'})});
        hashmap.insert({'5', vector<char>({'j', 'k', 'l'})});
        hashmap.insert({'6', vector<char>({'m', 'n', 'o'})});
        hashmap.insert({'7', vector<char>({'p', 'q', 'r', 's'})});
        hashmap.insert({'8', vector<char>({'t', 'u', 'v'})});
        hashmap.insert({'9', vector<char>({'w', 'x', 'y', 'z'})});

        vector<string> ret;
        this->recall(digits, "", 0, ret, hashmap);
        return ret;
    }

    void recall(string digits, string stk, int idx, vector<string> &ret, unordered_map<char, vector<char>> &hashmap){
        if (idx == digits.size())
            ret.push_back(stk);
        else {
            vector<char> temp = hashmap[digits[idx]];
            for (int i = 0; i < temp.size(); i++){
                this->recall(digits, stk + temp[i], idx+1 , ret, hashmap);
            }
        }
    }

};

int main(){
    Solution s;
    string a = "23";
    vector<string> ret = s.letterCombinations(a);
    for (auto i : ret){
        cout << i << "  ";
    }
    return 0;
}

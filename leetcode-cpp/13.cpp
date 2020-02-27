#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        if (!s.size()) return 0;
        unordered_map<string, int> hashmap;
        hashmap.insert({"I",1});
        hashmap.insert({"II",2});
        hashmap.insert({"III",3});
        hashmap.insert({"IV",4});
        hashmap.insert({"V",5});
        hashmap.insert({"IX",9});
        hashmap.insert({"X",10});
        hashmap.insert({"XL",40});
        hashmap.insert({"L",50});
        hashmap.insert({"XC",90});
        hashmap.insert({"C",100});
        hashmap.insert({"CD",400});
        hashmap.insert({"D",500});
        hashmap.insert({"CM",900});
        hashmap.insert({"M",1000});
        int max_len = 3, idx = 0, ret = 0, temp;
        while (idx != s.size()){
            if (idx + max_len <= s.size())
                temp = max_len;
            else
                temp = s.size() - idx;
            while (hashmap.find(s.substr(idx, temp)) == hashmap.end()) {
                temp -= 1;
            }
            ret += hashmap[s.substr(idx, temp)];
            idx += temp;
        }
        return ret;
    }
};

int main(){
    string s = "MCMXCIV";
    Solution a;
    int ret = a.romanToInt(s);
    cout << ret <<endl;
    return 0;
}

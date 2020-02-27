#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size() == 0) return 0;
        if (haystack.size() == 0) return -1;
        if (needle.size() > haystack.size()) return -1;
        int len_needle = needle.size();
        for (int i = 0; i <= haystack.size() - needle.size(); i++)
            if (!haystack.compare(i, len_needle, needle, 0, len_needle))
                return i;
        return -1;
    }
};

int main(){
    Solution a;
    string haystack = "hello", neddle = "lo";
    cout << a.strStr(haystack, neddle) << endl;
    return 0;
}

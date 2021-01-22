#include <stdio.h>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

//char chs[200];
int main() {
    string s;
    while (cin >> s) {
        sort(s.begin(), s.end());
        cout << s << endl;
    }
    return 0;
}

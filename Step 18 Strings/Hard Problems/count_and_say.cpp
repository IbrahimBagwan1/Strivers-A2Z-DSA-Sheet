#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        string str = countAndSay(n - 1);
        string ztr = "";
        int frequency = 1;
        char ch = str[0];
        for (int i = 1; i < static_cast<int>(str.length()); i++) {
            char dh = str[i];
            if (ch == dh) {
                frequency++;
            } else {
                ztr += to_string(frequency) + ch;
                frequency = 1;
                ch = dh;
            }
        }
        ztr += to_string(frequency) + ch;
        return ztr;
    }
};

int main() {
    Solution sol;
    int inputs[] = {1, 2, 3, 4, 5, 6, 7, 8};
    for (int n : inputs) {
        cout << "countAndSay(" << n << ") = " << sol.countAndSay(n) << '\n';
    }
    return 0;
}

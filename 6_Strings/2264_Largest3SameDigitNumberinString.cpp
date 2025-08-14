#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string largestGoodInteger(string num) {
        if (num.size() < 3) {
            return "";
        }

        char maxDigit = 0; 
        for (int i = 0; i < num.size() - 2; i++) {
            if (num[i] == num[i+1] && num[i+1] == num[i+2]) {
                if (num[i] > maxDigit) {
                    maxDigit = num[i];
                }
            }
        }

        if (maxDigit == 0) return "";
        return string(3, maxDigit);
    }
};

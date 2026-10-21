
class Solution {
public:
    int myAtoi(string s) {
        int j = 0;
        string result = "";
        bool digitTillNowFound = false;

        while (j < s.length() && s[j] == ' ') {
            j++;
        }

        if (j < s.length() && (s[j] == '-' || s[j] == '+')) {
            result += s[j];
            j++;
        }

        while (j < s.length() && isdigit(s[j])) {
            digitTillNowFound = true;
            result += s[j];
            j++;
        }

        if (!digitTillNowFound) {
            return 0;
        }

        int sign = 1;
        int i = 0;

        if (result[0] == '-') {
            sign = -1;
            i = 1;
        } 
        else if (result[0] == '+') {
            i = 1;
        }

        long long num = 0;

        while (i < result.length()) {
            int digit = result[i] - '0';
            num = num * 10 + digit;

            if (sign * num < INT_MIN) {
                return INT_MIN;
            }

            if (sign * num > INT_MAX) {
                return INT_MAX;
            }

            i++;
        }

        return sign * num;
    }
};

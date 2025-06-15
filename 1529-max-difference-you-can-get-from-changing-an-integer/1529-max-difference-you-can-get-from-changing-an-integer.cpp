class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);

        // Make largest number by replacing the first non-'9' digit
        char temp = 0;
        for (char ch : s) {
            if (ch != '9') {
                temp = ch;
                break;
            }
        }
        string largest = s;
        if (temp) {
            for (char& ch : largest) {
                if (ch == temp) ch = '9';
            }
        }

        // Make smallest number
        string smallest = s;
        if (s[0] == '1') {
            // Replace the first digit != '1' and != '0' with '0'
            temp = 0;
            for (char ch : s) {
                if (ch != '1' && ch != '0') {
                    temp = ch;
                    break;
                }
            }
            if (temp) {
                for (char& ch : smallest) {
                    if (ch == temp) ch = '0';
                }
            }
        } else {
            // Replace s[0] with '1'
            temp = s[0];
            for (char& ch : smallest) {
                if (ch == temp) ch = '1';
            }
        }

        return stoi(largest) - stoi(smallest);
    }
};

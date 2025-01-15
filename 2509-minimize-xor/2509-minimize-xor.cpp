class Solution {
public:
    int countBits(int num) {
        int count = 0;
        while (num > 0) {
            if ((num & 1) == 1)
                count++;
            num = num >> 1;
        }
        return count;
    }

    int minimizeXor(int num1, int num2) {
        int n1 = countBits(num1);
        int n2 = countBits(num2);
        if (n1 == n2)
            return num1;
        else if (n2 > n1) {
            int shifts = n2 - n1;
            int n = 0;
            while (shifts > 0) {
                if ((num1 & (1 << n)) == 0) {
                    num1 = num1 ^ (1 << n);
                    shifts--;
                }
                n++;
            }
            return num1;
        } else {
            int shifts = n1 - n2;
            for (int i = 0; shifts > 0; ++i) {
                if ((num1 & (1 << i)) != 0) { // If bit `i` is set
                    num1 &= ~(1 << i); // Turn it off
                    shifts--;
                }
            }
            return num1;
        }
    }
};
class Solution {
public:
    const int MOD = 1e9 + 7;

    // STL-based Modular Exponentiation using iterative approach
    long long modPow(long long base, long long exp, long long mod) {
        long long result = 1;
        while (exp > 0) {
            if (exp % 2 == 1) { // If exponent is odd, multiply base with result
                result = (result * base) % mod;
            }
            base = (base * base) % mod; // Square the base
            exp /= 2; // Reduce exponent by half
        }
        return result;
    }

    int countGoodNumbers(long long n) {
        long long even_digits = (n + 1) / 2;
        long long odd_digits = n / 2;

        // Using STL modular exponentiation
        long long res = (modPow(5, even_digits, MOD) * modPow(4, odd_digits, MOD)) % MOD;
        return res;
    }
};
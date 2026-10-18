class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> digits;
        int fact = 1;

        for (int i = 1; i <= n; ++i) {
            digits.push_back(i);
            fact *= i;
        }

        string result;
        --k;

        for (int i = n; i >= 1; --i) {
            fact /= i;
            int idx = k / fact;

            result += to_string(digits[idx]);
            digits.erase(digits.begin() + idx);
            k %= fact;
        }

        return result;
    }
};

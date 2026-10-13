class Solution {
public:
    int rob(vector<int>& nums) {
        int prev = 0;
        int best = 0;

        for (int money : nums) {
            int next = max(best, prev + money);
            prev = best;
            best = next;
        }

        return best;
    }
};
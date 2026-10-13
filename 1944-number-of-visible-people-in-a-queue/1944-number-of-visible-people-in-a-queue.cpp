class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        vector<int> ans(n, 0);
        vector<int> stack;

        for (int i = n - 1; i >= 0; --i) {
            while (!stack.empty() && heights[i] > stack.back()) {
                stack.pop_back();
                ++ans[i];
            }

            if (!stack.empty())
                ++ans[i];

            stack.push_back(heights[i]);
        }

        return ans;
    }
};
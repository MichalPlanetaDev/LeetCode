class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int best = 0;
        stack<int> st;

        for (int i = 0; i <= n; ++i) {
            int h = (i == n) ? 0 : heights[i];

            while (!st.empty() && heights[st.top()] > h) {
                int height = heights[st.top()];
                st.pop();

                int width = st.empty() ? i : i - st.top() - 1;
                best = max(best, height * width);
            }

            if (i < n)
                st.push(i);
        }

        return best;
    }
};
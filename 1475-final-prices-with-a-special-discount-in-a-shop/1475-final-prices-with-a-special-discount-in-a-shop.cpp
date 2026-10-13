class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> ans = prices;
        vector<int> st;

        for (int i = 0; i < prices.size(); ++i) {
            while (!st.empty() && prices[i] <= prices[st.back()]) {
                ans[st.back()] -= prices[i];
                st.pop_back();
            }

            st.push_back(i);
        }

        return ans;
    }
};
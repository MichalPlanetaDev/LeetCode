class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int count[101] = {};

        for (int num : nums)
            ++count[num];

        int smaller = 0;

        for (int& freq : count) {
            int current = freq;
            freq = smaller;
            smaller += current;
        }

        vector<int> ans;
        ans.reserve(nums.size());

        for (int num : nums)
            ans.push_back(count[num]);

        return ans;
    }
};
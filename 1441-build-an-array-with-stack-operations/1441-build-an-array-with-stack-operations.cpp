class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ops;
        int current = 1;

        for (int num : target) {
            while (current < num) {
                ops.push_back("Push");
                ops.push_back("Pop");
                ++current;
            }

            ops.push_back("Push");
            ++current;
        }

        return ops;
    }
};
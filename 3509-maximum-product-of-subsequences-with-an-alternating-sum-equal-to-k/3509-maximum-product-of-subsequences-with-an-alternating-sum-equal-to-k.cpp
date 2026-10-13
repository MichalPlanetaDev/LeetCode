class Solution {
public:
    int maxProduct(vector<int>& nums, int k, int limit) {
        constexpr int offset = 900;
        using Sums = bitset<1801>;

        if (k < -offset || k > offset)
            return -1;

        vector<Sums> odd(limit + 1), even(limit + 1);
        Sums allOdd, allEven;

        for (int num : nums) {
            auto nextOdd = odd;
            auto nextEven = even;

            if (num == 0) {
                nextOdd[0] |= allEven;
                nextOdd[0].set(offset);
                nextEven[0] |= allOdd;
            } else {
                if (num <= limit)
                    nextOdd[num].set(offset + num);

                for (int p = 0; p <= limit / num; ++p) {
                    int product = p * num;

                    nextOdd[product] |= even[p] << num;
                    nextEven[product] |= odd[p] >> num;
                }
            }

            Sums newOdd = allOdd | (allEven << num);
            Sums newEven = allEven | (allOdd >> num);
            newOdd.set(offset + num);

            allOdd = newOdd;
            allEven = newEven;

            odd.swap(nextOdd);
            even.swap(nextEven);
        }

        for (int p = limit; p >= 0; --p) {
            if (odd[p][offset + k] || even[p][offset + k])
                return p;
        }

        return -1;
    }
};
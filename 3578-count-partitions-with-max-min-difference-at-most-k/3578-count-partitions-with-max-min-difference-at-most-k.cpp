class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        const int MOD = 1e9 + 7;
        int n = nums.size();
        vector<long long> dp(n + 1, 0);
        vector<long long> prefix(n + 1, 0);
        dp[0] = 1;
        prefix[0] = 1;
        deque<int> maxQ, minQ;
        int left = 0;
        for (int right = 0; right < n; right++) {
            while (!maxQ.empty() && nums[maxQ.back()] <= nums[right])
                maxQ.pop_back();

            maxQ.push_back(right);
            while (!minQ.empty() && nums[minQ.back()] >= nums[right])
                minQ.pop_back();
            minQ.push_back(right);

            while (!maxQ.empty() && !minQ.empty() &&
                   nums[maxQ.front()] - nums[minQ.front()] > k) {
                if (maxQ.front() == left)
                    maxQ.pop_front();
                if (minQ.front() == left)
                    minQ.pop_front();
                left++;
            }
            long long ways = prefix[right];
            if (left > 0)
                ways = (ways - prefix[left - 1] + MOD) % MOD;
            dp[right + 1] = ways;
            prefix[right + 1] = (prefix[right] + dp[right + 1]) % MOD;
        }
        return (int)dp[n];
    }
};
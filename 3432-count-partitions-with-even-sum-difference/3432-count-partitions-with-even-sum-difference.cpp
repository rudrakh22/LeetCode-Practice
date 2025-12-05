class Solution {
public:
    int countPartitions(vector<int>& nums) {
        long long sum=accumulate(nums.begin(),nums.end(),0LL);
        int ans=0,leftSum=0;
        for(int i=0;i<nums.size()-1;i++) {
            leftSum+=nums[i];
            ans+=(sum-2*leftSum)%2==0;
        }
        return ans;
    }
};
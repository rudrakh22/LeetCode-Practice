class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const long long MOD=1e9+7;
        long long ans=0;
        unordered_map<long long,long long>left;
        unordered_map<long long,long long>right;

        for(int num:nums){
            right[num]++;
        }
        for(int num: nums){
            right[num]--;
            long long target=2*num;
            ans=(ans+(right[target]*left[target])%MOD)%MOD;
            left[num]++;
        }
        return ans% MOD;
    }
};
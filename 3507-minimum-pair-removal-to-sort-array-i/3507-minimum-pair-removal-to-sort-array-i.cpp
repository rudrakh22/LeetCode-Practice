class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int count=0;
        while(nums.size()>1){
            bool isAscending=true;
            int minSum=INT_MAX;
            int target=-1;
            for(int i=1;i<nums.size();i++){
                int sum=nums[i-1]+nums[i];
                if(nums[i]<nums[i-1]) {
                    isAscending=false;
                }
                if(sum<minSum){
                    minSum=sum;
                    target=i-1;
                }
            }
            if(isAscending){
                break;
            }
            count++;
            nums[target]=minSum;
            nums.erase(nums.begin()+target+1);
        }
        return count;
    }
};
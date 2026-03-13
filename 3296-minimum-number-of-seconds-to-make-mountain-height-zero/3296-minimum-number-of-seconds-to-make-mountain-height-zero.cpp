class Solution {
public:
    long long canReduce(long long T,vector<int>& workerTimes){
        long long total=0;
        for(auto t: workerTimes){
            long long val=(2*T)/t;
            long long x=(sqrt(1+4*val)-1)/2;
            total+=x;
        }
        return total;
    }
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long left=0,right=1e18;
        long long ans=-1;
        while(left<=right){
            long long mid=(left+right)/2;
            if(canReduce(mid,workerTimes) >= mountainHeight){
                ans=mid;
                right=mid-1;
            }else{
                left=mid+1;
            }
        }
        return ans;
    }
};
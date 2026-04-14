class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(),robot.end());
        sort(factory.begin(),factory.end());
        vector<int>factoryPositions;
        for(auto & f:factory)
            for(int i=0;i<f[1];i++) factoryPositions.push_back(f[0]);
        int n=robot.size();
        int m=factoryPositions.size();
        vector<vector<long long>>dp(n+1,vector<long long>(m+1,0));

        for(int i=0;i<n;i++){
            dp[i][m]=1e12;
        }
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                long long take=abs(robot[i]-factoryPositions[j])+dp[i+1][j+1];
                long long not_take=dp[i][j+1];
                dp[i][j]=min(take,not_take);
            }
        }
        return dp[0][0];
        }
};
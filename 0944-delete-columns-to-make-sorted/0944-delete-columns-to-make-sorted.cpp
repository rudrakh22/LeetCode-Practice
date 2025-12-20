class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int res=0,rows=strs.size(),cols=strs[0].size();
        for(int col=0;col<cols;col++){
            for(int row=1;row<rows;row++){
                if(strs[row][col] < strs[row-1][col]){
                    res++;
                    break;
                }
            }
        }
        return res;
    }
};
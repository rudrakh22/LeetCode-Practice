class Solution {
public:
    int minOperations(string s) {
        vector<int>op={0,0};
        for(int i=0;i<s.size();i++){
            op[(s[i]^i) &1]++;
        }
        return min(op[0],op[1]);
    }
};
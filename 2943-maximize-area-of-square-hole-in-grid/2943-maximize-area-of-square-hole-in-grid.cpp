class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());
        int hMax=1,hcur=1,vMax=1,vcur=1;
        for(int i=1;i<hBars.size();i++){
            if(hBars[i]==hBars[i-1]+1) hcur++;
            else hcur=1;
            hMax=max(hMax,hcur);
        }
        for(int i=1;i<vBars.size();i++){
            if(vBars[i]==vBars[i-1]+1) vcur++;
            else vcur=1;
            vMax=max(vMax,vcur);
        }
        int side=min(hMax,vMax)+1;
        return side*side;
    }
};
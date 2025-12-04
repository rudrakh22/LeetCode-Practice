class Solution {
public:
    int countCollisions(string directions) {
        int n=directions.size();
        int l=0,r=n-1;
        while(l<n && directions[l]=='L') l++;
        while(r>=0 && directions[r]=='R') r--;
        int collisions=0;
        while(l<=r){
            collisions+=directions[l]!='S';
            l++;
        }
        return collisions;
    }
};
class DSU {
public:
    vector<int> parent, rankv;

    DSU(int n) {
        parent.resize(n);
        rankv.resize(n,0);
        for(int i=0;i<n;i++) parent[i]=i;
    }

    int find(int x){
        if(parent[x]!=x)
            parent[x]=find(parent[x]);
        return parent[x];
    }

    bool unite(int a,int b){
        int pa=find(a), pb=find(b);
        if(pa==pb) return false;

        if(rankv[pa]<rankv[pb]) parent[pa]=pb;
        else if(rankv[pb]<rankv[pa]) parent[pb]=pa;
        else{
            parent[pb]=pa;
            rankv[pa]++;
        }
        return true;
    }
};
class Solution {
public:
    bool isPossible(int n,vector<vector<int>>& edges,int k,int val){
        DSU dsu(n);
        int used=0;
        vector<vector<int>> good;
        vector<vector<int>> upgrade;

        for(auto & e:edges){
            int u=e[0],v=e[1],s=e[2],must=e[3];
            if(must==1){
                if(s<val) return false;
                if(!dsu.unite(u,v)) return false;
                used++;
            }else{
                if(s>=val) good.push_back(e);
                else if(2*s>=val) upgrade.push_back(e);
            }
        }
        for(auto &e:good){
            if(dsu.unite(e[0],e[1])){
                used++;
                if(used==n-1) return true;
            }
        }

        int upgrades=0;
        for(auto &e:upgrade){
            if(upgrades==k) break;

            if(dsu.unite(e[0],e[1])){
                upgrades++;
                used++;
                if(used==n-1) return true;
            }
        }

        return used==n-1;

    }
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        int maxi=0;
        for(auto &edge : edges) maxi=max(maxi,edge[2]);
        int left=0,right=2*maxi,ans=-1;
        while(left<=right){
            int mid=(left+right)/2;
            if(isPossible(n,edges,k,mid)){
                ans=mid;
                left=mid+1;
            }
            else right=mid-1;
        }
        return ans;
    }
};
class DSU{
    
    vector<int>parent;
    vector<int>rank;
    public:
    DSU(int n){
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++) parent[i]=i;
    }
    int find(int x){
        if(parent[x] !=x){
            parent[x]=find(parent[x]);
        }
        return parent[x];
    }
    bool unite(int a,int b){
        int pa=find(a),pb=find(b);
        if(pa==pb) return false;
        if(rank[pa]<rank[pb]) parent[pa]=pb;
        else if(rank[pa] > rank[pb]) parent[pb]=pa;
        else{
            parent[pb]=pa;
            rank[pa]++;
        }
        return true;
    }
};

class Solution {
public:
    bool isPossible(int n,vector<vector<int>>& edges,int k,int val){
        DSU dsu(n);
        int used=0;
        vector<vector<int>>good;
        vector<vector<int>>upgrade;
        for(auto &e:edges){
            int u=e[0],v=e[1],s=e[2],must=e[3];
            if(must==1){
                if(s<val) return false;
                if(!dsu.unite(u,v)) return false;
                used++;
            }else{
                if(s>=val) good.push_back(e);
                else if (2*s >=val) upgrade.push_back(e);
            }
        }
        for(auto &edge:good){
            if(dsu.unite(edge[0],edge[1])) {
                used++;
                if(used==n-1) return true;
            }
        }
        int upgrades=0;
        for(auto &edge:upgrade){
            if(upgrades==k) break;
            if(dsu.unite(edge[0],edge[1])) {
                used++;
                upgrades++;
                if(used==n-1) return true;
            }
        }

        return used==n-1; 
    }
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        int maxi=0;
        for(auto &edge:edges) maxi=max(maxi,edge[2]);
        int left=0,right=2*maxi,ans=-1;
        while(left<=right){
            int mid=(left+right)/2;
            if(isPossible(n,edges,k,mid)){
                ans=mid;
                left=mid+1;
            }else right=mid-1;
        }
        return ans;
    }
};
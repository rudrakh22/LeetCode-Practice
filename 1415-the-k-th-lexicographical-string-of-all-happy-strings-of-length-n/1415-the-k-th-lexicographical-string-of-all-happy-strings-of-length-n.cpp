class Solution {
public:
    void generateHappyStrings(int n,string current,vector<string>& happy){
        if(current.size()==n) {
            happy.push_back(current);
            return;
        };
        for(char i='a';i<='c';i++){
            if(current.size()>0 && current.back() == i) continue;
            generateHappyStrings(n,current+i,happy);
        }
    }
    string getHappyString(int n, int k) {
        string currentString="";
        vector<string>happyStrings;
        generateHappyStrings(n,currentString,happyStrings);
        if(happyStrings.size()<k) return "";
        return happyStrings[k-1];
    }

};
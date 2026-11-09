class Solution {
public:
        const long long mod=1e9+7;
    void solve(int i,unordered_map<int,vector<pair<int,int>>>&adj,vector<int>&result,int n,long long value){

            result[i]=value;
            for(auto p:adj[i]){
                long long newValue=(value*(p.second))%mod;
                    solve(p.first,adj,result,n,newValue);
            }
    }
    vector<int> baseUnitConversions(vector<vector<int>>& conversions) {
     unordered_map<int,vector<pair<int,int>>>adj;
     for(auto con:conversions){
        adj[con[0]].push_back({con[1],con[2]});
     }
      int n=conversions.size()+1;
      vector<int>result(n);
      solve(0,adj,result,n,1);
      return result;
    }
};
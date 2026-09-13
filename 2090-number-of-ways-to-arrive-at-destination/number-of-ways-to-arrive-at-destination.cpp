class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        unordered_map<int,vector<pair<int,int>>>adj;
        const long long MOD = 1000000007;
        for(auto road:roads){
                int u=road[0];
                int v=road[1];
                int time=road[2];
                 adj[u].push_back({v,time});
                adj[v].push_back({u,time});
        }
  vector<long long> result(n, LLONG_MAX);
vector<long long> countPaths(n, 0);
        result[0]=0;
        countPaths[0]=1;

        priority_queue<
    pair<long long,int>,
    vector<pair<long long,int>>,
    greater<pair<long long,int>>
> pq;
        pq.push({0,0});
        while(!pq.empty()){
          pair<long long,int> p = pq.top();
           long long time = p.first;
          int u=p.second;
          pq.pop();
          for(auto nbr:adj[u]){
            int v=nbr.first;
            long long newTime=time+nbr.second;
                if(newTime<result[v]){
                    pq.push({newTime,v});
                    result[v]=newTime;
                    countPaths[v] = countPaths[u];
                }

                else if(newTime==result[v]){
               
                    countPaths[v] =
                        (countPaths[v] + countPaths[u]) % MOD;
                }
          }
          

        }

        return countPaths[n-1];
    }
};
class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        unordered_map<int,vector<int>>mp;
        int i=0;
        
        for(auto v:routes){
            for(int j=0;j<v.size();j++){
                mp[v[j]].push_back(i);
            }
            i++;
        }
        if(target==source){
            return 0;
        }
        if(mp[source]==mp[target]){
            return 1;
        }
        vector<bool>visited(routes.size(),false);
        queue<int>que;
        int minBuses=INT_MAX;
        for(auto bus:mp[source]){
            que.push(bus);
        }
             int noOfbuses=0;
        while(!que.empty()){
            int len=que.size();
             noOfbuses++;
            while(len--){
                 int idx=que.front();
                   que.pop();
           if(visited[idx]){
                continue;
               }
               
                visited[idx]=true;
               for(int i=0;i<routes[idx].size();i++){
                if(routes[idx][i]==target){
                    minBuses=min(minBuses,noOfbuses);
                    break;
                }
                for(auto bus:mp[routes[idx][i]]){
                        if(!visited[bus]){
                            que.push(bus);
                        }
                }
               }
            }
        }

        // int len=que.size();
        // while(len--){
        //      int noOfbuses=1;
        //       int minBuses=INT_MAX;
        //     while(!que.empty()){
        //        if(visited[idx]){
        //         continue;
        //        }
        //         int idx=que.front();
        //         que.pop();
        //         visited[idx]=true;
        //        for(int i=0;i<routes[idx].size();i++){
        //         if(routes[idx][i]==target){
        //             minBuses=min(minBuses,noOfbuses);

        //         }
        //         que.push(routes[idx][i]);
        //        }
        //     }
        
        if(minBuses==INT_MAX){
            return -1;
        }
        return minBuses;
    }
};
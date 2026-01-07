// class Solution {
// public:

//     vector<vector<int>>direc={
//          {1,1},{1,0},{0,1},{0,-1},{-1,0},{-1,-1}, {-1,1}, {1,-1}
//     };
//     int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
//         int n=grid.size();
//         if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
//         queue<pair<int,int>>que;
//         que.push({0,0});
//         int level=1;
      
        
//         while(!que.empty()){
//             int sz=que.size();
           
          
//             while(sz--){
//                 pair<int,int>p=que.front();
//                 int x=p.first;
//                 int y=p.second;
//                 que.pop();
//                  if(x==n-1 && y==n-1){
//                         return level;
//                     }
                
//                 for(auto dir:direc){
//                     int x_=x+dir[0];
//                     int y_=y+dir[1];
//                      if(x_<n && x_>=0 && y_>=0 && y_<n && grid[x_][y_]==0){
//                              grid[x_][y_] = 1;
//                              que.push({x_,y_});    
//                      }
                  
//                 }
//             }
//              level++;
//         }
//         return -1;
//     }
// };

class Solution {
public:
 typedef pair<int, pair<int, int>> P;
    vector<vector<int>>direc={
         {1,1},{1,0},{0,1},{0,-1},{-1,0},{-1,-1}, {-1,1}, {1,-1}
    };
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
 priority_queue<P, vector<P>, greater<P>> pq;      
   pq.push({0,{0,0}});
   vector<vector<int>> result(n, vector<int>(n, INT_MAX));
     
      if(n==1 && grid[0][0]==0){
        return 1;
      }
        
        while(!pq.empty()){
             int d  = pq.top().first;
	    pair<int, int> node = pq.top().second;
	    pq.pop();

            int x = node.first;
            int y = node.second;
          
            for(auto dir:direc) {
		int x_   = x + dir[0];
		int y_   = y + dir[1];
		int dist = 1;

		if(x_<n && x_>=0 && y_>=0 && y_<n && grid[x_][y_] == 0 && d+dist < result[x_][y_]) {
		    pq.push({d+dist, {x_, y_}});
		    grid[x_][y_] = 1;
		    result[x_][y_] = d + dist;
		}
            }
        }
       if(result[n-1][n-1] == INT_MAX)
            return -1;
        
        return result[n-1][n-1]+1;
    }
};
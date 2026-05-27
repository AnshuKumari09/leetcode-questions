class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
      intervals.push_back(newInterval);
      sort(intervals.begin(),intervals.end());
      vector<vector<int>>result;
        int prev_strt=intervals[0][0];
        int prev_end=intervals[0][1];
           int n=intervals.size();
        for(int i=1;i<n;i++){
           vector<int>currVec=intervals[i];
           int curr_strt=currVec[0];
           int curr_end=currVec[1];
           if(curr_strt<=prev_end){
              // toh new end bna do 
              prev_end=max(curr_end,prev_end);

           }
           else{
            // previous merged interval daal do
            vector<int>vec;
            vec.push_back(prev_strt);
            vec.push_back(prev_end);
              result.push_back(vec);

              // pointer move karo
              prev_strt=curr_strt;
              prev_end=curr_end;
           }
        }
        result.push_back({prev_strt,prev_end}); // end interval
        return result; 
    }
};
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // step 1: sort according to the first number in each vec
        // step 2 : iterate through the intervals 
        // mind map: mujhe prev start aur prev end pta hona chahiye.
        // iteration index 1 se shuru karo 

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
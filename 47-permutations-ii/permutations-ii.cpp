class Solution {
public:
vector<vector<int>>sets;
   void solve(vector<int>&nums,vector<int>&visited,vector<int>&curr){
            if(curr.size()==nums.size()){
                sets.push_back(curr);
                return;
            }
            int n=nums.size();
            for(int i=0;i<n;i++){
                if(visited[i]==0){
                    visited[i]=1;
                    curr.push_back(nums[i]);
                    solve(nums,visited,curr);
                    curr.pop_back();
                    visited[i]=0;

                }

            }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
       int n=nums.size();
       vector<int>curr;
       vector<int>visited(n,0);
       solve(nums,visited,curr);
set<vector<int>> st(sets.begin(), sets.end());

// Set ko vector mein convert karo
vector<vector<int>> result(st.begin(), st.end());

return result;
    }
};
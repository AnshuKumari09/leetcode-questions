class Solution {
public:
vector<vector<int>>result;
   void solve(vector<int>& nums,vector<int>&visited,vector<int>curr){
            if(curr.size()==nums.size()){
                result.push_back(curr);
                return;
            }
            for(int i=0;i<nums.size();i++){
                if(visited[i]==0){
                        visited[i]=1;
                        curr.push_back(nums[i]);
                        solve(nums,visited,curr);
                        curr.pop_back();
                        visited[i]=0;
                }
            }
    }
    vector<vector<int>> permute(vector<int>& nums) {
       
       int n=nums.size();
       vector<int>visited(n,0);
        vector<int>curr;
       solve(nums,visited,curr);
       return result; 
    }
};
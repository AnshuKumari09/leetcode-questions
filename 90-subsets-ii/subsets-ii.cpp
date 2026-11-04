// class Solution {
// public:
//     vector<vector<int>> subsetsWithDup(vector<int>& nums) {
//         vector<vector<int>>result;
//         set<vector<vector<int>>>result;
//         result.insert({});
//         for(int i=0;i<nums.size();i++){
//              vector<int>temp;
//             for(int j=i;j<nums.size();j++){
//             temp.push_back(nums[j]);
//             result.insert(temp);
//           }
//         }
//         vector<vector<int>>finalResult;
//         for(auto vec:result){
//             finalResult.push_back(vec);
//         }
//         return result;
//     }
// };

class Solution {
public:
set<vector<int>>result;
    void findSubsets(vector<int>& nums,int i,vector<int>temp){
        result.insert(temp);
        if(i>=nums.size()){
          return;   
        }
        // take
        temp.push_back(nums[i]);
        findSubsets(nums, i + 1, temp);
        temp.pop_back();
        findSubsets(nums,i+1,temp);

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
       
       
        sort(nums.begin(), nums.end()); 
        vector<int>temp;
        findSubsets(nums,0,temp);
       
       vector<vector<int>> finalResult(result.begin(), result.end());
        return finalResult;
    }
};
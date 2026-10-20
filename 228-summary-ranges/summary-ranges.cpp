class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int i=0;
        int j=0;
        int n=nums.size();
        vector<string>result;
        string tmp="";
        while(j<n){
            if (j + 1 < n && (long long)nums[j + 1] - nums[j] == 1){
                    j++;
            }
            else if(i==j){
                tmp = to_string(nums[i]);
                result.push_back(tmp);
                tmp="";
                i=j+1;
                j++;                
            }
            else{
                tmp = to_string(nums[i]) + "->" + to_string(nums[j]);
                result.push_back(tmp);
                tmp="";
                i=j+1;
                j++;
            }
        }
        return result;
    }
};
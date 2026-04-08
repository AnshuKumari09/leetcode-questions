class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<long long>vec;
        int i=0;
      while(i<n){
        long long sum=0;
    
        for(int j=i;j<n;j++){
            // k=1
            sum+=nums[j];
            vec.push_back(sum);
           
        }
        i++;
      } 

      sort(vec.begin(),vec.end());
      long long result=0;
        int MOD = 1e9 + 7;
      for(int k=left-1;k<=right-1;k++){
            result = (result + vec[k]) % MOD;
      }
      return result;

    }
};
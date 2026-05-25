// class Solution {
// public:
//     int subarraySum(vector<int>& nums, int k) {
//         // with two pointer method
//         int n=nums.size();
//         int i=0;
//         int j=0;
//         int res=0;
//         int sum=0;
//         while(j<n){
//              sum+=nums[j];
//             // if(j==n-1){
//             //     j=i;
//             //     i++;
//             //     sum=0;
//             // }
         
//           if(sum>k){
//             // sum-=nums[i];
//             sum=0;
//            j=i;
//             i++;
            
//           }
//           else if(sum==k){
//             res++;
//           }
//           j++;
//         }
//         return res;
//     }
// };

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // with two pointer method
        int n=nums.size();
        int i=0;
        int j=0;
        int res=0;
        int sum=0;
       for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
             sum+=nums[j];
             if(sum==k){
               res++;
             }
        }
       }
        return res;
    }
};



// class Solution {
// public:
//     int subarraySum(vector<int>& nums, int k) {
//         // with two pointer method
//         int n=nums.size();
//         int sum=0;
//         vector<int>vec;
//        for(int i=0;i<n;i++){
//            sum+=nums[i];
//            vec.push_back(sum);
//        }
//         int res=0;
        
//     for(int i=0;i<n;i++){
//         if(vec[i]==k){
//                 res++;
//             }
//         for(int j=i+1;j<n;j++){
            
//             if((vec[j]-vec[i])==k){
//                 res++;
//             }
//         }
//        }
//         return res;
//     }
// };

// class Solution {
// public:
//     int subarraySum(vector<int>& nums, int k) {
//         // with two pointer method
//         int n=nums.size();
//         int sum=0;
//         vector<int>vec;
//        for(int i=0;i<n;i++){
//            sum+=nums[i];
//            vec.push_back(sum);
//        }
//        int res=0;
//         unordered_map<int,int>mp;
//         mp[0]=1;
//         for(int i=0;i<n;i++){
//             int num=vec[i]-k;
//             for(auto m:mp){
//                 if(m.first==num){
//                     res+=m.second;
//                 }
//             }
//             mp[vec[i]]++;
//         }
//         return res;
//     }
// };


// class Solution {
// public:
//     int subarraySum(vector<int>& nums, int k) {

//         int n = nums.size();

//         int sum = 0;

//         vector<int> vec;

//         for(int i = 0; i < n; i++) {
//             sum += nums[i];
//             vec.push_back(sum);
//         }

//         int res = 0;

//         unordered_map<int,int> mp;

//         mp[0] = 1;

//         for(int i = 0; i < n; i++) {

//             int num = vec[i] - k;

//             // agar pehle mila hai
//             if(mp.find(num) != mp.end()) {
//                 res += mp[num];
//             }

//             // current prefix sum store karo
//             mp[vec[i]]++;
//         }

//         return res;
//     }
// };
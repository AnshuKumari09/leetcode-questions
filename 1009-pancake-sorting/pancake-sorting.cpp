// class Solution {
// public:

//     int findIndex(vector<int>&arr,int num){
//         for(int j=0;j<i;j++){
//             if(arr[j]==num){
//                 return j;
//             }
//         }
//         return -1;
//     }
//     vector<int> pancakeSort(vector<int>& arr) {
//         // step 1 -> pick the largest number (index)
//         // step 2 -> reverse upto 

//         int n=arr.size();

//         for(int i=n;i>=2;i--){
//             int idx=findKIndex(arr,i);
//          if(idx == i-1) {
//                 continue;
//             }
                
//                 // ab idx zero se leke idx tk reverse maar do
//                 reverse(arr.begin(),arr.begin()+idx); 
//                 wapas reverse maaro
//                 reverse(arr.begin(),arr.begin()+i);

//         }
//     }
// };

// 4,2,3,1 -> 4
// 1,3,2,4 -> 2
// 3,1,2,4 ->4
// 2,1,3,4 -> 


class Solution {
public:

    int findIndex(vector<int>& arr, int num) {
        for(int j = 0; j < arr.size(); j++) {
            if(arr[j] == num) {
                return j;
            }
        }
        return -1;
    }

    vector<int> pancakeSort(vector<int>& arr) {

        int n = arr.size();
        vector<int> ans;

        for(int i = n; i >= 2; i--) {

            int idx = findIndex(arr, i);

            // Already correct position par hai
            if(idx == i-1) {
                continue;
            }

            // Flip 1: Largest element ko front par lao
            if(idx != 0) {
                reverse(arr.begin(), arr.begin() + idx + 1);
                ans.push_back(idx + 1);
            }

            // Flip 2: Largest element ko correct position par lao
            reverse(arr.begin(), arr.begin() + i);
            ans.push_back(i);
        }

        return ans;
    }
};



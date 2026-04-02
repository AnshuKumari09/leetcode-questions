// class Solution {
// public:
//     long long getDescentPeriods(vector<int>& prices) {
//         int n=prices.size();
//         int count=0;
//          bool flag=false;
//         for(int i=0;i<n-1;i++){
//             if(prices[i]-prices[i+1]==1){
//                 count++;
//             }
//         }
//         long long ans=n+count;
//         return ans;
//     }
// };

// class Solution {
// public:
//     long long getDescentPeriods(vector<int>& prices) {
//         int n=prices.size();
//         int count=0;
//          bool flag=false;
//         for(int i=0;i<n-1;i++){
//             if(prices[i]-prices[i+1]==1 && flag==false){
//                 count++;
//                 flag=true;
//             }
//             else if(prices[i]-prices[i+1]==1 && flag==true){
//                 count+=2;
//             }
//             else if(prices[i]-prices[i+1]!=1){
//                flag=false;
//             }
//             }

//               long long ans=n+count;
//         return ans;
//         }
// };


class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n=prices.size();
        long long count=0;
        long long len=1;
        
        for(int i=0;i<n-1;i++){
        if(prices[i]-prices[i+1]==1){
            len++;
        }
        else{
            len=1;
        }
            
            count+=(len-1);
            }
              
              long long ans=n+count;
        return ans;
        }
};
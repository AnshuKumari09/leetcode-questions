// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//       int i=0;
//         int n=prices.size();
//       int profit=INT_MIN;
//     while(i<n){
//        for(int j=i+1;j<n;j++){ 
//         if(prices[i]<prices[j]){
//            profit=max(profit,prices[j]-prices[i]);
//         }
//       }
//       i++;
//       }
//        if(profit==INT_MIN){
//         return 0;
//        }
//       return profit;  
//     }
// };


class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int i=0;
        int n=prices.size();
      int profit=INT_MIN;
       vector<int>mini;
        int minim=INT_MAX;
       for(int i=0;i<n;i++){
           
          minim=min(minim,prices[i]);
          mini.push_back(minim);
       }
      
       for(int i=n-1;i>=0;i--){
           profit=max(profit,prices[i]-mini[i]); 
       }
      return profit;  
    }
};
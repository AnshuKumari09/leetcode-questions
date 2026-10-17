// class Solution {
// public:
//     int minEatingSpeed(vector<int>& piles, int h) {
//         vector<int>pile=piles;
//         sort(pile.begin(),pile.end(),greater<int>());
//         int mx=pile[0];

//         int result=0;

//         for(int num=1;num<=mx;num++){
//             long long total=0;
//             for(int i=0;i<piles.size();i++){
//                 if(piles[i]<=num){
//                     total+=1;
//                 }
//                 else{
//                     if(piles[i]%num==0){
//                         total+=(piles[i]/num);
//                     }
//                     else{
//                         total+=(piles[i]/num)+1;
//                     }
//                 }
//             }
//             if(total<=h){
//                 result=num;
//                 break;
//             }
//         }
//           return result;
//     }
// };



class Solution {
public:
    bool checkValid(vector<int>&piles,int h,int num){
            long long total=0;
            for(int i=0;i<piles.size();i++){
                if(piles[i]<=num){
                    total+=1;
                }
                else{
                    if(piles[i]%num==0){
                        total+=(piles[i]/num);
                    }
                    else{
                        total+=(piles[i]/num)+1;
                    }
                } 
            }
             if(total<=h){
                return true;
             }
            return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int res=0;
      int l=1;
      vector<int>pile=piles;
      sort(pile.begin(),pile.end(),greater<int>());

      int r=pile[0];
      while(l<=r){
         int mid=(l+r)/2;
         
         if(checkValid(piles,h,mid)){
            res=mid;
            r=mid-1;
         }
         else{
            l=mid+1;
         }

      }
      return res;
    }
};
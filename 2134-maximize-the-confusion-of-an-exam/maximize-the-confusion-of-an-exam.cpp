// class Solution {
// public:

//     int largestLength(string answerKey){
//        int n=answerKey.length();
//        int currLength=1;
//        int ans;
//        for(int i=1;i<n;i++){
           
//             if(answerKey[i]==answerKey[i-1]){
//                currLength++;

//             }
//             else{
//               ans=max(ans,currLength);
//                currLength=1;
//             }
//        }
//        ans=max(ans,currLength);
//        return ans;
//     }
//     int maxLength=0;
//     void solve(string answerKey,int k,int i){
//           if(k<0){
          
//         return;
//         }
//         if(i>=answerKey.length()){
//              // find the longest consecutive F or T
//            int length=largestLength(answerKey);
//            maxLength=max(maxLength,length);

//             return;
//         }
      
//        // change 
//        string flipped=answerKey;
//        if(flipped[i]=='F'){
//         flipped[i]='T';
//        }
//        else{
//         flipped[i]='F';
//        }
//        solve(flipped,k-1,i+1);
//        // not change
//        solve(answerKey,k,i+1);
//     }
//     int maxConsecutiveAnswers(string answerKey, int k) {
//         solve(answerKey,k,0);// 0 is the index
//         return maxLength;

//     }
// };

// class Solution {
// public:

//     int largestLength(string &answerKey){
//        int n=answerKey.length();
//        int currLength=1;
//        int ans=1;
//        for(int i=1;i<n;i++){
           
//             if(answerKey[i]==answerKey[i-1]){
//                currLength++;

//             }
//             else{
//               ans=max(ans,currLength);
//                currLength=1;
//             }
//        }
//        ans=max(ans,currLength);
//        return ans;
//     }
//     int maxLength=0;
//     void solve(string &answerKey,int k,int i){
//           if(k<0){
          
//         return;
//         }
//         if(i>=answerKey.length()){
//              // find the longest consecutive F or T
//            int length=largestLength(answerKey);
//            maxLength=max(maxLength,length);

//             return;
//         }
      
//        // change 
//       answerKey[i]=answerKey[i]=='T'?'F':'T';
//                solve(answerKey,k-1,i+1);
//        // not change
//        answerKey[i]=answerKey[i]=='T'?'F':'T';
//        solve(answerKey,k,i+1);
//     }
//     int maxConsecutiveAnswers(string answerKey, int k) {
//         solve(answerKey,k,0);// 0 is the index
//         return maxLength;

//     }
// };


class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n=answerKey.length();

       vector<int>vec(n);// changing F to T
       int num=n;
       for(int i=n-1;i>=0;i--){
          vec[i]=num;
          if(answerKey[i]=='F'){
            num=i;
          }
       }

       int i=0;
       int count=0;
       int j=0;
       int maxLength=0;
       while(j<n){
           if (answerKey[j] == 'F'){
               count++;
           }
            while(count>k){
               if(answerKey[i]=='F'){
                   count--;
               }
               i++;
            }
            
           

        maxLength=max(maxLength,j-i+1);
         j++;
        
       }


      //  similar way for doing T to F
          vector<int>vec2(n);
       int num2=n;
       for(int i=n-1;i>=0;i--){
          vec2[i]=num2;
          if(answerKey[i]=='T'){
            num2=i;
          }
       }
       int i2=0;
       int count2=0;
       int j2=0;
       
       while(j2<n){
        if(answerKey[j2]=='T'){
            count2++; 
        }   
          while(count2>k){
                // valid 
                if(answerKey[i2]=='T')
                {
                    count2--;
                }
               
                 i2++;
            }
            
        
        maxLength=max(maxLength,j2-i2+1);
        j2++;
       }
       return maxLength;

    }
    
}; 
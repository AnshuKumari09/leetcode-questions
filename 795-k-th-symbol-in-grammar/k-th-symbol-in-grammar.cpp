// class Solution {
// public:
//      char kthChar(int n,int k,int whichHalf,int positionInhalf){
//         if(n<=1){
//             return '0';
//         }
//         if(whichHalf==0){  // base case
//             if(positionInhalf==0){
//                 return '0';
//             }
//             else{
//                 return '1';
//             }
//         }
//         else if(whichHalf==1){ //base case
//             if(positionInhalf==1){
//                 return '0';
//             }
//             else{
//                 return '1';
//             } 
//         }
//          return kthChar(n-1,k-1,(k-1)/2,(k-1)%2); 

//      }
//     int kthGrammar(int n, int k) {
//         quotient = k-1/2
//         remainder=k-1%2
//         return kthChar(n-1,k-1,(k-1)/2,(k-1)%2);// i m giving index of position (k) not the val
        
//     }
// };

class Solution {
public:

    int kthChar(int n, int idx){
        // base case
        if(n == 1){
            return 0;
        }

        int parentIdx = idx / 2;
        int positionInHalf = idx % 2;

        int parent = kthChar(n-1, parentIdx);

        if(positionInHalf == 0){
            // left → same
            return parent;
        }
        else{
            // right → flip
            return 1 - parent;
        }
    }

    int kthGrammar(int n, int k) {
        return kthChar(n, k-1); // only here k-1
    }
};
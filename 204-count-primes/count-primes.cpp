// class Solution {
// public:
//     bool checkPrime(int n){
//          if (n < 2) {
//             return false;
//         }
//         int noOffactors=0;
//         for(int i=2;i*i<=n;i++){
//             if(n%i==0){
//                 return false;
//             }
//         }

//         return true;
//     }
//     int countPrimes(int n) {
//         int count=0;
//         for(int i=2;i<n;i++){
//             if(checkPrime(i)){
//                 count++;
//             }
//         }
//         return count;
//     }
// };


// class Solution {
// public:
//     bool checkPrime(int n){
//          if (n < 2) {
//             return false;
//         }
//         int noOffactors=0;
//         for(int i=2;i<=n/2;i++){
//             if(n%i==0){
//                 return false;
//             }
//         }

//         return true;
//     }
//     int countPrimes(int n) {
//         int count=0;
//         for(int i=2;i<n;i++){
//             if(checkPrime(i)){
//                 count++;
//             }
//         }
//         return count;
//     }
// };



class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;

        int count = 0;
        vector<bool> vec(n, true);

        vec[0] = false;
        vec[1] = false;

        for (int i = 2; i * i < n; i++) {
         int j = i;

            while (i * j < n) {
                vec[i * j] = false;
                j++;
            }

        }

        for (int i = 2; i < n; i++) {
            if (vec[i] == true) {
                count++;
            }
        }

        return count;
    }
};


// class Solution {
// public:

//     bool ifVowel(char ch){
//         if(ch=='a' || ch=='e' || ch=='i' || ch=='o' ||ch=='u'){
//             return true;
//         }
//         return false;
//     }
//     long long countOfSubstrings(string word, int k) {
//          int n=word.length();
//          vector<int>vec(n);
//          int nextIndex=n; 
//          for(int i=n-1;i>=0;i--){
//             vec[i]=nextIndex;
//              if(!ifVowel(word[i])){
//                 nextIndex=i;
//              }
//          }

//          unordered_map<char,int>mp;
//          int i=0;
//          int j=0;
//          int countOfCons=0;
//           long long result=0;
//          while(i<n && j<=n-1){
//             if(ifVowel(word[j])){
//                 mp[word[j]]++;

//             }
//            else{
//                 countOfCons++;
//             }
//             if(countOfCons>k){
//                 i++;
//                 j=i;
//                 countOfCons=0;
//                 // clear the map of all
//                mp.clear();
//               continue;

//             }
           
//             if(mp.size()<5 || countOfCons<k){ // if aeiou all are present
//                 j++;
//                 continue;
//             }

//              if(mp.size()==5 && countOfCons==k){ // valid substring
//                 int num=vec[j]-j;
//                 result+=num;
//                 i++;
//                 j=i;
//                   // clear the map of all
//                mp.clear();
//                countOfCons=0;
    
//             }
//          }
//          return result;
//     }
// };


class Solution {
public:

    bool ifVowel(char ch){
        return ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u';
    }

    long long countOfSubstrings(string word, int k) {

        int n = word.length();

        vector<int> vec(n);

        int nextIndex = n;

        // next consonant index
        for(int i=n-1;i>=0;i--){

            vec[i] = nextIndex;

            if(!ifVowel(word[i])){
                nextIndex = i;
            }
        }

        unordered_map<char,int> mp;

        int i=0;
        int j=0;

        int countOfCons=0;

        long long result=0;

        while(j<n){

            // add current char
            if(ifVowel(word[j])){
                mp[word[j]]++;
            }
            else{
                countOfCons++;
            }

            // shrink if consonants exceeded
            while(countOfCons > k){

                if(ifVowel(word[i])){

                    mp[word[i]]--;

                    if(mp[word[i]]==0){
                        mp.erase(word[i]);
                    }
                }
                else{
                    countOfCons--;
                }

                i++;
            }

            // valid substring
            while(mp.size()==5 && countOfCons==k){

                result += (vec[j]-j);

                // remove left side
                if(ifVowel(word[i])){

                    mp[word[i]]--;

                    if(mp[word[i]]==0){
                        mp.erase(word[i]);
                    }
                }
                else{
                    countOfCons--;
                }

                i++;
            }

            j++;
        }

        return result;
    }
};
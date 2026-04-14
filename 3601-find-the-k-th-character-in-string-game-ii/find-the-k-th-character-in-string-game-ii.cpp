// class Solution {
// public:
//      string findString(vector<int>& operations,string word,int i){
//         if(i==operations.size()){
//             return word;
//         }
//         else{
//              if(operations[i]==0){
//              return findString(operations, word + word, i+1);
//             }
//            else{
//                 //find the next char string first
//                 string temp="";
//                 for(int j=0;j<word.size();j++){
//                     char nextchar=(word[j]=='z')?'a':word[j]+1;
//                     temp+=nextchar;
//                 }

//                 return findString(operations,word+temp,i+1);
//           }
//         }
        
       
//      }
//     char kthCharacter(long long k, vector<int>& operations) {
//         int n=operations.size();
//         string word="a";
//        string finalWord=findString(operations,word,0);
//         return finalWord[k-1];
//     }
// };


class Solution {
public:

    char findnextchar(char ch){
        if(ch=='z'){
            return 'a';
        }
        return ch+1;
    }
    char findChar(vector<int>& operations,int i,long long k,long long l){
        if(i<0){
            return 'a';
        }
      
            if(k<=l/2){
            return findChar(operations,i-1,k,l/2);
        }
        else{
                  if(operations[i]==0){
            return findChar(operations,i-1,k-(l/2),l/2);
          }
          else{
            return findnextchar(
                    findChar(operations, i-1, k - (l/2), l/2)
                );
          }
        }   
    }
    char kthCharacter(long long k, vector<int>& operations) {
        int n=operations.size();
        
       long long len = 1;
       for(int i=0;i<n;i++){
        len*=2;
        if(len>=k){
            // 
           return findChar(operations,i,k,len);
        }
       }
       return 'a';
    }
};

// class Solution {
// public:
//     vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
//         vector<string>result;
//         for(string query:queries){
//                for(string dict:dictionary){
//                 int i=0;
//                 int countNotMatching=0;
//                 while(i<=query.length()-1){
                    
//                     if(query[i]!=dict[i]){
//                         countNotMatching++;
//                     }
//                     if(countNotMatching>2){
//                         break;
//                     }
//                     i++;
//                 }
//                  if(countNotMatching<=2){
//                   result.push_back(query);
//                   break;
//                }
//                }
              
//         }
//         return result;
//     }
// };


class Solution {
public:

    bool isPossible(string &a, string &b){

        int mismatch = 0;

        for(int i = 0; i < a.length(); i++){

            if(a[i] != b[i]){
                mismatch++;
            }

            if(mismatch > 2){
                return false;
            }
        }

        return true;
    }

    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {

        vector<string> result;

        for(string &query : queries){

            for(string &dict : dictionary){

                if(isPossible(query, dict)){
                    result.push_back(query);
                    break;
                }
            }
        }

        return result;
    }
};
// class Solution {
// public:

//       void solve(int i,int n,vector<int>&possibleValues,string currString,set<string>&foundStrings,string result,vector<string>&results,int minLen){
//              if(i>=possibleValues.size()){
//                 return;
//             }
//         if(currString.length()==n){
//             foundStrings.insert(currString);
//             solve(i+1,n,possibleValues,currString.substr(1),foundStrings,result,results,minLen);
//         }
//         if(result.length()==minLen){
//                 results.push_back(result);
//                 return;
//         }

//            for(int j=i;j<possibleValues.size();j++){
//                 solve(i+1,n,possibleValues,currString+to_string(possibleValues[i]),foundStrings,result+to_string(possibleValues[i]),results,minLen);
//            }

//         }
//     string crackSafe(int n, int k) {
//         int minLen=n+pow(2,n)-1;
//         vector<int>possibleValues;
//         for(int i=0;i<k;i++){
//             possibleValues.push_back(i);
//         }
       
//         set<string>foundStrings;
//         vector<string>results;
//         solve(0,n,possibleValues,"",foundStrings,"",results,minLen);
//         sort(results.begin(),results.end());
//         return results[0];
//     }
// };


class Solution {
public:

    unordered_set<string> visited;
    string result;

    void solve(string curr, int n, int k) {

        for(int i = 0; i < k; i++) {

            string next = curr + to_string(i);

            if(visited.find(next) == visited.end()) {

                visited.insert(next);

                solve(next.substr(1), n, k);

                result += to_string(i);
            }
        }
    }

    string crackSafe(int n, int k) {

        string start(n - 1, '0');

        solve(start, n, k);

        result += start;

        return result;
    }
};
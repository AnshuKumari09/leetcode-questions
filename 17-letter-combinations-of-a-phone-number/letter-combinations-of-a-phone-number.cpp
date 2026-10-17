class Solution {
public:

   void solve(unordered_map<char,vector<char>>&mp,string digits,vector<string>&result,int i,string currString){
        if(i==digits.length() || currString.length()==digits.length()){
            result.push_back(currString);
            return;
        }
        for(auto m:mp[digits[i]]){
            solve(mp,digits,result,i+1,currString+m);
        }

   }
    vector<string> letterCombinations(string digits) {
        vector<string>result;
         unordered_map<char,vector<char>>mp;
         mp['2']={'a','b','c'};
         mp['3']={'d','e','f'};
         mp['4']={'g','h','i'};
         mp['5']={'j','k','l'};
        mp['6']={'m','n','o'};
         mp['7']={'p','q','r','s'};
        mp['8']={'t','u','v'};
         mp['9']={'w','x','y','z'};
        //  for(int i=0;i<digits.length();i++){
        //     if(digits.lenth()==1){
        //         return mp[digits[i]];
        //     }

   // }//

        solve(mp,digits,result,0,"");
        return result;
    }
};


// class Solution {
// public:
//     void solve(unordered_map<char, vector<char>>& mp,
//                string digits,
//                vector<string>& result,
//                int i,
//                string currString) {

//         if (i == digits.length()) {
//             result.push_back(currString);
//             return;
//         }

//         for (auto m : mp[digits[i]]) {
//             solve(mp, digits, result, i + 1, currString + m);
//         }
//     }

//     vector<string> letterCombinations(string digits) {
//         vector<string> result;

//         if (digits.empty()) {
//             return result;
//         }

//         unordered_map<char, vector<char>> mp;

//         mp['2'] = {'a', 'b', 'c'};
//         mp['3'] = {'d', 'e', 'f'};
//         mp['4'] = {'g', 'h', 'i'};
//         mp['5'] = {'j', 'k', 'l'};
//         mp['6'] = {'m', 'n', 'o'};
//         mp['7'] = {'p', 'q', 'r', 's'};
//         mp['8'] = {'t', 'u', 'v'};
//         mp['9'] = {'w', 'x', 'y', 'z'};

//         solve(mp, digits, result, 0, "");

//         return result;
//     }
// };

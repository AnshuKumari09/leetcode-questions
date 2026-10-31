class Solution {
public:
        vector<string>result;
        bool valid(string currString){
            if(currString=="" || currString.length() > 3){
                return false;
            }
            int currNo=stoi(currString);
            if(currNo>255 || (currString.length()>1 && currString[0]=='0')){
                return false;
            }
            return true;
        }
       void solve(string s,int remainingCuts,int cutOnIndex,string firstString,string remainingString,string finalString){
        int n=remainingString.length();
            if(!valid(firstString)){
                return;
            }
                finalString+=(finalString.empty()?"":".")+firstString;
            if(remainingCuts==0){
                if(remainingString.empty()){
                    result.push_back(finalString);
                  
                }
                  return;

            }

            if(n>=1){
                solve(s,remainingCuts-1,cutOnIndex+1,remainingString.substr(0,1),remainingString.substr(1),finalString);
            }
            if(n>=2){
                solve(s,remainingCuts-1,cutOnIndex+2,remainingString.substr(0,2),remainingString.substr(2),finalString);
            }
            if(n>=3){
                solve(s,remainingCuts-1,cutOnIndex+3,remainingString.substr(0,3),remainingString.substr(3),finalString);
            }
            


        }

    vector<string> restoreIpAddresses(string s) {
        result.clear();

        if(s.length() < 4 || s.length() > 12) {
            return result;
        }

        for(int len = 1; len <= 3; len++) {
            solve(s, 3, len, s.substr(0, len), s.substr(len), "");
        }

        return result;
    }
};
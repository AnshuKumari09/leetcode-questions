class Solution {
public:
vector<string>result;
    void solve(int n,string s,int i,string currString){
         if(currString.length()==n){
        result.push_back(currString);
        return;
      }
      if(i>=3){
          return;
      }
     
      // take
      if(currString.empty() || currString.back()!=s[i]){
         solve(n,s,0,currString+s[i]);
      }
     
      //skip
      solve(n,s,i+1,currString);
    }
    string getHappyString(int n, int k) {
        solve(n,"abc",0,"");
        if (k > result.size()) return "";
       return result[k-1];
    }
};
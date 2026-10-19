class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        int len=s.length();
        int i=0;
        unordered_map<char,char>mp;
        mp['{']='}';
        mp['[']=']';
        mp['(']=')';

        while(len--){
            if(s[i]=='}' || s[i]==']' || s[i]==')'){
                if(!st.empty() && mp[st.top()] == s[i]){
                    st.pop();
                }
                else{
                    return false;
                }
             
            }
           else{
                st.push(s[i]);
            }

            i++;
        }
        if(st.empty() ){
            return true;
        }
        return false;
    }
};
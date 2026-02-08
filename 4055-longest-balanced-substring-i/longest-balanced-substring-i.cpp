class Solution {
public:
    int longestBalanced(string s) {
      int maxLength=0;
      int n=s.length();
      for(int i=0;i<n;i++){
         unordered_map<char,int>mp;
        for(int j=i;j<n;j++){
           // how many characters have count >0 and same count
             mp[s[j]]++;
            //  if(the counts of different letters are equal and other than those letters have count=0){
            //     maxLength==max(maxLength,these counts);
            //  }
            int target=-1;
            bool balanced=true;
            for(auto it:mp){
                if(it.second>0){
                    if(target==-1){
                          target=it.second;
                    }
                    else if(it.second!=target){
                    balanced=false;
                    break;
                }
                  
                }
                
            }
            if(balanced){
                  int length=j-i+1;
                  maxLength=max(length,maxLength);
            }     
        }            
      }
       return maxLength;
    }
};
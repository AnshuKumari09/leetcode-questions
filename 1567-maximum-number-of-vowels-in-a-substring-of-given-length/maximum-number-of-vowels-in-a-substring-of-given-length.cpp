class Solution {
public:
    int maxVowels(string s, int k) {
      
        int windowCount=0;
        for(int i=0;i<k;i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
                  windowCount++;
            }
        }
           int i=0;
           int n=s.length();
           int j=k-1;
           int maxCount=0;
        while(j<n){
             maxCount=max(windowCount,maxCount);
             if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
                  windowCount-=1;
            }
            i++;
            j++;
            if(j<n){
              if(s[j]=='a' || s[j]=='e' || s[j]=='i' || s[j]=='o' || s[j]=='u'){
                  windowCount+=1;
               }   
            }
        }
        return maxCount;
    }
};
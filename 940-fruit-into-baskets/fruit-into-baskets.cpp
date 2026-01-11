class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int i=0;
        int j=0;
        unordered_map<int,int>mp;
        int n=fruits.size();
        int maxlength=INT_MIN;
        while(j<n){
            mp[fruits[j]]++;
            
            while(mp.size()>2){
                mp[fruits[i]]--;
                if(mp[fruits[i]]==0){
                     mp.erase(fruits[i]);
                }
               
                i++;
            }
            int currlength=j-i+1;
             maxlength=max(maxlength,currlength);
            j++;
        }
        return maxlength;
    }
};
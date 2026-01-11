// class Solution {
// public:
//     int countGoodSubstrings(string s) {
//         unordered_map<char,int>mp;
//         for(int i=0;i<3;i++){
//             mp[s[i]]++;
//         }
//         int i=0;
//         int j=2;
//         int n=s.length();
//         int result=0;
//         while(j<n){
//             int count=0;
//             for(auto m:mp){
//                 if(mp[m.first]==1){
//                     count++;
//                 }
//             }
//             if(count==3){
//                 result++;
//             }

//             if(mp[s[i]]>0){
//                  mp[s[i]]-=1;
//             }
//             i++;
//             j++;
//             if(j<n){
//                 mp[s[j]]++;
//             }
//         }
//         return result;
//     }
// };

class Solution {
public:
    int countGoodSubstrings(string s) {
        unordered_map<char,int>mp;
        for(int i=0;i<3;i++){
            mp[s[i]]++;
        }
        int i=0;
        int j=2;
        int n=s.length();
        int result=0;
        while(j<n){
            if(mp.size()==3){
                result++;
            }
            mp[s[i]]--;
            if(mp[s[i]]==0){
                 mp.erase(s[i]);
            }
            i++;
            j++;
            if(j<n){
                mp[s[j]]++;
            }
        }
        return result;
    }
};
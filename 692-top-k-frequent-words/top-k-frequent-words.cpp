// class Solution {
// public:
//     vector<string> topKFrequent(vector<string>& words, int k) {
//         typedef pair<int,string>P;
//         struct comp{
//             bool operator()(P& a,P& b){
//                 if(a.first==b.first){
//                     return a.second>b.second;
//                 }
//                 else{
//                     return b.first>a.first;
//                 }
//             }
//         };
//         unordered_map<string,int>mp;
//         for(string word:words){
//             mp[word]++;
//         }
//         priority_queue<P,vector<P>,comp>pq;
//         for(auto m:mp){
//              pq.push({m.second,m.first});  
//         }
//         vector<string>result;

//         while(k--){
//             result.push_back(pq.top().second);
//             pq.pop();
            
//         }
//         return result;
//     }
// };


class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        typedef pair<int,string>P;
        struct comp{
            bool operator()(P& a,P& b){
                if(a.first==b.first){
                    return a.second<b.second;
                }
                else{
                    return b.first<a.first;
                }
            }
        };
        unordered_map<string,int>mp;
        for(string word:words){
            mp[word]++;
        }
        priority_queue<P,vector<P>,comp>pq;
        for(auto m:mp){
             pq.push({m.second,m.first});  
             if(pq.size()>k){
                pq.pop();
             }
        }
        vector<string>result;

        while(k--){
            result.push_back(pq.top().second);
            pq.pop();
        }
        reverse(result.begin(),result.end());
        return result;
    }
};
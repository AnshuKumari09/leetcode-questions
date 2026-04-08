class Solution {
public:
    string reorganizeString(string s) {
        int n=s.length();
        unordered_map<char,int>mp;
        for(char ch:s){
            mp[ch]++;
            if(n%2==0 && mp[ch]>=n/2+1){
               return "";
            }
            else if(n%2!=0 && mp[ch]>n/2+1){
                 return "";
            }
        }
        // ab kya?
        typedef pair<int,char>p;
        priority_queue<p>pq; // max heap
        for(auto m:mp){
            pq.push({m.second,m.first});
        }
        string result="";
       while(pq.size()>=2){

             p top1=pq.top();
             pq.pop();
             if(top1.first>0){
                 result+=top1.second;
                 top1.first--;

             }
              p top2=pq.top();
              pq.pop();
            if(top2.first>0){
                
               result+=top2.second;
                top2.first--;
            }
            if(top1.first > 0) pq.push(top1);
           if(top2.first > 0) pq.push(top2);
        }
        if(!pq.empty()){
            if(pq.top().first > 1) return "";
            result+=pq.top().second;
            
        }
    return result;
    }
};
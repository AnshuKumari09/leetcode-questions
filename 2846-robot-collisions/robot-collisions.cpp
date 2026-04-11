class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        
        int n = positions.size();

        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[positions[i]] = i;
        }

        sort(positions.begin(), positions.end());

        vector<int> vec;
        for(int x:positions){
            vec.push_back(mp[x]);
        }

        stack<int> st;

        for(int i=0;i<n;i++){
            int x = vec[i];

            while(!st.empty() && directions[st.top()] == 'R' && directions[x] == 'L'){
                
                if(healths[x] == healths[st.top()]){
                    healths[x] = 0;
                    healths[st.top()] = 0;
                    st.pop();
                    break;
                }
                else if(healths[x] > healths[st.top()]){
                    healths[x]--;
                    healths[st.top()] = 0;
                    st.pop();
                }
                else{
                    healths[st.top()]--;
                    healths[x] = 0;
                    break;
                }
            }

            if(healths[x] > 0){
                st.push(x);
            }
        }

        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(healths[i] > 0){
                ans.push_back(healths[i]);
            }
        }

        return ans;
    }
};
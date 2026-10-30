// class Solution {
// public:
//     vector<string> possibleSoln;

//     void solve(vector<int>& vec, vector<int>& visited, string currString) {

//         if(currString.length() == vec.size()) {
//             possibleSoln.push_back(currString);
//             return;
//         }

//         for(int i = 0; i < vec.size(); i++) {

//             if(visited[i] == 0) {

//                 visited[i] = 1;

//                 solve(vec, visited, currString + to_string(vec[i]));

//                 visited[i] = 0;
//             }
//         }
//     }

//     string getPermutation(int n, int k) {

//         vector<int> vec;

//         for(int i = 1; i <= n; i++) {
//             vec.push_back(i);
//         }

//         vector<int> visited(n, 0);

//         solve(vec, visited, "");

//         return possibleSoln[k-1];
//     }
// };




class Solution {
public:
    string getPermutation(int n, int k) {

        vector<int> vec;
        int fact = 1;

        for(int i = 1; i < n; i++) {
            fact *= i;
        }

        for(int i = 1; i <= n; i++) {
            vec.push_back(i);
        }

        k--;

        string ans = "";

        while(!vec.empty()) {

            int index = k / fact;

            ans += to_string(vec[index]);

            vec.erase(vec.begin() + index);

            if(vec.empty()) break;

            k = k % fact;

            fact = fact / vec.size();
        }

        return ans;
    }
};
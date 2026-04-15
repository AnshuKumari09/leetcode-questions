class Solution {
public:
    int findTheWinner(int n, int k) {
        // rotation me kaam chal rha
        // 1 2 3 4 5
        // k=2
        vector<int>vec;
        for(int i=0;i<n;i++){
            vec.push_back(i+1);
        }


        
    //     int j=0;
    //     while(vec.size()>1){
    //       vec.erase(vec.begin() + ((j+k-1)%vec.size()));
    //     //    j++; 
    //    j = (j + k - 1) % vec.size();
    //     }


             int idx = 0; // starting index

        while(vec.size() > 1){
            idx = (idx + k - 1) % vec.size(); // next to remove
            vec.erase(vec.begin() + idx);
        }

return vec[0];
    }
};
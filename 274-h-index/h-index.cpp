class Solution {
public:
    int hIndex(vector<int>& citations) {
        if(citations.size()==1 && citations[0]==0){
            return 0;
        }
        sort(citations.begin(),citations.end());
        int n=citations.size();
        int j=n-1;
        while(j>=0 && n-j<=citations[j]){
                j--;
        }

        return n-j-1;
    
    }
};
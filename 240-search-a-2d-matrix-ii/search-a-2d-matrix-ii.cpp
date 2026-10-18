class Solution {
public:
    bool gotTarget(int i,vector<vector<int>>& matrix,int target,int l,int r){
         while(l<=r){
            int mid=(l+r)/2;
            if(matrix[i][mid]==target){
                return true;
            }
            else if(matrix[i][mid]<target){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
         }
         return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();

        for(int i=0;i<n;i++){
            if(gotTarget(i,matrix,target,0,m-1)){
                return true;
            }
        }
        return false;
    }
};
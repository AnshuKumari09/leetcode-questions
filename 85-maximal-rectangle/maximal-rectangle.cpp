class Solution {
public:

int maximalRec = 0;

void solve(vector<int>& temp) {
    int n = temp.size();

    for (int j = 0; j < n; j++) {
        if (temp[j] == 0) continue;

        int height = temp[j];
        int width = 1;

        // Left side
        int k = j - 1;
        while (k >= 0 && temp[k] >= height) {
            width++;
            k--;
        }

        // Right side
        k = j + 1;
        while (k < n && temp[k] >= height) {
            width++;
            k++;
        }

        maximalRec = max(maximalRec, height * width);
    }
}


    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                matrix[i][j]=matrix[i][j]-'0';
            } 
        }

        vector<int>temp(n,0);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]!=0){
                   
                    temp[j]+=matrix[i][j];
                }
                else{
                      temp[j]=0;
                }
            }
               solve(temp); 
           
        }
        return maximalRec;
    }
};
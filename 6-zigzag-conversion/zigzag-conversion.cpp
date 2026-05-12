class Solution {
public:
void convert2(string &s,int curr,int numRows,vector<vector<char>>&mat,int col){
        if(curr>=s.length()){
            return;
        }
              for(int i=0;i<numRows && curr<s.length();i++){
                  mat[i][col]=s[curr];
                  curr++;
             }
           
            for(int k=numRows-2;k>0 && curr<s.length();k--){
                col++;
                 mat[k][col]=s[curr];
                 curr++;
            }
        
        convert2(s,curr,numRows,mat,col+1);

    }
    string convert(string s, int numRows) {
        if(numRows==1){
            return s;
        }
       vector<vector<char>>mat(numRows,vector<char>(s.length(),'*'));
       convert2(s,0,numRows,mat,0);
       int n=mat.size();
       int m=mat[0].size();
       string result="";
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]!='*'){
                  result+=mat[i][j];
            }
          
        }
       }
       return result;
    }
};
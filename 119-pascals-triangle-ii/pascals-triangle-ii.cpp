class Solution {
public:

    vector<int> solve(int rowIndex){
     vector<int>result;
        if(rowIndex==0){
            result.push_back(1);
            return result;
        }
        if(rowIndex==1){
            result.push_back(1);
            result.push_back(1);
            return result;
        }

        result.push_back(1);
        vector<int>temp=solve(rowIndex-1);
        for(int i=0;i<temp.size()-1;i++){
            int sum=temp[i]+temp[i+1];
            result.push_back(sum);
        }

        result.push_back(1);
        return result;

    }
    vector<int> getRow(int rowIndex) {
        vector<int>result;
        if(rowIndex==0){
            result.push_back(1);
            return result;
        }
        if(rowIndex==1){
            result.push_back(1);
            result.push_back(1);
            return result;
        }

      return solve(rowIndex);
    }
};
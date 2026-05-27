class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
  
      int i=0; // for iteration in fl
      int j=0;  // for iteration in second list
      int n=firstList.size();
      int m=secondList.size();
      vector<vector<int>>result;
      while(i<n && j<m){
        int s1=firstList[i][0];
      int e1=firstList[i][1];
      int s2=secondList[j][0];
      int e2=secondList[j][1];
      if(max(s1,s2)<=min(e1,e2)){
          result.push_back({max(s1,s2),min(e1,e2)});
        }
        if(e1<e2){
            i++;
        }
        else{
            j++;
        }
        
        
      }
        return result;
    }
};
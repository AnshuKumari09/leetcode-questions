class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string>result;
        for(string query:queries){
               for(string dict:dictionary){
                int i=0;
                int countNotMatching=0;
                while(i<=query.length()-1){
                    
                    if(query[i]!=dict[i]){
                        countNotMatching++;
                    }
                    if(countNotMatching>2){
                        break;
                    }
                    i++;
                }
                 if(countNotMatching<=2){
                  result.push_back(query);
                  break;
               }
               }
              
        }
        return result;
    }
};
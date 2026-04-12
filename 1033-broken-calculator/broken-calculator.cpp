class Solution {
public:
    int brokenCalc(int startValue, int target) {
       
        if(target<=startValue){
            // only sub operations
            return startValue-target;
        }
        else{
            //even
            if(target%2==0){
               return 1+brokenCalc(startValue,target/2); 
            }
            else{
                return 1+brokenCalc(startValue,target+1);
            }
        }
    }
};
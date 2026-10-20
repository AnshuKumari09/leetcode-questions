// class Solution {
// public:
//     bool solve(vector<int>&gas,vector<int>&cost,int i){
//         int index=i;
//         int n=gas.size();
//         //  i=(i+1)%n;
//         int j=-1;
//         int currVal=0;
//         while(j!=index){
//                 currVal+=gas[i];
                
//                 if(currVal>=cost[i]){
//                     currVal-=cost[i];
//                 }
//                 else{
//                     return false;
//                 }
//                 i=(i+1)%n;
//                 j=i;
               
//         }
//         return true;
//     }
//     int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
//         int total_gas=0;
//         int total_cost=0;
//         for(int i=0;i<gas.size();i++){
//             total_gas+=gas[i];
//         }

//         for(int i=0;i<cost.size();i++){
//             total_cost+=cost[i];
//         }

//         if(total_cost>total_gas){
//             return -1;
//         }
//         for(int i=0;i<gas.size();i++){
//           if(solve(gas,cost,i)){
//             return i;
//           }
//         }
//         return -1;
//     }
// };




class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int start = 0;
        int tank = 0;
        int total = 0;
        for(int i=0;i<n;i++){
            int diff = gas[i]-cost[i];
            total+=diff;
             tank+=diff;
            if(tank<0){
                tank=0;
                start = i+1;
            }
        }
        if(total<0){
            return -1;
        }
        return start;
    }
};
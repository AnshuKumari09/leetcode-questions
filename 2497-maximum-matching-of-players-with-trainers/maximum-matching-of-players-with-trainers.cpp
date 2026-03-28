class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());
        int count=0;
        // for(int i=0;i<players.size();i++){
        //     for(int j=0;j<trainers.size();j++){
        //         if(players[i]<=trainers[j]){
        //             count++;
        //             break;
        //         }
        //     break;
        //     }
        // }
       int i=0,j=0;
        while(i<players.size() && j<trainers.size()){
            if(players[i]<=trainers[j]){
                i++;
                j++;
                count++;
            }
            else{
                j++;
            }
        }
        return count;
    }
};
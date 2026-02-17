class Solution {
public:
    int count(int num){
        int c=0;
        while(num>0){
            if(num%2==1){
                c++;
            }
            num=num/2;
        }
        return c;
    }
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string>ans;
        for(int i=0;i<=11;i++){
            for(int j=0;j<=59;j++){
                int countBits=count(i)+count(j);
                if(countBits==turnedOn){
                     string str=to_string(i)+":";

                    if(j<10){
                       str+='0';
                    }
                    str+=to_string(j);
                    ans.push_back(str);
                }
            }
        }
        return ans;

    }
};
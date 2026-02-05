class Solution {
public:
    int compareVersion(string version1, string version2) {
        // queue USE KR LE TOH
        // jb tk next dot nhi aata,tb tk numbers collect karo
        queue<char>q1;
        queue<char>q2;
         for(int i=0;i<version1.length();i++){
            q1.push(version1[i]);
         }
         for(int j=0;j<version2.length();j++){
            q2.push(version2[j]);
         }

        //  1,.,2
        //  1,.,1,0
         while(!q1.empty() || !q2.empty()){
            int num1=0;
            int num2=0;
            while(!q1.empty() && q1.front()!='.'){ // revision
                num1=num1*10+(q1.front()-'0');
               // change char to int
               q1.pop();
            }
            while(!q2.empty() && q2.front()!='.'){ // revision
               
               // change char to int
               num2=num2*10+(q2.front()-'0');
               q2.pop();
            }
            if(!q1.empty()){
                q1.pop();
            }
            if(!q2.empty()){
                q2.pop();
            }
            if(num1>num2){
                return 1;
            }
            if(num1<num2){
                return -1;
            }
         }

       return 0;
    }
};
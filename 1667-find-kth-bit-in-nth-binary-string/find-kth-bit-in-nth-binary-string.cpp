class Solution {
public:



    string reverse(string s){
        int i=0;

        int j=s.length()-1;
           while(i<j){
                  swap(s[i],s[j]);
                  i++;
                  j--;
           }
          
      
        return s;
    }
    string invert(string str){
        for(int i=0;i<str.length();i++){
            if(str[i]=='0'){
                str[i]='1';
            }
            else{
                str[i]='0';
            }
        }
        return str;
    }
    string findString(int n,string &str){
        if(n<=1){
           return "0";
        }
        else{
            string prev = findString(n-1, str);
            str=prev+"1"+reverse(invert(prev));
        }

        return str;
    }
    char findKthBit(int n, int k) {
        string str="";
        string result=findString(n,str);
        return result[k-1];
    }
};
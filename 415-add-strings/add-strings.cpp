// class Solution {
// public:
//     string addStrings(string num1, string num2) {
//         int n1=stoi(num1);
//         int n2=stoi(num2);

//         int res=n1+n2;
//         return to_string(res);
//     }
// };

class Solution {
public:
    string addStrings(string num1, string num2) {
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        int n1=num1.size();
        int n2=num2.size();
        int n=max(n1,n2);
        int i=0;
        int j=0;
        int carry=0;

        string result="";
        while(i<n1 || j<n2 || carry){
             int add=0;
            if(i<n1 && j<n2){
             int e1=num1[i]-'0';
             int e2=num2[j]-'0';
             add=e1+e2+carry;
            }
            else if(j<n2){
                 int e2=num2[j]-'0';
                add=e2+carry;
            }
            else if(i<n1){
                int e1=num1[i]-'0';
                add=e1+carry;
            }
        
            else{
                add=carry;
            }     
            if(add>9){ 
            result.push_back((add % 10) + '0');
                carry=true;
            }
            else{
               result.push_back(add + '0');
                carry=false;   
            }
            carry=add/10;
            i++;
            j++;
        }
        reverse(result.begin(),result.end());
        return result;
    }
};
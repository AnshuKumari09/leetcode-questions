class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        auto parse=[](string s){
           int plus=s.find('+');
           int real=stoi(s.substr(0,plus));
           int imag=stoi(s.substr(plus+1,s.size() - plus - 2));
           return pair<int,int>(real,imag);
        };
        auto [a,b]=parse(num1);
        auto [c,d]=parse(num2);
        int real=a*c-b*d;
        int imag=a*d+b*c;
        return to_string(real)+"+"+to_string(imag)+"i";
    }
};
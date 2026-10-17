// class Solution {
// public:
//     string multiply(string num1, string num2) {
//         int number1=stoi(num1);
//         int number2=stoi(num2);
//         int multiply=number1*number2;
//         return to_string(multiply);
//     }
// };


// class Solution {
// public:
//     string multiply(string num1, string num2) {
//       int result=0;
//         reverse(num2.begin(),num2.end());
//         int numb1=stoi(num1);
//         for(int i=0;i<num2.length();i++){
//             result+=(numb1*(num2[i] - '0')*(pow(10, i)));
//         }

//       return to_string(result);
//     }
// };



// class Solution {
// public:
//     string multiply(string num1, string num2) {
//         int len1=num1.length();
//         int len2=num2.length();
//         vector<int>vec1;
//         vector<int>vec2;

//         for(int i=0;i<len1;i++){
//             int total=0;
//             int numb1=num1[i]-'0';
//             total+=numb1*(pow(10,len1-i-1));
//             vec1.push_back(total);
//         }

//         for(int i=0;i<len2;i++){
//             int total=0;
//             int numb1=num2[i]-'0';
//             total+=numb1*(pow(10,len2-i-1));
//             vec2.push_back(total);
//         }

//         long long res=0;
//         for(int i=0;i<vec1.size();i++){
//             for(int j=0;j<vec2.size();j++){
//                     res+=(vec1[i]*vec2[j]);
//             }
//         }
//         return to_string(res);
//     }
// };




class Solution {
public:
    string multiply(string num1, string num2) {
        int len1 = num1.length();
        int len2 = num2.length();

        if (num1 == "0" || num2 == "0") return "0";

        vector<int> vec(len1 + len2, 0);

        for (int i = len1 - 1; i >= 0; i--) {
            for (int j = len2 - 1; j >= 0; j--) {
                int numb1 = num1[i] - '0';
                int numb2 = num2[j] - '0';

                int product = numb1 * numb2;
                int sum = product + vec[i + j + 1];

                vec[i + j + 1] = sum % 10;
                vec[i + j] += sum / 10;
            }
        }

        string ans = "";
        for (int digit : vec) {
            if (!(ans.empty() && digit == 0)) {
                ans += to_string(digit);
            }
        }

        return ans;
    }
};

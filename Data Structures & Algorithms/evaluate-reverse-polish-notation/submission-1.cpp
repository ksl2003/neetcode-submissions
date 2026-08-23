class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(auto a: tokens){
            if(a!="+" && a!="-" && a!="*" && a!="/"){
                int num = stoi(a);
                s.push(num);
            }
            else{
                int num1 = s.top();
                s.pop();
                int num2 = s.top();
                s.pop();
                int result = 0;
                if(a=="+"){
                    result = num1 + num2;
                }
                else if(a=="-"){
                    result = num2 - num1;
                }
                else if(a=="*"){
                    result = num1*num2;
                }
                else{
                    result = num2/num1;
                }
                s.push(result);
            }
        }
        return s.top();
    }
};

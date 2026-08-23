class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto a: s){
            char presEle = a;
            if(presEle=='(' || presEle=='[' || presEle == '{'){
                st.push(presEle);
            }
            else{
                if(st.empty()){
                    return false;
                }
                char topEle = st.top();
                st.pop();

                if((topEle=='(' && presEle==')') || (topEle=='[' && presEle==']') || (topEle=='{' && presEle=='}')){
                    continue;
                }
                return false;
            }
        }
        if(st.empty()){
            return true;
        }
        return false;
    }
};

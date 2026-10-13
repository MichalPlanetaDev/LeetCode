class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> st;

        for (const string& token : tokens) {
            if (token != "+" && token != "-" && token != "*" && token != "/") {
                st.push_back(stoi(token));
                continue;
            }

            int b = st.back();
            st.pop_back();
            int a = st.back();
            st.pop_back();
            if (token == "+")
                st.push_back(a + b);
            else if (token == "-")
                st.push_back(a - b);
            else if (token == "*")
                st.push_back(a * b);
            else
                st.push_back(a / b);
        }

        return st.back();
    }
};
#include <iostream>
#include <stack>
#include <vector>

class Solution
{
public:
    int evalRpl(std::vector<std::string> &tokens)
    {
        if (tokens.size() == 0)
            return 0;

        std::stack<std::string> st;
        for (auto token : tokens)
        {
            if (token == "+")
            {
                int a = std::stoi(st.top());
                st.pop();
                int b = std::stoi(st.top());
                st.pop();
                int c = a + b;
                st.push(std::to_string(c));
            }
            else if (token == "-")
            {
                int a = std::stoi(st.top());
                st.pop();
                int b = std::stoi(st.top());
                st.pop();
                int c = b - a;
                st.push(std::to_string(c));
            }
            else if (token == "/")
            {
                int a = std::stoi(st.top());
                st.pop();
                int b = std::stoi(st.top());
                st.pop();
                int c = b / a;
                st.push(std::to_string(c));
            }
            else if (token == "*")
            {
                int a = std::stoi(st.top());
                st.pop();
                int b = std::stoi(st.top());
                st.pop();
                int c = a * b;
                st.push(std::to_string(c));
            }
            else
            {
                st.push(token);
            }
        }

        if (st.size() == 1)
            return std::stoi(st.top());
        else
            return 0;
    }
};

int main()
{
    std::vector<std::string> tokens = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    Solution s;
    std::cout << s.evalRpl(tokens);
    return 0;
}
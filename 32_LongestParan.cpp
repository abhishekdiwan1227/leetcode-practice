#include <iostream>
#include <stack>

class Solution
{
public:
    int longestValidParantheses(std::string s)
    {
        int len = 0;
        int lastOpenIndex = -1;
        if (s.length() == 0)
            return 0;
        std::stack<int> st;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
            {
                st.push(i);
                lastOpenIndex = i;
            }
            else if (!st.empty())
            {
                int openIndex = st.top();
                st.pop();
                if (openIndex < lastOpenIndex)
                    len = (i - openIndex) + 1;
                else
                    len += (i - openIndex) + 1;
            }
        }

        return len;
    }
};

int main()
{
    std::string s = "()(()())";
    Solution sol;
    std::cout << sol.longestValidParantheses(s);
    return 0;
}
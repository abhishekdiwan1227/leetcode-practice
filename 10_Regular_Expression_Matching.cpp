#include <iostream>
using namespace std;

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        if (s.empty() || p.empty())
            return false;
        int pCurr = 0, sCurr = 0;
        while (pCurr < p.length())
        {
            if ((pCurr + 1) < p.length() && p[pCurr + 1] == '*')
            {
                char last = p[pCurr];
                if (last == s[sCurr])
                    sCurr++;
                else
                    pCurr++;
            }
            else if (p[pCurr] == '*')
                pCurr++;
            else if (p[pCurr] == '.' && s[sCurr] != NULL)
            {
                pCurr++;
                sCurr++;
            }
            else if (s[sCurr] == p[pCurr])
            {
                pCurr++;
                sCurr++;
            }
            else
                return false;
        }
        if (sCurr == s.length())
            return true;
        else
            return false;
    }
};

int main()
{
    string s = "mississippi";
    string p = "mis*is*p*.....";

    // string s = "mississippi";
    // string p = "mis*is*p*.";
    // -> false

    Solution sol = Solution();
    cout << sol.isMatch(s, p);
    return 0;
}

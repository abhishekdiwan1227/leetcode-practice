#include <iostream>
using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        if (s.length() == 0 || s == "")
        {
            return "";
        }
        int currMax = 0, start = 0;
        for (int i = 0; i < s.length(); i++)
        {
            int len1 = expandFromCenter(s, i, i);
            int len2 = expandFromCenter(s, i, i + 1);
            int len = max(len1, len2);
            if (currMax < len)
            {
                currMax = len;
                if (len1 > len2)
                {
                    start = i - (len / 2);
                }
                else
                {
                    start = i - ((len - 1) / 2);
                }
            }
        }
        string toReturn = s.substr(start, currMax);
        return toReturn;
    }

private:
    int expandFromCenter(string s, int left, int right)
    {
        int length = 0;
        int l = left, r = right;
        while (l >= 0 && right < s.length() && s[l] == s[r])
        {
            if (l != r)
                length++;
            l--;
            r++;
        }
        int toReturn = length * 2;
        return left == right ? toReturn + 1 : toReturn;
    }
};

int main()
{
    Solution *sol = new Solution();
    string s = "gabccbae";
    cout << s + ": " + sol->longestPalindrome(s) << endl;
    s = "gabcbae";
    cout << s + ": " + sol->longestPalindrome(s) << endl;
    s = "abc";
    cout << s + ": " + sol->longestPalindrome(s) << endl;
    s = "cbbd";
    cout << s + ": " + sol->longestPalindrome(s) << endl;
    s = "babad";
    cout << s + ": " + sol->longestPalindrome(s) << endl;
}
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1)
            return s;

        vector<string> res = vector<string>(numRows, "");
        int i = 0;
        bool reverse = true;
        for (char c : s)
        {
            res[i] = res[i] + c;
            if (i == 0 || i == numRows - 1)
                reverse = !reverse;
            i = reverse ? --i : ++i;
        }

        string result = "";
        for (string s : res)
        {
            result = result + s;
        }

        return result;
    }
};

int main()
{
    string s = "PAYPALISHIRING";
    int numRows = 3;
    auto sol = new Solution();
    cout << sol->convert(s, numRows);
    return 0;
}
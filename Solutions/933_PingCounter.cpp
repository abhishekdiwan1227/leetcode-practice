#include <bits/stdc++.h>
class RecentCounter
{
public:
    RecentCounter()
    {
    }

    int ping(int t)
    {
        
    }

private:
    std::vector<int> bucket;
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
int main()
{
    auto times = {1, 100, 3001, 3002};
    RecentCounter *obj = new RecentCounter();
    for (auto t : times)
    {
        int param_1 = obj->ping(t);
        std::cout << param_1 << std::endl;
    }
}
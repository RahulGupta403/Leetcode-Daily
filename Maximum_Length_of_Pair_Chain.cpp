class Solution
{
public:
    static bool cmp(vector<int> a, vector<int> b)
    {
        if (a[1] < b[1])
        {
            return true;
        }
        return false;
    }
    int findLongestChain(vector<vector<int>> &pairs)
    {
        sort(pairs.begin(), pairs.end(), cmp);
        int count = 1;
        int prev = pairs[0][1];
        for (int i = 1; i < pairs.size(); i++)
        {
            if (pairs[i][0] > prev)
            {
                prev = pairs[i][1];
                count++;
            }
        }
        return count;
    }
};
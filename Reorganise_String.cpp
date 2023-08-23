class Solution
{
public:
    string reorganizeString(string s)
    {
        string ans = "";
        map<char, int> map;
        for (int i = 0; i < s.size(); i++)
        {
            map[s[i]]++;
        }
        priority_queue<pair<int, char>> pq;
        for (auto it : map)
        {
            pq.push({it.second, it.first});
        }
        pair<int, char> prev(-1, '@');
        while (!pq.empty())
        {
            pair<int, char> curr(pq.top().first, pq.top().second);
            pq.pop();
            ans += curr.second;
            curr.first--;
            if (prev.first > 0)
            {
                pq.push(prev);
            }
            prev = curr;
        }
        if (ans.length() != s.length())
        {
            return "";
        }
        else
            return ans;
    }
};
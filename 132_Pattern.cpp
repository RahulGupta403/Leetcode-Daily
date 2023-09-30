class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> st;
        int prev = INT_MIN;        
        for (auto it = nums.rbegin(); it != nums.rend(); it++) {
            while (!st.empty() && st.top() < *it) {
                if (prev > st.top())
                    return true;
                prev = st.top();
                st.pop();
            }            
            st.push(*it);
        }        
        return !st.empty() && prev > st.top();
    }
};

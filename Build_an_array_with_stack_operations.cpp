class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int current=1;
        for(int i=0;i<target.size();i++){
            int top=target[i];
            while(current<top){
                ans.push_back("Push");
                ans.push_back("Pop");
                current++;
            }
            ans.push_back("Push");
            current++;
        }
        return ans;
    }
};

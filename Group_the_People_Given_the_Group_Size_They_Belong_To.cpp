class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
       vector<vector<int>> ans;
       int n=groupSizes.size();
       unordered_map<int,vector<int>> map;
       for(int i=0;i<n;i++){
           map[groupSizes[i]].push_back(i);
           if(map[groupSizes[i]].size()==groupSizes[i]){
               ans.push_back(map[groupSizes[i]]);
               map[groupSizes[i]].clear();
           }
       }
       return ans; 
    }
};

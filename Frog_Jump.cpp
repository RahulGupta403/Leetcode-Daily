class Solution {
public:
    int n;
    unordered_map<int,int> map;
    int dp[2001][2001];
    int solve(vector<int> &stones,int curr_stone_idx,int prevJump){
        if(curr_stone_idx==n-1){
            return true;
        }
        bool result=false;
        if(dp[curr_stone_idx][prevJump]!=-1){
            return dp[curr_stone_idx][prevJump];
        }
        for(int nextJump=prevJump-1;nextJump<=prevJump+1;nextJump++){
            if(nextJump>0){
                int next_stone=stones[curr_stone_idx]+nextJump;
                if(map.find(next_stone)!=map.end()){
                    result=result or solve(stones,map[next_stone],nextJump);
                }
            }
        }
        return dp[curr_stone_idx][prevJump]=result;
    }
    bool canCross(vector<int>& stones) {
        n=stones.size();
        memset(dp,-1,sizeof(dp));
        if(stones[1]!=1){
            return false;
        }
        for(int i=0;i<n;i++){
            map[stones[i]]=i;
        }
        return solve(stones,map[0],0);
    }
};
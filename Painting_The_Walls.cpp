class Solution {
public:
    int n;
    int solve(int index,int remain,vector<int>& cost, vector<int>& time,vector<vector<int>>&dp){
        if(remain<=0){
            return 0;
        }
        if(index>=n){
            return 1e9;
        }
        if(dp[index][remain]!=-1){
            return dp[index][remain];
        }
        int paint=cost[index]+solve(index+1,remain-1-time[index],cost,time,dp);
        int no_paint=solve(index+1,remain,cost,time,dp);
        return dp[index][remain]=min(paint,no_paint);
    }
    int paintWalls(vector<int>& cost, vector<int>& time) {
        n=cost.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return solve(0,n,cost,time,dp);   
    }
};

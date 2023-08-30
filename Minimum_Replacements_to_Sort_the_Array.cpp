class Solution {
public:
    bool isSorted(vector<int> &nums){
        int n=nums.size();
        if(n==1){
            return true;
        }
        for(int i=1;i<n;i++){
            if(nums[i]>=nums[i-1]){
                continue;
            }else{
                return false;
            }
        }
    return true;
    }
    long long minimumReplacement(vector<int>& nums) {
        if(isSorted(nums)){
            return 0;
        }
        int n=nums.size();
        long long int ans=0;
        int prev=nums[n-1];
        for(int i=n-2;i>=0;i--){
            if(nums[i]>prev){
                long long int total_divide=(nums[i]-1)/prev;
                prev=nums[i]/(total_divide+1);
                ans+=total_divide;
            }else{
                prev=nums[i];
            }
        }
    return ans;
    }
};

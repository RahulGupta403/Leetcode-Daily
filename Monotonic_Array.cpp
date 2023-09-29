class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
       int n=nums.size();
       vector<int> temp(nums.begin(),nums.end());
       if(nums[0]>=nums[n-1]){
        sort(temp.begin(),temp.end(),greater<int>());
        if(nums==temp){
            return true;
        }else{
            return false;
        }
       }
       else if(nums[0]<=nums[n-1]){
        sort(temp.begin(),temp.end());
        if(nums==temp){
            return true;
        }else{
            return false;
        }
       }
       return true;
    }
};

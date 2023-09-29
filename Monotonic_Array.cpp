// Leetcode Easy Problem
// Approach - 01
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






// Approach - 02
class Solution {
public:
    bool isMonotonic(vector<int>& arr) {
       int n=arr.size();
        bool increase=true;
        bool decrease=true;
        for(int i=1;i<n;i++){
            if(arr[i]>arr[i-1]){
                increase=false;
            }
            if(arr[i]<arr[i-1]){
                decrease=false;
            }
        }
        return increase or decrease;
    }
};

class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int ans1=abs(fx-sx);
        int ans2=abs(fy-sy);
        if(ans1==0 and ans2==0){
           if(t==0){
            return true;
           }
        }
        if(ans1==0 and ans2==0){
           if(t==1){
            return false;
           }
        }
        return max(ans1,ans2)<=t;
    }
};

class Solution {
public:
    int countHomogenous(string s) {
        int mod=(int)1e9+7;
        int n=s.length();
        if(n==1){
            return 1;
        }
        else if(n==2){
            if(s[0]!=s[1]){
                return 2;
            }
            else{
                return 3;
            }
        }
        long long int ans=0;
        long long i=0;
        long long j=1;
        long long int count=1;
        while(j<n){
            if(s[i]==s[j]){
                j++;
                count++;
            }
            else if(s[i]!=s[j]){
                long long int ans1=(((count)*(count+1))/2)%mod%mod;
                ans=(ans+ans1)%mod%mod;
                i=j;
                j++;
                count=1;
            }
        }
        long long int ans1=(((count)*(count+1))/2)%mod%mod;
        ans=(ans+ans1)%mod%mod;
        return ans%mod%mod;
    }
};

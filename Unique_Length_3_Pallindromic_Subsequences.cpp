class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n=s.size();
        unordered_set<char>set;
        for(int i=0;i<n;i++){
            set.insert(s[i]);
        }
        int count=0;
        int size=set.size();
        for(int i=0;i<size;i++){
            char ch=*set.begin();
            int first_occ=-1;
            for(int i=0;i<n;i++){
                if(ch==s[i]){
                    first_occ=i;
                    break;
                }
            }
            int last_occ=-1;
            for(int j=n-1;j>=0;j--){
                if(ch==s[j]){
                    last_occ=j;
                    break;
                }
            }
            unordered_set<char> set1;
            if(last_occ!=-1 and first_occ!=-1){
                for(int k=first_occ+1;k<last_occ;k++){
                    set1.insert(s[k]);
                }
            }
            count+=set1.size();
            set.erase(set.begin());
        }
    return count;
    }
};

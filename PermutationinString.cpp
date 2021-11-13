class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length()>s2.length())return 0;
        vector<int> a(26,0);
        for(int i=0;i<s1.length();i++){
            a[s1[i]-'a']++;
        }
        int l=0,r=0,c=s1.length();
        while(r<s2.length()){
            if(a[s2[r++]-'a']-- >= 1) --c;
            if(c==0)return 1;
            if(r-l==s1.length() && a[s2[l++]-'a']++>=0) ++c;
        }
       return 0;  
    }
};

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(nullptr);
    }
    int lengthOfLongestSubstring(string s) {
        string tmp{""};
        int an{0};
        for (char c : s) {
            if (tmp.find(c)!=string::npos) {
                while(tmp.front()!=c){
                    tmp.erase (0,1);
                }
                tmp.erase (0,1);
            }
            tmp+=c;
            if (tmp.size()>an) an = tmp.size();    
        }
        return an;
    }
};

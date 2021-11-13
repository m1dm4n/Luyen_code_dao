class Solution {
public:
    string reverseWords(string s) {
        vector<string> arr;
        stringstream ss(s); //su dung stringstream de tach chu
        string a,ans;
        while (ss>> a) arr.push_back(a);
        for(int i = arr.size() - 1; i >= 0; --i) {
            if (i != arr.size() - 1) ans += " ";
            ans += arr[i];   
        }
        return ans;
    }
};

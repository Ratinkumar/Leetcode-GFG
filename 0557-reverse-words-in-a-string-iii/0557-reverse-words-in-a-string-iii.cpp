class Solution {
public:
    string reverseWords(string s) {
        stringstream str(s);
        string ans,temp;
        while(str >> temp)
        {
            reverse(temp.begin(),temp.end());
            ans+=(temp+" ");
        }
        //cout<<ans<<" ";
        return ans.substr(0,ans.size()-1);
    }
};
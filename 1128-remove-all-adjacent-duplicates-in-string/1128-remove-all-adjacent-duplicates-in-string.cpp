class Solution {
public:
    string removeDuplicates(string s) {
        string ans="";
        int index=0;
        while(index < s.length())
        {
            //if same means ans ka rightmost element and s ka current element
            if(ans.length() > 0 && ans[ans.length()-1] == s[index])
            {
                ans.pop_back();
            }
            else
            {
                ans.push_back(s[index]);
            }
            index++;
        }
        return ans;
    }
};
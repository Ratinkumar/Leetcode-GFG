class Solution {
public:
    int lengthOfLastWord(string s) {
        istringstream str(s);
        string word;
        vector<string>ans;

        while(str >> word)
        {
            ans.push_back(word);
        }
        return ans.back().length();
    }
};
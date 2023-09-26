class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n=s.size();
        int cnt[26]={0};
        int vis[26]={0};

        //store the count of each character
        for(int i=0;i<n;i++)
        { 
            cnt[s[i] - 'a']++;
        }

        string ans="";

        for(int i=0;i<n;i++)
        {
            //decreasing the count of character
            cnt[s[i] - 'a']--;

            //if character is not already in answer
            if(!vis[s[i] - 'a'] )
            {
                while(ans.size() > 0 && ans.back() > s[i] && cnt[ans.back() - 'a'] > 0)
                {
                    //mark letter unvisited
                    vis[ans.back() - 'a'] = 0;
                    ans.pop_back();
                }
                //add s[i] in ans and mark it visited
                ans += s[i];
                vis[s[i] - 'a'] = 1;
            }
        }
        return ans;
    }
};
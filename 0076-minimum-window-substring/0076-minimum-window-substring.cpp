class Solution {
public:
    string minWindow(string s, string t) {
        int len1=s.length();
        int len2=t.length();
        int start=0;
        if(len1 < len2)
        {
            return "";
        }

        int ansIndex=-1;
        int ansLen=INT_MAX;

        unordered_map<char,int>sMap;
        unordered_map<char,int>tMap;

        for(char ch:t)
        {
            tMap[ch]++;
        }

        int count=0;
        int e=0;
        while(e<s.length())
        {
            char ch=s[e];
            sMap[ch]++;

            if(sMap[ch] <= tMap[ch])
            {
                count++;
            }

            if(count==len2)
            {
                while(sMap[s[start]] > tMap[s[start]] || tMap[s[start]]==0)
                {
                    if(sMap[s[start]] > tMap[s[start]])
                    {
                        sMap[s[start]]--;
                    }
                    start++;
                }

                int windowLength=e-start+1;
                if(windowLength<ansLen)
                {
                    ansLen=windowLength;
                    ansIndex=start;
                }
            }
            e++;
        }
        if(ansIndex==-1)
        {
            return "";
        }
        else
        {
            return s.substr(ansIndex,ansLen);
        }
    }
};
class Solution {
public:
    int minimumPushes(string word) {
        vector<int>freq(26,0);
        for(char c:word)
        {
            freq[c-'a']++;
        }

        sort(freq.rbegin(),freq.rend()); //sort in descending order

        int totalpush=0,m=0;
        for(int i=0;i<26;i++)
        {
            if(i>=0 && i<8)
            {
                m=1;
            }
            else if(i>=8 && i<16)
            {
                m=2;
            }
            else if(i>=16 && i<24)
            {
                m=3;
            }
            else
            {
                m=4;
            }
            totalpush += m*freq[i];
        }
        return totalpush;
    }
};
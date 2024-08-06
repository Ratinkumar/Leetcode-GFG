class Solution {
public:
    int minimumPushes(string word) {
        vector<int>freq(26,0);
        for(char c:word)
        {
            freq[c-'a']++;
        }

        sort(freq.rbegin(),freq.rend()); //sort in descending order

        int totalpush=0;
        for(int i=0;i<26;i++)
        {
            totalpush=totalpush+(i/8 + 1) * freq[i];
        }
        return totalpush;
    }
};
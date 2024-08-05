class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int>m;
        for(auto &val:arr)
        {
            m[val]++;
        }

        for(auto val : arr)
        {
            if(m[val]==1)
            {
                k--;
            }
            if(k==0)
            {
                return val;
            }
        }
        return "";
    }
};
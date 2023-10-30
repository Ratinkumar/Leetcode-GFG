class Solution {
public:

    static bool compare(int a,int b)
    {
        int bitA=__builtin_popcount(a);
        int bitB=__builtin_popcount(b);

        if(bitA == bitB)
        {
            return a < b;
        }

        return bitA < bitB;
    }

    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),compare);
        return arr;
    }
};
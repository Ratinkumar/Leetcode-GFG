class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        int n = target.size();
        sort(target.begin(),target.end());
        sort(arr.begin(),arr.end());
        return arr == target;
    }
};
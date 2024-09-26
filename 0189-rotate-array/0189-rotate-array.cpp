class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k= k % nums.size();
        //step 1 : Rotate 0 to n-1
        reverse(nums.begin(),nums.end());

        //step 2: rotate 0 to k-1
        reverse(nums.begin(),nums.begin()+k);

        //step 3: rotate k to n-1
        reverse(nums.begin()+k,nums.end());
    }
};
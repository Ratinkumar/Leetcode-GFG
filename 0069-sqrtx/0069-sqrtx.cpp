class Solution {
public:
    int mySqrt(int x) {
        int start=0;
        int end=x;
        int ans=-1;
        while(start <= end)
        {
            long long int mid=start+(end-start)/2;
            if(mid*mid == x)
            return mid;
            else if(x > mid*mid)
            {
                ans=mid;
                start=mid+1;
            }
            else
            {
                end=mid-1;
            }
        }
        return ans;
    }
};
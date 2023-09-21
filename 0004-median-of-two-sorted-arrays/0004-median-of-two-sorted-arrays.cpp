class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();

        vector<int>ans;

        for(int i=0;i<n;i++)
        {
            ans.push_back(nums1[i]);
        }
        for(int i=0;i<m;i++){
            ans.push_back(nums2[i]);
        }
        
        sort(ans.begin(),ans.end());

        int count=ans.size();
        if(count % 2 ==1)//if the count is odd return the middle element as the median
        {
            return static_cast<double>(ans[count / 2]);
        }
        else
        {   
            //if the count is even,return the average of the two middle element as the median
            int mid1=ans[count / 2 -1];
            int mid2=ans[count / 2];
            return (static_cast<double>(mid1) + static_cast<double>(mid2)) / 2.0;
        }
    }
};
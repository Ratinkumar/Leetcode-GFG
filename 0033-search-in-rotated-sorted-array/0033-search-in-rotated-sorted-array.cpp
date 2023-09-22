class Solution {
public:

    int findpivotIndex(vector<int>& nums)
    {
        int n=nums.size();
        int start=0;
        int end=nums.size()-1;
        while(start <= end)
        {
            int mid=start+(end-start)/2;
            //corner case
            if(start==end)
            return start;
            else if(mid+1 < n && nums[mid] > nums[mid+1])
            return mid;
            else if(mid-1 >=0 && nums[mid] < nums[mid-1])
            return mid-1;
            else if(nums[start] > nums[mid])
            end=mid-1;
            else
            start=mid+1;
        }
        return -1;
    }

    int binarySearch(vector<int>& arr,int start,int end,int target)
    {
        while(start <= end)
        {
            int mid=start+(end-start)/2;
            if(arr[mid]==target)
            return mid;
            else if(target > arr[mid])
            start=mid+1;
            else
            end=mid-1;
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
       int pivotindex=findpivotIndex(nums);
        int n=nums.size();
        int ans=-1;
       //search in A
       if(target >= nums[0] && target <= nums[pivotindex])
       {
           ans= binarySearch(nums,0,pivotindex,target);
       }
       else
       {
           ans= binarySearch(nums,pivotindex+1,n-1,target);
       }
       return ans;
    }
};
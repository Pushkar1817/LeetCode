class Solution {
private:
    int binarySearch(vector<int>&nums, int target, int st, int ed){
        int mid = st + (ed-st)/2;
        while(st <= ed){
            mid = st + (ed-st)/2;
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] > target){
                ed = mid-1;
            }
            else{
                st = mid + 1;
            }
        }
        return -1;
    }
public:
    int search(vector<int>& nums, int target) {
        
        int pivot = 0 ;

        for(int i = 0 ;i< nums.size() ;i++){
            if(nums[i] < nums[pivot]){
                pivot = i;
            }
        }
        int bef = binarySearch(nums,target,0,pivot);
        int aft = binarySearch(nums,target,pivot,nums.size()-1);
        return bef == -1 ? aft:bef;
    }
};
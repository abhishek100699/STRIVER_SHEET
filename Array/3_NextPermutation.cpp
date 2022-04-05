class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // find the point of infletion
        int n = nums.size()-1;
        int i=0;
        for(i=n;i>0;i--){
            if(nums[i]>nums[i-1]){
                break;
            }
        }
        if(i<=0){
            sort(nums.begin(),nums.end());
            return ;
        }
        // finf any number which is grater than nums[i-1] and swap
        for(int j = n;j>=0;j--){
            if(nums[j]>nums[i-1]){
                swap(nums[j],nums[i-1]);
                sort(nums.begin()+i,nums.end());
                break;
            }
        }
    
    }
};

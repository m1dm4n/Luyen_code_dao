class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int ind1 = 0; // dùng dò số khác 0;
        int ind2 = 0; // thằng này thì sẽ dừng ở các vị trí = 0 để đổi với ind 1
        while(ind1<nums.size())
        {
            if(nums[ind1]!=0)
            {
                nums[ind2] = nums[ind1];
                ind1++;
                ind2++;
            }
            else
            {
                ind1++;
            }
        }
        while(ind2<nums.size())
        {
            nums[ind2] = 0;
            ind2++;
        }
    }
};

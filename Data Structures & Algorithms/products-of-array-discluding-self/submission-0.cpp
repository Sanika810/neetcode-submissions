class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> rightProd(n,1);
        int leftProd = 1;
        for(int i=n-1;i>0;i--)
        {
            rightProd[i-1]=rightProd[i]*nums[i];
        }
        vector<int>ans(n);
        for(int i=0;i<n;i++)
        {
            ans[i] = leftProd * rightProd[i];
            leftProd = leftProd * nums[i];
        }
        return ans;
    }
};

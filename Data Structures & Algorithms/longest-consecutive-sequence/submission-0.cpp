class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st;
        for(int num : nums)
            st.insert(num);
        int cnt ;
        int maxi = 0;
        for(int num : nums)
        {
            if(st.find(num - 1) != st.end())
                continue;
            cnt = 1;
            while(st.find(num + 1) != st.end())
            {
                num = num + 1;
                cnt = cnt + 1;
            }
            maxi = max(maxi , cnt);
        }
        return maxi;
    }
};

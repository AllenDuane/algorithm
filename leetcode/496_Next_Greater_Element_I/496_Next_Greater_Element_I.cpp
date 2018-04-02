class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {

        vector<int> res;
        for(int i=0;i<findNums.size();i++)
        {
            res.push_back(getElement(findNums[i],nums));
        }

        return res;

    }


    int getElement(int x,vector<int>& nums){
        int res=-1;

        for(int i=getIndex(x,nums)+1;i<nums.size();i++){
            if(nums[i]>x){
                res=nums[i];
                break;
            }
        }

        return res;
    }

    int getIndex(int x,vector<int>& nums){
        int res=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==x){
                res=i;
                break;
            }
        }

        return res;
    }
};

#include <vector>
#include <climits>

using namespace std;

class Solution {
public:

    int maxSubArray(vector<int>& nums) {
        int maxNums = nums[0];
        int result = nums[0];
        if(nums.size()==1) return result;
        int maxMemoIdx = -1;
        int maxMemo = INT_MIN;
        vector<int> numsDupVec;

        
        //iterate through vector
        //create memo based on the size of the vector
        //find greatest memos and indexes - hash map

        vector<int> memo(nums.size());
        memo[0] = nums[0];
        for(int i=1; i<nums.size(); i++){
            memo[i] = nums[i]+memo[i-1];
            if(nums[i]>=maxNums) {
                maxNums = nums[i];
                if(!numsDupVec.empty()){
                    if(nums[numsDupVec[0]] < nums[i]){
                        numsDupVec.clear();
                    }
                }
                numsDupVec.push_back(i);
            }
            if(memo[i] >= maxMemo) {
                maxMemo=memo[i];
                maxMemoIdx = i;
            }
        }

        //iterate nums and subtract from maxMemo up to maxMemoIdx (including)
        //update result with biggest memo
        result = maxMemo;
        for(int i=0; i<maxMemoIdx; i++){
            maxMemo -= nums[i];
            if(result < maxMemo) result = maxMemo;
        }

        //go through each duplicate memo
        int dupIdx;
        int numsPtr = 0;
        int dupMemo = memo[dupIdx];
        int maxDupMemo = INT_MIN;
        int memoOrigin = 0;
        for(int i=0; i<numsDupVec.size(); i++){
            dupIdx = numsDupVec[i];
            dupMemo = memo[dupIdx]-memoOrigin;
            if(maxDupMemo<dupMemo) maxDupMemo = dupMemo;
            while(numsPtr<=dupIdx){
                dupMemo -= nums[numsPtr];
                if(maxDupMemo<dupMemo) maxDupMemo = dupMemo;
                numsPtr++;
            }
            memoOrigin = memo[dupIdx];
        }
        
        //return the grester one maxNums, result, and maxDupMemo
        if(maxNums > result) result = maxNums;
        if(maxDupMemo > result && maxNums > 0) result = maxDupMemo;
        
        return result;
    }
};

int main(){
    Solution sol1;
    vector<int> input1 = {-1,6,7,-7,-2,-6,-1,3,4,2,6,-3,-8,-1,7};
    sol1.maxSubArray(input1);

    return 0;
}
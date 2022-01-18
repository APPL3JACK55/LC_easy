#include <vector>

using namespace std;

int removeElement(vector<int>& nums, int val) {
    int found = 0;
    int original = nums.size();
    
    //iterate through vector
    //if vector value equals val then swap with last element and increase found value
    for(int i=0; i<nums.size(); i++){
        if(nums[i] == val){
            found++;
            nums.erase(nums.begin()+i);
            i = i-1;
        }
    }
    return (nums.size() - found);
}

int main(void){
    vector<int> input = {3,2,2,3};
    removeElement(input, 3);

    return 0;
}
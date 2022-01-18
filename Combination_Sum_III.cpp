#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> solution;
    vector<int> v1;
    vector<vector<int>> combinationSum3(int k, int n){
        if (k == 1)
        {
            for(int i = 1; i < 10; i++){
                if((n-i) == 0){
                    v1.push_back(i);
                    solution.push_back(v1);
                    v1.pop_back();
                }
            }
            return solution;
        }
        for(int i = 1; i < 10; i++){
            v1.push_back(i);
            recurAdd(i, k-1, n-i);
            v1.pop_back();
        }
        
        return solution;
    }

    void recurAdd(int i, int k, int rem){
        if(k == 0){
            if(rem == 0){
                solution.push_back(v1);
            }
            return;
        }
        else if(rem <= 0){
            return;
        }

        for(int j = i+1; j < 10; j++)
        {
            v1.push_back(j);
            recurAdd(j, k-1, rem-j);
            v1.pop_back();
        }
    }
};

int main(){
    Solution test;
    test.combinationSum3(3, 9);
    return 0;
}
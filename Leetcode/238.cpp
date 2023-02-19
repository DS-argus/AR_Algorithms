#include <iostream>
#include <vector>

using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {

    vector<int> result;

    if  (count(nums.begin(), nums.end(), 0) >= 2){
        for (auto i: nums){
            result.push_back(0);
        }
    }else if (count(nums.begin(), nums.end(), 0) == 1){
        
        int val = 1;

        for (auto i : nums){
            if (i != 0){
                val *= i;
            }
        }

        for (auto i : nums){
            if (i != 0){
                result.push_back(0);
            }else{
                result.push_back(val);
            }
        }
    }else{
        int val = 1;

        for (auto i : nums){
            val *= i;
        }

        for (auto i : nums){
            result.push_back(val/i);
        }
    }
    return result;
    
}

int main(){
    vector<int> nums {1, 2, 3, 4};

    vector<int> result = productExceptSelf(nums);

    for (auto i: result){
        cout << i << endl;
    }
}
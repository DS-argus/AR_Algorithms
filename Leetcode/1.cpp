#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> result;
    unordered_map<int, int> store;

    for(int i = 0; i < nums.size(); i++){

        int compliment = target - nums[i];
        
        if  (store.count(compliment)){
            result.push_back(store[compliment]);
            result.push_back(i);
            break;

        }else{
            store[nums[i]] = i; 
       }
    }
    return result;
}

int main(){
    vector<int> nums {2, 7, 11, 15};
    int target = 9;

    for (auto i: twoSum(nums, target))
    {
        cout << i << endl;
    }
    
}
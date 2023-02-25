#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    
    vector<vector<int>> result;

    sort(nums.begin(), nums.end());

    for(int i = 0; i < nums.size(); i++){
        if (i > 0 && nums[i] == nums[i-1]){
            continue;
        }

        // two sum from now on
        int l = i + 1;
        int r = nums.size()-1;

        while (l < r){
            int threesum = nums[i] + nums[l] + nums[r]; 

            if (threesum == 0){
                result.push_back({nums[i], nums[l], nums[r]});
                l++;
                while(nums[l] == nums[l-1] && l < r){
                    l++;
                }
            }else if(threesum > 0){
                r--;
            }else{
                l++;
            }
        }
    }

    return result;
}

int main(){
    vector<int> nums {-1, 0, 1, 2, -1, -4};

    vector<vector<int>> result = threeSum(nums);

    for(auto i: result){
        for (auto j: i){
            cout << j << " ";
        }
        cout << endl;
    }
}
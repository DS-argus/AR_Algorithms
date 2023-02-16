#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool containsDuplicate(vector<int>& nums) {
    unordered_map<int, bool> store;

    for(int i = 0; i < nums.size(); i++){
        if(store.count(i)){
            return true;
        }else{
            store.insert(make_pair(i, true));
        }
    }
    return false;
}

int main(){
    vector<int> nums = { 1,2,3,4 };

    cout << boolalpha << containsDuplicate(nums) << endl;

}
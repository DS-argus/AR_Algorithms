#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <unordered_set>

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

//slower
bool containsDuplicate2(vector<int>& nums) {
    set<int> store;

    for(auto i: nums){
        if(store.count(i) == 1){
            return true;
        }else{
            store.insert(i);
        }
    }
    return false;
}

bool containsDuplicate3(vector<int>& nums) {
    unordered_set<int> store;

    for(auto i: nums){
        if(store.count(i) == 1){
            return true;
        }else{
            store.insert(i);
        }
    }
    return false;
}

int main(){
    vector<int> nums = { 1,2,3,1 };
    cout << "using unordered_set" << endl;
    cout << boolalpha << containsDuplicate3(nums) << endl;
}
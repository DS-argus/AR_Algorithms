#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>

using namespace std;


vector<int> topKFrequent(vector<int>& nums, int k) {
    
    // for result
    vector<int> result;

    // unordered_map is faster than map here
    unordered_map<int, int> store;

    for (auto i: nums){
        if (store.count(i)){
            store[i]++;
        }else{
            store[i] = 1;
        }
    }

    // drop duplicates
    set<int> values;

    for (auto i: store){
        values.insert(i.second);
    }

    vector<int> v;
    int tempint = 0;

    for (auto i: values){
        v.push_back(i);
        
        // to store only k values
        tempint++;
        if (tempint == k){
            break;
        }
    }

    // to sort by key (ascending order)
    map<int, vector<int>> mp;

    for (auto i: store){
        if (mp.count(i.second)){
            mp[i.second].push_back(i.first);
        }else{
            vector<int> temp {i.first};
            mp[i.second] = temp;
        }
    }

    tempint = 0;
    for (auto iter = mp.rbegin(); iter != mp.rend(); ++iter){
        vector<int> temp = iter->second;
        for (auto i: temp){
            result.push_back(i);
            tempint++;
        }

        // when frequency is the same,
        if (tempint == k){
            break;
        }
    }

    return result;
}


int main(){
    vector<int> nums{4, 1, -1, 2, -1, 2, 3};

    vector<int> result = topKFrequent(nums, 2);

    for(auto i: result){
        cout << i << endl;
    }
}
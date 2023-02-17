#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {

    vector<vector<string>> result;

    unordered_map<string, vector<string>> store;

    for (auto i : strs){
        
        // copy i to key
        string key = i;

        // sorting key to use it as a hash value
        sort(key.begin(), key.end());

        
        if (store.count(key)){

            store[key].push_back(i);

        }else{
            vector<string> value{i};
            store[key] = value;
        }
    }

    for (auto i : store){
        result.push_back(i.second);
    }

    return result; 
}


int main(){
    vector<string> strs{"eat","tea","tan","ate","nat","bat"};

    vector<vector<string>> result = groupAnagrams(strs);

    for (auto i: result)
    {
        for (auto j: i)
        {
            cout << j << endl;
        }
        
    }    
}
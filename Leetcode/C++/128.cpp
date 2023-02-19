#include <iostream>
#include <map>
#include <vector>
#include <unordered_set>

using namespace std;

int longestConsecutive(vector<int>& nums) {

    map<int, int> store;

    if (nums.size() == 0) return 0;

    for (auto i: nums){
        store[i] = 1;
    }

    vector<int> sorted;

    for (auto i: store){
        sorted.push_back(i.first);
    }

    vector<int> resultVector;
    int result = 1;
    for (int i = 1; i < sorted.size(); i++){
        if  (sorted[i] == sorted[i-1] + 1){
            result++;
        }
        else{
            resultVector.push_back(result);
            result = 1;
        }
    }

    resultVector.push_back(result);

    int max = resultVector[0];
    for (auto i: resultVector){
        if (i > max) max = i;
    }

    return max;
}


int longestConsecutive2(vector<int> &num) {
    unordered_set<int> record(num.begin(),num.end());
    int res = 0;
    for(int n : num){
        if(record.find(n)==record.end()) continue;
        record.erase(n);
        int prev = n-1,next = n+1;
        while(record.find(prev)!=record.end()) record.erase(prev--);
        while(record.find(next)!=record.end()) record.erase(next++);
        res = max(res,next-prev-1);
    }
    return res;
}


int main(){
    vector<int> nums{100, 4, 200, 1, 3, 2};

    cout << longestConsecutive(nums) << endl;
}
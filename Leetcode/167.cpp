#include <iostream>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {

    int l = 0;
    int r = numbers.size() -1;

    while(l < r){
        if(numbers[l] + numbers[r] == target){
            
            return {l+1,r+1};;
        }
        else if(numbers[l] + numbers[r] > target){
            r--;
        }
        else{
            l++;
        }
    }
    return {};
}

int main(){
    vector<int> numbers {2, 7, 11, 15};

    vector<int> result = twoSum(numbers, 9);

    for (auto i: result){
        cout << i << endl;
    }
}


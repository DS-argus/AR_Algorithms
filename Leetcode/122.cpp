#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int>& prices) {
    int L = 0;
    int R = 1;

    int max = 0;

    while(L < prices.size()-1){
        if(prices[L] >= prices[R]){
            L = R;
            R = L+1;
        }else if(prices[R]-prices[L] > 0){
            max = max + prices[R]-prices[L];
            L = R;
            R = L + 1;
        }
    }
    return max;
}

int main(){
    vector<int> prices{7, 1, 5, 4, 3, 6};

    cout << maxProfit(prices) << endl;
}

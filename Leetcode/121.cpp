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
                continue;

            }else if(prices[R]-prices[L] > max){
                max = prices[R]-prices[L];
            }

            if(R==prices.size()-1){
                L++;
                R = L + 1;
            }else{
                R++;
            }
        }
        return max;

    }

    int main(){
        vector<int> prices{7, 1, 5, 3, 6, 4};

        cout << maxProfit(prices) << endl;
        
    }
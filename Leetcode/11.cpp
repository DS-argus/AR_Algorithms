#include <iostream>
#include <vector>
using namespace std;

int maxArea(vector<int>& height) {
    int l = 0;
    int r = height.size() - 1;

    int max = 0;

    while(l < r){
        int width = r - l;
        int area;

        if (height[l] > height[r]){
            area = width * height[r];

            if (area > max) max = area;

            r--;

        }else{
            area = width * height[l];

            if (area > max) max = area;

            l++;
        }
    }
    return max;
}

int main(){

    vector<int> height {1, 8, 6, 2, 5, 4, 8, 3, 7};

    cout << maxArea(height) << endl;
}
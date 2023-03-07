#include <iostream>
#include <string>
using namespace std;

int lengthOfLongestSubstring(string s) {
    int result = 0;
    int l = 0;
    int r = 1;

    while(r <= s.size()){
        string substring = s.substr(l, r-l);

        if(r == s.size()){
            if (substring.size() > result){
                result = substring.size();
            }
            break;

        }else if(substring.find(s[r]) != std::string::npos){
            if (substring.size() > result){
                result = substring.size();
            }
            l = l + 1;

        }else{
            r = r + 1;
        }
    }

    return result;
}

int main(){
    string s = "abcabcbb";

    cout << lengthOfLongestSubstring(s) << endl;
    
}
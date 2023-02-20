#include <iostream>
using namespace std;

bool isPalindrome(string s) {
    for (int i = 0; i < s.size(); i++){

        if (!((48 <= int(s[i]) && int(s[i]) <= 57) || (97 <= int(s[i]) && int(s[i]) <= 122) || (65 <= int(s[i]) && int(s[i]) <= 90))){
            s[i] = ' ';
        }

        if (65 <= int(s[i]) && int(s[i]) <= 90){
            s[i] = (int(s[i]) + 32);
        }
    }

    s.erase(remove(s.begin(), s.end(), ' '), s.end());
    
    for (int i = 0; i < s.size() / 2; i++){
        if (s[i] != s[s.size() - 1 - i]){
            return false;
        }
    }
    return true;
}

 
int main(){
    string s = "A man, a plan, a canal: Panama";

    cout << boolalpha << isPalindrome(s) << endl;

}
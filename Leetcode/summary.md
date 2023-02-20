1. Contains Duplicate `217.cpp`
    * **hash** 사용하지 않으면 찾는 과정에서 시간초과 발생
    * **boolalpha** : true or false로 프린트하기 위함
    * `set<int>`로 구현하면 더 느림 : set은 이진트리로 저장 
    * `unordered_set<int>`로 구현하면 set보단 빠르지만 unordered_map 보다 느림 --> collision 때문에?
---
2. Valid Anagram `242.cpp`
    * `std::sort(s.begin(), s.end())` 사용해서 정렬 후 같은지 체크, 속도는 느리지만 메모리 효율적 -> **<mark>O(nlogn)</mark>** by quick sort
    * `unordered_map` 으로 구현한건 속도는 더 빠르나 메모리 큼
    * `#include <algorithm>` 안했는데 sort 사용가능. sort.h에 있다고 나오는데?
        * https://stackoverflow.com/questions/49760728/i-dont-use-algorithm-header-but-sort-is-available
---
3. Two Sum `1.cpp`
    * `unordered_map` 사용. compliment의 index를 저장해 놓고 hash로 빠르게 search
---
4. Group Anagram `49.cpp`
    * `string` 을 새로운 변수명에 할당하면 복사됨(깊은 복사)
    * <mark>`unordered_map`의 범위 기반 for loop은 `i.first, i.second로` 접근가능</mark>
---
5. Top K Frequent Elements `347.cpp`
    * 눈물의 똥꼬쇼...
    * **unordered_map** : 단순히 저장만 할 때는 map보다 빠름
    * **map** : 순서정렬 위해 사용
    * **set** : 중복제거 위해 사용
    * <mark>**`for (auto iter = mp.rbegin(); iter != mp.rend(); ++iter)` : 역순으로 for loop 돌 때 활용**</mark>
    * **`priority_queue<pair<int,int>>pq`** 를 사용하면 편함
        * pair<int, int>는 앞에서부터 대소 비교
        * priority_queue는 큰 값이 위에 저장
---
6. Product of Array Except Self `238.py`, `238.cpp`
    * 0이 2개 이상인 경우 / 0이 1개인 경우 / 0이 없는 경우로 나눠서 해결
    * C++ 도 동일한 로직으로 작성
        * <mark>C++ vector에서 원소 개수 셀 때 count 사용 : `count(nums.begin(), nums.end(), 0)`. python에서 `nums.count(0)`과 동일</mark>
    * division을 사용안하면 dynamic programming으로 왼쪽 곱, 오른쪽 곱을 각각 리스트에 담아서 곱해주는 방법 사용 
        * python : time O(n), space O(1)
            ``` python
                def productExceptSelf(self, nums):
                    n, ans, suffix_prod = len(nums), [1]*len(nums), 1
                    for i in range(1,n):
                        ans[i] = ans[i-1] * nums[i-1]
                    for i in range(n-1,-1,-1):
                        ans[i] *= suffix_prod
                        suffix_prod *= nums[i]
                    return ans
            ```
---
7. Longest Consecutive Sequence `128.cpp`
    * 내 방법 : 빈 vector 입력되면 0 반환 --> map에 key로 저장해서 정렬 : O(log(n)) -->result 변수에 연속한 숫자 개수를 담고 끊기면 resultVector에 저장. resultVector에서 최댓값 찾기
    * 좋은 방법 : set과 while문을 이용해서 찾는 방법 -> faster!
---
8. Valid Palindrome `125.cpp`
    * 나는 ascii 코드표 보고 노가다. isalnum, toupper, two pointer 몰랐음
    * `int isalnum(int c)` : 숫자 혹은 알파벳인지 체크
        * 자매품 : `int isdigit(int c)` 숫자여부 체크, `int isalpha(int c)` 알파벳 여부 체크
    * **<mark>Two pointer `for (int i = 0, j = s.size() - 1; i < j; i++, j--)`  : i와 j가 양끝에서 시작해서 만날 때까지 진행</mark>**
    ```C++
        bool isPalindrome(string s) {
            for (int i = 0, j = s.size() - 1; i < j; i++, j--) { // Move 2 pointers from each end until they collide
                while (isalnum(s[i]) == false && i < j) i++; // Increment left pointer if not alphanumeric
                while (isalnum(s[j]) == false && i < j) j--; // Decrement right pointer if no alphanumeric
                if (toupper(s[i]) != toupper(s[j])) return false; // Exit and return error if not match
            }
    
           return true;
        }
    ```
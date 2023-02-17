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

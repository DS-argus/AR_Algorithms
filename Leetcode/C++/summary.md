1. Contains Duplicate `217.cpp`
    * **hash** 사용하지 않으면 찾는 과정에서 시간초과 발생
    * **boolalpha** : true or false로 프린트하기 위함
    * `set<int>`로 구현하면 더 느림 : set은 이진트리로 저장 
    * `unordered_set<int>`로 구현하면 set보단 빠르지만 unordered_map 보다 느림 --> collision 때문에?

2. Valid anagram `242.cpp`
    * `std::sort(s.begin(), s.end())` 사용해서 정렬 후 같은지 체크, 속도는 느리지만 메모리 효율적 -> **<mark>O(nlogn)</mark>** by quick sort
    * `ordered_map` 으로 구현한건 속도는 더 빠르나 메모리 큼
    * `#include <algorithm>` 안했는데 sort 사용가능. sort.h에 있다고 나오는데?
        * https://stackoverflow.com/questions/49760728/i-dont-use-algorithm-header-but-sort-is-available

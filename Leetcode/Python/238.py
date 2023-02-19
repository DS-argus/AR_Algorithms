def productExceptSelf(nums: list[int]) -> list[int]:
    result = []
    
    if nums.count(0) >= 2:
        result = [0] * len(nums)
    
    elif nums.count(0) == 1:
        # get mul except 0
        val = 1
        for i in nums:
            if i != 0:
                val *= i

        for i in nums:
            if i!= 0:
                result.append(0)
            else:
                result.append(val)
        
    else:
        val = 1
        for i in nums:
            val *= i
        
        for i in nums:
            result.append(int(val / i))
    
    return result

if __name__ == "__main__":
    nums = [1, 2, 3, 4]
    print(productExceptSelf(nums))
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        # Prefix & Postfix method: Time: O(n), Space: O(n)
        prod_array = [1]*len(nums)
        prefix = 1
        postfix = 1
        for i in range(len(nums)-1):
            prefix *= nums[i]
            prod_array[i+1] = prefix 
        for i in range(len(nums)-1, -1, -1):
            prod_array[i] *= postfix
            postfix *= nums[i]
        return prod_array
        
        # # Brute force -> Time: O(n^2), Space: O(1)
        # prod_array = []
        # for i in range(len(nums)):
        #     prod = 1
        #     for j in range(len(nums)):
        #         if i != j:
        #             prod *= nums[j]
        #     prod_array.append(prod)
        # return prod_array

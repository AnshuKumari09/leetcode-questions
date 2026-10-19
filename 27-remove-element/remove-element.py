class Solution:
    def removeElement(self, nums: list[int], val: int) -> int:
        lists=[]
        for it in nums:
            if it!=val:
                lists.append(it)
        nums[:]=lists

        return len(lists)

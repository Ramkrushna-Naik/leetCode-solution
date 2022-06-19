class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        n=nums1[:]+nums2[:]
        n.sort()
        if(len(n)%2==0):
            a=n[int(len(n)/2)-1]
            b=n[int(len(n)/2)]
            return (a+b)/2
        else:
            return n[int(len(n)/2)]
        
        
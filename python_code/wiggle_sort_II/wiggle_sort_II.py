#!/usr/bin/env python3

def findMedian(nums):
    median = 0
    nextLeft, nextRight = 0
    for num in nums:
        if median == num:
            



# For odd len [1,5,7,2,1]
# Start with three [1, 5, 7]
# median =   1, left = 1, right = 1
# median =   3, left = 1, right = 5
# median =   5, left = 1, right = 7
# median = 3.5, left = 1, right = 7
#
#
#


def main(void):
    findMedian([1,5,7,2,1])

    return 0;

if __name__ == "__main__":
    main()

print("Hello")

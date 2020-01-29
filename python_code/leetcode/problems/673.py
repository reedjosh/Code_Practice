"""
    problems/673.py

    Longest increasing subsequence.
"""
from collections import defaultdict
from itertools import chain
from typing import List


class Solution:
    def findNumberOfLIS(self, nums: List[int]) -> int:

        def append_if(max_subseqs, subsequences, subseq):
            """ Only add to the list of subsequences if this sequnce's length is >= others in list.
                Assumes others subseqeunces are all the same length. """
            if subsequences:
                if (len(subseq) == len(subsequences[0])):
                    subsequences.append(subseq)
                elif (len(subseq) > len(subsequences[0])):
                    subsequences = [subseq]
            else:
                subsequences = [subseq]
            if max_subseqs:
                if (len(subseq) == len(max_subseqs[0])):
                    max_subseqs.append(subseq)
                elif (len(subseq) > len(max_subseqs[0])):
                    max_subseqs = [subseq]
            else:
                max_subseqs = [subseq]
            return max_subseqs, subsequences
                

        subseqs_seen = defaultdict(list)
        max_len = 0
        max_subseqs = []
        for num in nums:
            max_subseqs, subseqs_seen[num] = append_if(max_subseqs, subseqs_seen[num], (num,))
            for final_seq_num in subseqs_seen.keys():
                if final_seq_num < num:
                    new_subseqs = [tuple(chain(subseq + (num,))) for subseq in subseqs_seen[final_seq_num]]
                    for subseq in new_subseqs:
                        max_subseqs, subseqs_seen[num] = append_if(max_subseqs, subseqs_seen[num], subseq)

        return len(max_subseqs)


if __name__ == "__main__":
    print('Should be: 2')
    print(Solution().findNumberOfLIS([1,3,5,4,7]))
    #print(Solution().findNumberOfLIS([1,2]))

    print('Should be: 5')
    print(Solution().findNumberOfLIS([2,2,2,2,2]))

    print('Should be: 3')
    print(Solution().findNumberOfLIS([1,2,4,3,5,4,7,2]))

    print('Should be: 3')
    print(Solution().findNumberOfLIS([1,9,4,3,5,4,7,2]))

    print(Solution().findNumberOfLIS([12,65,55,-84,-34,26,46,40,52,52,78,16,8,-25,7,-65,15,8,33,-83,53,20,21,-55,2,-54,-71,1,73,36,-15,26,95,25,36,35,18,8,41,90,9,-40,96,84,-46,52,89,17,21,-33,49,95,97,82,-70,50,44,36,42,-47,43,83,13,-61,27,95,57,3,17,30,56,9,89,-63,-48,16,57,59,27,56,-41,48,94,85,51,61,-60,45,12,90,11,30,43,-88,97,68,88,50,80,58,-88,73,-56,89,36,20,3,-29,27,73,30,21,98,22,97,-4,-36,-20,82,45,84,53,-25,-28,47,25,56,-20,-5,68,98,10,33,70,-65,15,-46,60,71,48,-90,81,17,-75,1,43,-61,56,-35,94,64,85,12,99,89]))

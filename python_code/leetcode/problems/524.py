"""
    problems/524.py

    Longest word in dictionary through deletion.
"""
from typing import List
from collections import deque, namedtuple, defaultdict

class Solution:
    def findLongestWord(self, s: str, d: List[str]) -> str:
                
        def w1_in_w2(word1, word2):
            idx = 0
            match_cnt = 0
            for char in word2:
                while idx < len(word1) and char != word1[idx]:
                    idx += 1
                if idx < len(word1) and char == word1[idx]:
                    match_cnt += 1
                idx += 1
            #print('w1', word1, 'w2', word2, match_cnt)
                
            return match_cnt == len(word2)
           
        hits = [] 
        max_word = ""
        for word in d:
            if len(word) > len(max_word):
                if w1_in_w2(s, word):
                    max_word = word
            elif len(word) == len(max_word):
                if w1_in_w2(s, word):
                    max_word = sorted([max_word, word])[0]
    
        return max_word
            
# Found this algorithm via comments in the leetcode solutions page.
# It was described here: https://techdevguide.withgoogle.com/paths/foundational/find-longest-word-in-dictionary-that-subsequence-of-given-string/#
class Solution:
    def findLongestWord(self, s: str, d: List[str]) -> str:
        matching = defaultdict(deque)

        # Initialize the dictionary of words by char.
        for word in d:
            matching[word[0]].append((word, 0))

        max_hit = ""

        considering = deque()
        for char in s:
            while matching[char]:
                considering.append(matching[char].pop())
            while considering:
                word, cnt = considering.pop()
            
                new_idx = cnt + 1

                if new_idx == len(word):
                    max_hit = min(max_hit, word, key=lambda x: [-len(x), x])

                if new_idx < len(word):
                    matching[word[new_idx]].append((word, new_idx))
                else:
                    matching[word[cnt]].append((word, cnt))

        return max_hit
                
            


if __name__ == "__main__":
    print('Should be: apple')
    print(Solution().findLongestWord(s = "abpcplea", d = ["ale","apple","monkey","plea"]))

    print('Should be a')
    print(Solution().findLongestWord(s = "abpcplea", d = ["a","b","c"]))

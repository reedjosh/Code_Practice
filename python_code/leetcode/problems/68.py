"""
    problems/68.py

    Text Justification.
"""
from collections import deque, namedtuple
from typing import List

class Solution:
    def fullJustify(self, words: List[str], maxWidth: int) -> List[str]:

        def justify_line(word_q, running_length):
            """ Given a line of words, justify the line to maxWidth. """
            slot_count = len(word_q) - 1
            print(type(word_q))
            word = word_q.popleft()
            spaces_needed = maxWidth - running_length
            if slot_count == 0: #  Special 1 word case.
                return word + "*" * (maxWidth - len(word))

            # Build line from words by calculating space_per_slot and then number of
            # extra space slots.
            line = []
            space_per_slot =  spaces_needed // slot_count
            needed_extra = spaces_needed - (space_per_slot * slot_count)
            while word_q:
                line.append(word + '*'*(space_per_slot + (1 if needed_extra > 0 else 0)))
                needed_extra -= 1
                word = word_q.popleft()

            line.append(word) #  Append final line without spaces.

            return ''.join(line)

        line = deque()
        lines = [] 
        running_length = 0
        for word in words:

            # If the next word would increase the total line length beyond maxWidth create a line.
            if (running_length  + len(line) + len(word)) > maxWidth:
                print(type(line))
                lines.append(justify_line(line, running_length))

                # Rest line.
                running_length = 0

            # Add the next word to the current line.
            running_length += len(word)
            line.append(word)

        # Add final line using join to left justify it.
        lines.append(justify_line(deque(['*'.join(line)]), running_length))

        return lines
        
        

def main():
    lines = Solution().fullJustify(
        ["This", "is", "an", "example", "of", "text", "justification."], 16)
    print([len(line) for line in lines])
    print('\n'.join(lines))

    lines = Solution().fullJustify( 
        ["What","must","be","acknowledgment","shall","be"], 16)
    print([len(line) for line in lines])
    print('\n'.join(lines))

    lines = Solution().fullJustify( 
        ["Science","is","what","we","understand","well","enough","to","explain",
         "to","a","computer.","Art","is","everything","else","we","do"], 20)
    print([len(line) for line in lines])
    print('\n'.join(lines))



if __name__ == "__main__":
    main()

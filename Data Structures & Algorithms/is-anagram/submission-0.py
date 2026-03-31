class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        # Step 1: Quick length check
        if len(s) != len(t):
            return False

        # Step 2: Initialize 26 buckets for letters a–z
        counts = [0] * 26
        base = ord('a')

        # Step 3: Walk through both strings
        for char_s, char_t in zip(s, t):
            counts[ord(char_s) - base] += 1  # +1 for s
            counts[ord(char_t) - base] -= 1  # -1 for t

        # Step 4: Verify all counts are zero
        return all(c == 0 for c in counts)
      
class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        # Stack -> Time:O(n*log(n)), Space:O(n)
        pairs = [(p, s) for p, s in zip(position, speed)]
        stack = []
        for p, s in sorted(pairs)[::-1]:
            temp = (target - p) / s
            if stack == [] or temp > stack[-1]:
                stack.append(temp)
        return len(stack)

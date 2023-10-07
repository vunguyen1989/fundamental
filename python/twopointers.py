    # Given n non-negative integers a1, a2, ..., an , 
    # where each represents a point at coordinate (i, ai). 
    # n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). 
    # Find two lines, which together with x-axis forms a container, 
    # such that the container contains the most water.
    def maxArea(self, height):
        l,area, r = 0, 0, len(height) - 1
        while l < r:  
            if height[l] < height[r]: 
                area = max(height[l] * (r - l), area)
                l += 1
            else: 
                area = max(height[r] * (r - l), area)
                r -= 1
        return area    
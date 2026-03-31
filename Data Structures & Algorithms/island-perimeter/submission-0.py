class Solution:
    def islandPerimeter(self, grid: List[List[int]]) -> int:
        rows = len(grid)
        column = len(grid[0])

        #set to keep track of lans cells we have already visited
        visited = set()

        def dfs(r, c):
            # if row index is outside the grid,
            # this side contributes 1 to the perimeter
            if r < 0 or r >= rows:
                return 1 
            # if column index is outside the grid,
            # this side contributes 1 to the perimeter
            if c < 0 or c >= column:
                return 1
            
            # if the current cell is water, 
            # the land touching it adds 1 to the perimeter
            if grid[r][c] == 0:
                return 1

            # If we have  already visisted this land cell, 
            # do not count its edges again
            if(r,c) in visited: 
                return 0
            # mark current land cell as visisted
            visited.add((r,c))

            #initialize perimeter contribution from this cell 
            perimeter = 0 

            #explore down
            perimeter += dfs(r + 1, c)

            #explore up
            perimeter += dfs(r - 1, c)

            #explore right
            perimeter += dfs(r, c + 1)

            #explore left 
            perimeter += dfs(r, c - 1)

            return perimeter
        
        #loop through the grid
        for i in range(rows):
            for j in range(column):
                #start dfs as soon as we find land 
                if grid[i][j] == 1:
                    return dfs(i,j)
            

        
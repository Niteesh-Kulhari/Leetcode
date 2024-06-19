class Solution(object):
    def rowAndMaximumOnes(self, mat):
        """
        :type mat: List[List[int]]
        :rtype: List[int]
        """
        finalAns = []
        row_index = 0
        finalCount = 0
        
        rows = len(mat)
        cols = len(mat[0])

        for i in range(rows):
            count = 0
            for j in range(cols):
                if(mat[i][j] == 1):
                    count += 1
            if( count > finalCount ):
                finalCount = count
                row_index = i

        finalAns.append(row_index)
        finalAns.append(finalCount)

        return finalAns


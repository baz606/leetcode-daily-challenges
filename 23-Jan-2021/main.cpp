#include <vector>
/*
  Problem: Sort the Matrix Diagonally
  Link: https://leetcode.com/explore/challenge/card/january-leetcoding-challenge-2021/582/week-4-january-22nd-january-28th/3614/
  Runtime: 0ms
  Memory Usage: 8.6MB
*/
class Solution
{
  public:

    void putBack(std::vector<std::vector<int>>& mat, std::vector<int>& diagonal, int i, int j )
    {
      int m = mat.size();
      int n = mat[0].size();
      for(int k = 0; i < m && j < n && k < diagonal.size(); i++, j++, k++)
      {
        mat[i][j] = diagonal[k];
      }
    }
    std::vector<std::vector<int>> diagonalSort(std::vector<std::vector<int>>& mat)
    {
      // [m x n] matrix
      int m = mat.size();
      int n = mat[0].size();
      
      std::vector<int> diagonal;
      
      // Loop through all diagonals starting in each column
      for (int i = 0, j = 0; j < n; j++)
      {
        for (int k = i, z = j; z < n && k < m; k++, z++)
        {
          diagonal.push_back(mat[k][z]);
        }
        std::sort(diagonal.begin(), diagonal.end());
        putBack(mat, diagonal, i, j);
        diagonal.clear();
      }

      // Loop through all diagonals starts in each row
      for (int i = 1, j = 0; i < m; i++)
      {
        for (int k = i, z = j; z < n && k < m; k++, z++)
        {
          diagonal.push_back(mat[k][z]);
        }
        std::sort(diagonal.begin(), diagonal.end());
        putBack(mat, diagonal, i, j);
        diagonal.clear();
      }

      return mat;
    }
};

class Solution
{
public:
  int totalNQueens(int n)
  {
    // each element represents which column should we place the queen for this row
    std::vector<int> board(n, -1);
    int res{ 0 };
    backtrack(board, 0, res);
    return res;
  }

private:
  void backtrack(std::vector<int> &board, int row, int &res)
  {
    if (row == board.size()) {
      res++;
      return;
    }
    for (int ii = 0; ii < board.size(); ii++) {
      if (!isBoardValid(board, row, ii)) {
        continue;
      }
      // Select this column for this row
      board[row] = ii;
      backtrack(board, row + 1, res);
      board[row] = -1;
    }
    return;
  }

  bool isBoardValid(std::vector<int> &board, int row, int col)
  {
    // Check through 0 to row-1 rows and see if the board if valid or not when we place a queen
    // at the col for current row
    for (int jj = 0; jj < row; jj++) {
      // same column has the queen already
      if (board[jj] == col) return false;
      // along the diagonals, we already have the queen from rows 0 to j - 1
      if (row - jj == abs(board[jj] - col)) return false;
    }
    return true;
  }
};

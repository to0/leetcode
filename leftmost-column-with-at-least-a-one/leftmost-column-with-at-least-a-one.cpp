/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &m) {
        // # of 1 is ascending
        return BinarySearchColumns(m, 1, 0, m.dimensions()[1] - 1);
    }
    
private:
    int BinarySearchColumns(BinaryMatrix& m, int target, int begin_col, int end_col) {
        cout << "begin " << begin_col << "end " << end_col << endl;
        if (begin_col > end_col) {
            return -1;
        }
        
        int mid_col = (begin_col + end_col) / 2;
        int ones = OnesInColumn(m, mid_col);
        if (ones < target) {
            return BinarySearchColumns(m, target, mid_col + 1, end_col);
        }
        
        // ones == target
        if (begin_col == end_col) {
            return begin_col;
        }
        
        // if (ones > target) {
            return BinarySearchColumns(m, target, begin_col, mid_col);
        // }
        
        
        
        // return BinarySearchColumns(m, target, begin_col, mid_col);
    }
    int OnesInColumn(BinaryMatrix &m, int col) {
        int ones = 0;
        for (int row = 0; row < m.dimensions()[0]; row++) {
            ones += m.get(row, col);
        }      
        return ones;
    }
    
    
};
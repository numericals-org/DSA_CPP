#include <iostream>
#include <unordered_set>
using namespace std;

int main()
{
    const int N = 9;
    unordered_set<char> rows[N], cols[N], boxes[N];

    char board[9][9] = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    for (int r = 0; r < N; r++)
    {
        rows[r] = unordered_set<char>();
        cols[r] = unordered_set<char>();
        boxes[r] = unordered_set<char>();
    }

    for (int r = 0; r < N; r++)
    {
        for (int c = 0; c < N; c++)
        {
            char val = board[r][c];
            if(val == '.')
                continue;

            if(rows[r].find(val) != rows[r].end()){
                return 0;
            }
            rows[r].insert(val);

            if(cols[c].find(val) != cols[c].end()){
                return 0;
            }
            cols[c].insert(val);

            int idx = (r/3) * 3 + (c/3);
            if(boxes[idx].find(val) != boxes[idx].end()){
                return 0;
            }
            boxes[idx].insert(val);
        }
    }

    std::cout << "The Sudoku board is valid." << std::endl;
    return 0;
}
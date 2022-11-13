#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
#ifndef SUDOKU_H
#define SUDOKU_H

class Sudoku{
    public:
        Sudoku();
        Sudoku(Sudoku *sudo);

        int getValue(int row, int col);
        void setValue(int row, int col, int num);

        bool solve();
        void getSudoku(string filename);
        void print();
    private:
        int s[9][9];
        bool isInRow(int row, int num);
        bool isInCol(int col, int num);
        bool isInBox(int colStart, int rowStart, int num);
        bool isEmpty(int &row, int&col);
        bool isCellValid(int row, int col, int num);
};
#endif

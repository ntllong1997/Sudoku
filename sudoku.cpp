#include "sudoku.hpp"



Sudoku::Sudoku()
{
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            s[i][j] = 0;
        }
    }
}

Sudoku::Sudoku(Sudoku* sudo){
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            s[i][j] = sudo->getValue(i,j);
        }
    }
}

int Sudoku::getValue(int row, int col){
    return s[row][col];
}

void Sudoku::setValue(int row, int col, int num){
    s[row][col] = num;
}

bool Sudoku::isInRow(int row, int num){
    for (int col = 0; col < 9; col++){
        if( s[row][col] == num){
            return true;
        }
    }
    return false;
}

bool Sudoku::isInCol(int col, int num){
    for (int row = 0; row < 9; row++){
        if( s[row][col] == num){
            return true;
        }
    }
    return false;
}

bool Sudoku::isInBox(int colStart, int rowStart, int num){
    
    for (int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if (s[i+rowStart][j+colStart] == num){
                return true;
            }
        }
    }
    return false;
}

bool Sudoku::isEmpty(int &row, int &col){
    for (row = 0; row < 9; row++)
        for (col = 0; col < 9; col++)
            if (s[row][col] == 0) //marked with 0 is empty
            return true;
   return false;
}

bool Sudoku::isCellValid(int row, int col, int num){
    return !(isInBox(col - col%3, row - row%3, num) || isInCol(col,num) ||isInRow(row,num));
}

bool Sudoku::solve(){
    int row, col;
    if(!this->isEmpty(row, col)){
        return true;
    }
    for (int num = 1; num < 10; num++){
        if (isCellValid(row, col, num)){
            s[row][col] = num;
            if(this->solve()) {return true;}
            s[row][col] = 0;
        }
    }
    return false;
}

void Sudoku::print(){
    for (int i = 0; i < 9; ++i) {
        if (i % 3 == 0) printf("+---------+---------+---------+\n");
        for (int j = 0; j < 9; ++j) {
            if (j % 3 == 0) printf("|");
            printf(" %d ", s[i][j]);
        }
        printf("|\n");
    }
    printf("+---------+---------+---------+\n");
}

void Sudoku::getSudoku(string filename){
    string line;
    ifstream ife;
    ife.open(filename);

    if(!ife.is_open()){
        cerr << "Could not open file" << endl;
        exit(1);
    }

    int row = 0;
    while(getline(ife, line)){
        stringstream inf(line);
        string temp;
        for (int col = 0; col < 9; col++){
            inf >> temp;
            s[row][col] = stoi(temp);
        }
        row++;
    }
}

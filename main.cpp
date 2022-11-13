#include "sudoku.hpp"

int main (){
    Sudoku s;
    s.getSudoku("temp.dat");
    if (s.solve() == true){
        s.print();
    }
    else {
        cout << "NO solution" << endl;
    }
}
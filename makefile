su: main.cpp sudoku.o
	g++ main.cpp sudoku.o -o su

sudoku: sudoku.cpp sudoku.hpp
	g++ -c sudoku.cpp -o sudoku.o
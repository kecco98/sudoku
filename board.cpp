//
// Created by kecco98 on 08/07/22.
//

#include "board.h"
#include <iostream>
#include <cassert>
#include <cmath>
#include <cstdlib>
#include <ctime>

void Board::printPuzzle() {

    int sizeBlock  = (int)sqrt(N);
    int extraSpace = N/10;

    for(int i=0; i<N; i++) {
        cout << "+---";
        for(int j=0; j<extraSpace; j++){
            cout << "-";
        }
    }

    cout <<"+"<<endl;

    for(int i=0; i<N; i++){
        cout << "| ";
        for(int j=0; j<N; j++){

            if((*this)(i,j) == 0){
                cout << ".";
                for(int k=0; k< extraSpace; k++){
                    cout << " ";
                }
            } else {
               if (!isProblem(i,j)){
                   cout << (*this)(i,j);
               } else {
                   cout << "\033[31m" << (*this)(i,j) << "\033[39m";
               }


                int numDigits = (*this)(i,j)/10;
                while(numDigits < extraSpace){
                    cout << " ";
                    numDigits++;
                }
            }

            if((j+1) % sizeBlock == 0) {
                cout << " | ";
            } else {
                cout << "   ";
            }
        }

        cout << endl;
        if((i+1) % sizeBlock == 0){
            for(int j=0; j<N; j++){
                cout << "+---";

                for(int k=0; k < extraSpace; k++){
                    cout << "-";
                }
            }

            cout << "+" << endl;
        }
    }

}

bool feasible(Board &board, int row, int col, int val){

    int N = board.getSize();
    assert(row<N);
    assert(col<N);
    int sizeBlock = (int) sqrt(N);

    //Control row
    for(int j=0; j<N; j++){
        if(board(row, j) == val) return false;
    }

    //Control col
    for(int i=0; i<N; i++){
        if(board(i, col) == val) return false;
    }

    // coordinates of upper-left hand corner of block that (row,col) occupies
    int blockRow = sizeBlock*(row/sizeBlock);
    int blockCol = sizeBlock*(col/sizeBlock);

    // See if used yet in block
    for(int i = 0; i < sizeBlock; i++)
        for(int j = 0; j < sizeBlock; j++)
            if(board(blockRow + i,blockCol + j) == val)
                return false;

    return true;
}

bool solve(Board &board, int row, int col){

    int N = board.getSize();
    //assert(N == pow(sqrt(N),2));

    if(row == N) {
        return true;
    }

    if(board(row,col) != 0) {
        if(col == (N-1)){
            if(solve(board, row+1, 0)) return true;
        } else {
            if(solve(board, row, col+1)) return true;
        }
        return false;
    }

    for(int val = 1; val <= N; val++) {
        if(feasible(board, row, col, val)){
            board(row,col) = val;
            if(col == (N-1)){
                if(solve(board, row+1, 0)) return true;
            } else {
                if(solve(board, row, col+1)) return true;
            }
        }
    }

    board(row, col) = 0;
    return false;
}

Board generatePuzzle(int N, int nobs){

    assert(nobs <= N*N);
    Board board(N);

    int* perm = generatePerm(N); // permuted 1...N

    // fill diag of board with perm
    for(int i = 0; i<N ; i++)
        board(i,i) = perm[i];

    delete [] perm;

   // solve board
    bool isSolved = solve(board,0,0);
    assert(isSolved); // by filling diagonal, this should never be violated


    // remove N*N - nobs entries
    perm = generatePerm(N*N);
    int x, y;
    for(int i = 0; i < (N*N - nobs); i++){
        x = (perm[i]-1)/N;
        y = (perm[i]-1)%N;
        board(x,y) = 0;
        board.assignImmutable(x,y, false);
    }

    delete [] perm;

    return board;
}

int* generatePerm(int N){

    int *x = new int[N];
    for(int i = 0; i<N; i++)
        x[i] = i+1;

    int rindex;
    int temp;

    for(int i = (N-1); i>0; i--){
        rindex = rand()%(i+1);
        temp = x[i];
        x[i] = x[rindex];
        x[rindex] = temp;
    }

    return x;
}
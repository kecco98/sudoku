/*
 * Francesco Ciarla
 *
 * Board
*/

#pragma once
#include <cassert>
#include <cstdlib>
#include <iostream>

using namespace std;

class Board{

    int N;
    int **grid;
    bool **immutable;
    bool **infeasible;

public:

    Board(int N) : N(N){

        //Grid creation
        grid = new int*[N];
        for(int i=0; i<N; i++)
            grid[i] = new int[N];


        //Grid inizilizzazion
        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
                grid[i][j] = 0;


        //matrix to track immutable creation
        immutable = new bool*[N];
        for(int i=0; i<N; i++)
            immutable[i] = new bool[N];


        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
                immutable[i][j] = true;


        //matrix to track which value can cause infeasibility
        infeasible = new bool*[N];

        for(int i=0; i<N; i++)
            infeasible[i] = new bool[N];

        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
                infeasible[i][j] = false;


    }

    ~Board(){
        for(int i=0; i<N; i++)
            delete [] grid[i];
        delete [] grid;

        for(int i=0; i<N; i++)
            delete [] immutable[i];
        delete [] immutable;

        for(int i=0; i<N; i++)
            delete [] infeasible[i];
        delete [] infeasible;
    }

    void printPuzzle();

    int& operator() (int x, int y){
        assert(x<N && y<N);
        return grid[x][y];
    }

    bool isProblem(int x, int y){
        return infeasible[x][y];
    }

    void assignImmutable(int x, int y, bool val) {
        immutable[x][y] = val;
    }

    int getSize() {
        return N;
    }

    bool inBound(int val);

    bool checkPuzzle();

    bool feasibleUser(int row, int col, int val);

    bool checkImmutable(int row, int col) {
        return immutable[row][col];
    }

    void assigValue(int x, int y, int val){
        (*this)(x,y)=val;
    }

    void clearPuzzle();

};

bool feasible(Board &board, int row, int col, int val);
bool solve(Board &board, int row, int col);
Board generatePuzzle(int n, int nobs);
int* generatePerm(int N);
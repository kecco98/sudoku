/*
 * Francesco Ciarla
 *
 * Board
*/

#pragma once

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


};

Board generatePuzzle(int n, int nobs);
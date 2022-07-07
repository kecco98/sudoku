/*
 * Francesco Ciarla
 *
 * MAIN
 */
#include <iostream>
#include "game.h"


using namespace std;


int main(int argc, char* rgv[]) {

    //Prendere da prompt
    int gamesize = 0;
    int nobs = 0;

    // Welcome message
    cout << "===========================================" << endl;
    cout << "============ Welcome to Sudoku! ===========" << endl;
    cout << "===========================================" << endl;

    playGame(gamesize, nobs);

    return 0;
}

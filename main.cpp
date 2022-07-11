/*
 * Francesco Ciarla
 *
 * MAIN
 */
#include <iostream>
#include "game.h"


using namespace std;


int main(int argc, char* rgv[]) {

    //TODO (Take from the propt this two values)
    int gamesize = 9;
    int nobs = 20;

    // Welcome message
    cout << "========================================" << endl;
    cout << "=============== " << "\033[34m" << "SUDOKU!" << "\033[39m" <<" ================" << endl;
    cout << "========================================" << endl;

    playGame(gamesize, nobs);

    return 0;
}

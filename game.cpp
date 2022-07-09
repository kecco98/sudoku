//
// Created by kecco98 on 07/07/22.
//

#include "game.h"
#include "board.h"

void playGame(int size, int nobs) {
    Board board = generatePuzzle(size,nobs);
    board.printPuzzle();

    int *inputVals;

    inputVals = getInput();

}

int* getInput(){
    int res[3];

    //TODO (Do better the input from terminal!!)
    cout << "Insert coordinates" << endl;
    cout << "x" << endl;
    cin >> res[0];
    cout << "y" << endl;
    cin >> res[1];
    cout << "val" << endl;
    cin >> res[2];
}
//
// Created by kecco98 on 07/07/22.
//

#include <sstream>
#include <regex>
#include "game.h"
#include "board.h"

void playGame(int size, int nobs) {

    string input;
    bool solved;
    Board board = generatePuzzle(size,nobs);

    int *inputVals;

    do {

        board.printPuzzle();
        inputVals = getInput();
//        getline(cin, input);
//
//        if(input == "Solve" || input == "solve") {
//            solved = solve(board, 0, 0);
//            board.printPuzzle();
//            break;
//        }
//
//        if(input == "Clear" || input == "clear") {
//            board.clearPuzzle();
//            board.printPuzzle();
//            break;
//        }


        //Check if values are out of range throw error and continue
        bool invalid = false;
        for(int i=0; i<3; i++){
            if(!board.inBound(inputVals[i])){
                invalid = true;
            }
        }

        if(invalid) {
            cout << "Values entered must be between 1 and " << board.getSize() << endl;
            continue;
        }

        if(board.feasibleUser((inputVals[0] - 1), (inputVals[1] - 1), inputVals[2])){

            if(!board.checkImmutable((inputVals[0] - 1), (inputVals[1] - 1))){
                board.assigValue((inputVals[0]-1), (inputVals[1]-1), inputVals[2]);
            } else {
                cout << "You can't change that value!" << endl;
            }

        } else {
            cout << "Not feasible!" << endl;
        }

        for(int i=0; i<3; i++){
            inputVals[i] = 0;
        }

    } while(!board.checkPuzzle());

    if(solved){
        cout << "The puzzle is solved!" << endl;
    }

}

int* getInput(){
    static int res[3];

    cout << "Insert coordinates" << endl;
    cout << "x y val :" << endl;
    cin >> res[0] >> res[1] >> res[2];

    cout << "You choose to insert the value "<< res[2] << " in position (" << res[0] << "," << res[1] << ")" <<endl;

    return res;
}
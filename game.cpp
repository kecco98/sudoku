//
// Created by kecco98 on 07/07/22.
//

#include <sstream>
#include <regex>
#include <iostream>
#include <sstream>
#include <vector>
#include "game.h"
#include "board.h"

void playGame(int size, int nobs) {

    string input;
    bool solved = false;
    Board board = generatePuzzle(size,nobs);

    int *inputVals;

    do {

        board.printPuzzle();
        printMenu();
        getline(cin, input);

        if(input == "Solve" || input == "solve") {
            solved = solve(board, 0, 0);
            board.printPuzzle();
            break;
        }

        if(input == "Clear" || input == "clear") {
            board.clearPuzzle();
            board.printPuzzle();
            cout << "The puzzle is cleared!" << endl;
            continue;
        }

        inputVals = getInput(input);

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

    if(board.checkPuzzle()){
        solved = true;
    }

    if(solved) {
        cout << "The puzzle is solved!" << endl;
    }

}

vector<string> split (const string &s, char delim) {
    vector<string> result;
    stringstream ss (s);
    string item;

    while (getline (ss, item, delim)) {
        result.push_back (item);
    }

    return result;
}

int* getInput(const string& s){

    static int res[3];

    vector<string> v = split (s, ' ');

    int n=0;
    for (const auto& i : v){
        res[n] = stoi(i);
        n++;
    }

    cout << "You choose to insert the value "<< res[2] << " in position (" << res[0] << "," << res[1] << ")" <<endl;

    return res;
}

void printMenu(){
    cout << "Command " << "\033[35m" << "solve" << "\033[39m" << " for solve the puzzle" << endl;
    cout << "Command " << "\033[35m" << "clear" << "\033[39m" << " for clear the puzzle" << endl;
    cout << "Insert coordinates in this way: ";
    cout << "\033[35m" << "x y val" << "\033[39m" << endl;
}
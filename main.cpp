/*
 * Francesco Ciarla
 *
 * MAIN
 */
#include <iostream>
#include <sstream>
#include "game.h"


using namespace std;

int main(int argc, char* argv[]) {

    int gamesize = 9;
    int nobs = 10;

    for(int i=1; i<argc; ++i){
        if((string(argv[i]) == "--gamesize") || (string(argv[i]) == "-g")){
            if(i+1 < argc) {
                istringstream ss(argv[++i]);
                if(!(ss >> gamesize)){
                    cerr << "Invalid number " << argv[i++] << endl;
                }
            } else {
                cerr << "--gamesize option requires one argument." << endl;
                return 1;
            }
        }
    }

    for(int i=1; i<argc; ++i){
        if((string(argv[i]) == "--nobs") || (string(argv[i]) == "-n")){
            if(i+1 < argc) {
                istringstream ss(argv[++i]);
                if(!(ss >> nobs)){
                    cerr << "Invalid number " << argv[i++] << endl;
                }
            } else {
                cerr << "--nobs option requires one argument." << endl;
                return 1;
            }
        }
    }


    // Welcome message
    cout << "========================================" << endl;
    cout << "=============== " << "\033[34m" << "SUDOKU!" << "\033[39m" <<" ================" << endl;
    cout << "========================================" << endl;
    //printMenu();

    playGame(gamesize, nobs);

    return 0;
}
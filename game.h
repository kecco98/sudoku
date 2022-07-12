/*
 * Francesco Ciarla
 *
 * Game play functions declaration
*/

#pragma once
#include <iostream>
#include <vector>

using namespace std;

void playGame(int size, int nobs);
void printMenu();
int* getInput(const string& s);
vector<string> split (const string &s, char delim);
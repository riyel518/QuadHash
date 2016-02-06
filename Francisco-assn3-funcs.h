#ifndef FRANCISCO-ASSN3-FUNCS__H_INCLUDED
#define FRANCISCO-ASSN3-FUNCS__H_INCLUDED
#include <iostream>
using namespace std;

const int INITIALIZER = 0;   //initialze and counter, loop or data
const int INCREASE = 1;      //incremental to 1
const int QUADRATIC = 2;     // Use in calculation of quad hash code
const int EVEN = 2;          //use to get the even number of aray to be search

// keyLocation function generate the initial hash code location for the hash table
int keyLocation(int values, int HtableSize);

//createQuadProb function transfer interger data from ramdom array to the quad hash
void createQuadProb(int randomArray[], int randArraySize, int quadHash[], int HtableSize);

//insertQuadProb function use quad hash code to properly insert value to the hash table
void insertQuadProb(int quadHash[], int insertValue, int& initialLoc, int HtableSize);

//searchQuad function searches half of randomArray content to the hash table. it also generate or return
//the number of inspected item per search and the average search
void searchQuad(int randomArray[], int randArraySize, int quadHash[], int HtableSize, int& quadTotal, float& avgSearch);

//checkQuad function search a specific targeted vaue in the hash table and it generate the total
//number of quad search until the target value is found
void checkQuad(int quadHash[], int insertValue, int& initialLoc, int HtableSize, int& quadTotal);

//getQuadSeachAvg function calculate the average search to find the
//target value in the Htable
float getQuadSeachAvg(int quadTotal, int randArraySize);


#endif

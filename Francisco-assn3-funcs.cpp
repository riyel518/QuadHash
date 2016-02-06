#include <iostream>
#include "FRANCISCO-ASSN3-funcs.h"
using namespace std;

// keyLocation function generate the initial hash code location for the hash table

int keyLocation(int values, int HtableSize){

      return (values % HtableSize);         //return the hash code for the values

}

//createQuadProb function transfer interger data from ramdom array to the quad hash

void createQuadProb(int randomArray[], int randArraySize, int quadHash[], int HtableSize){

   int counter = INITIALIZER;
   int data,
       initialKey;

   do{

         data = randomArray[counter];
         initialKey = keyLocation(data, HtableSize);
         insertQuadProb(quadHash, data, initialKey,HtableSize);
         counter++;

   }while(counter < randArraySize);

}

//insertQuadProb function use quad hash code to properly insert value to the hash table

void insertQuadProb(int quadHash[], int insertValue, int& initialLoc, int HtableSize){

 int posCount,
     increments;


posCount = INITIALIZER;            //Set posCount to zero
increments = INCREASE;            //set increments to 1

//loop if quadHash is empty and quadHash value is not qual to insert item and posCount is less than the HtableSize
while ((quadHash[initialLoc] != INITIALIZER) && (quadHash[initialLoc] != insertValue) && (posCount < HtableSize / QUADRATIC)){

          posCount++;
          initialLoc = (initialLoc + increments) % HtableSize;
          increments = increments + QUADRATIC;

    }// end of while loop

if (quadHash[initialLoc] == INITIALIZER){

     quadHash[initialLoc] = insertValue;

}

else if (quadHash[initialLoc] == insertValue){

    cout << endl << "Error: no duplication " << endl;

}

else{

    cout << endl << "Error: Table is full" << endl;

  }


}

//searchQuad function searches half of randomArray content to the hash table. it also generate or return
//the number of inspected item per search and the average search
void searchQuad(int randomArray[], int randArraySize, int quadHash[], int HtableSize, int& quadTotal, float& avgSearch){

  int counter = INITIALIZER;
  int data,
      initialKey;



  do{

    if (counter % QUADRATIC == INITIALIZER){

        data = randomArray[counter];
        initialKey = keyLocation(data, HtableSize);
        checkQuad(quadHash, data, initialKey, HtableSize, quadTotal);
     }

		counter++;


  }while(counter < randArraySize);


    avgSearch = getQuadSeachAvg(quadTotal, randArraySize);

}

//checkQuad function search a specific targeted vaue in the hash table and it generate the total
//number of quad search until the target value is found

void checkQuad(int quadHash[], int insertValue, int& initialLoc, int HtableSize, int& quadTotal){


  int posCount,
      increments;


 posCount = INITIALIZER;            //Set posCount to zero
 increments = INCREASE;            //set increments to 1

 //loop if quadHash is empty and quadHash value is not qual to insert item and posCount is less than the HtableSize
 //increment the quatTotal
 while ((quadHash[initialLoc] != INITIALIZER) && (quadHash[initialLoc] != insertValue) && (posCount < HtableSize / QUADRATIC)){

           posCount++;
           quadTotal++;
           initialLoc = (initialLoc + increments) % HtableSize;
           increments = increments + QUADRATIC;

     }// end of while loop

//increment the quadtotal when the target found
 if (quadHash[initialLoc] == insertValue){

     quadTotal++;


 }

 else{

     cout << endl << "Item cannot be found in the hash table" << endl;

   }


}


//getQuadSeachAvg function calculate the average search to find the
//target value in the Htable

float getQuadSeachAvg(int quadTotal, int randArraySize){

    return (float)quadTotal/(float)(randArraySize/QUADRATIC);

}

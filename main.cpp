#include <stdio.h>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void readFile(int* refArray)
{

}

void printMatrix(int* refArray)
{

}

void addMatrix(int* refArrayOne, int* refArrayTwo)
{

}

void multMatrix(int* refArrayOne, int* refArrayTwo)
{

}

void subtractMatrix(int* refArrayOne, int* refArrayTwo)
{

}

int main ()
{   
    int matrix[100][100]; // The max size of our matrix will be 100x100
    int size;
    char filename[20]; // Create a buffer for our filename
    
     // Get a file name from the user to read in the matrix data
    cout << "Enter an input filename: ";
    cin >> filename;

    // Open the file and get a pointer to it
    FILE* inputFilePtr = fopen(filename, "r");

    // Make sure it was a valid file
    if (inputFilePtr == NULL)
    {
        cout << "Invalid filename" << endl;
        return 0;
    }

    // I need to be able to take the file and turn it into a 2D array format 
    /*
        Open file
        Read first char --> determine loop amt
        Loop through lines
            Create row from line
            Zero fill rest of row
            Add row to matrix
        Zero fille rest of columns
    */

    /* Note: This assumes the file is 12 lines long with a number on each line and only that */
    /* Read in the file and store the data in the sales array */
    /*for (int i = 0; i < 12; i++)
    {
        fscanf(inputFilePtr, "%f", &[i]);
    }*/

    
    /* Close the file as keeping it open is no longer needed */
    fclose(inputFilePtr);
     
    return 0;
}
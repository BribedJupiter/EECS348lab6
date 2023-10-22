#include <iostream> // For io
#include <fstream> // For file io
#include <string> // For ease in reading lines

#define MAX_SIZE 100

using std::cout;
using std::cin;
using std::endl;
using std::string;

int readFile(int matrices[MAX_SIZE][MAX_SIZE][MAX_SIZE], int& numMatrices, int& size); // Read a file and create a list of matrices

void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int size); // Print a matrix

void addMatrix(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int size); // Add matrix A and matrix B

void multMatrix(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int size); // Multiply matrix A and matrix B

void subtractMatrix(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int size); // Subtract matrix B from matrix A

int main ()
{   
    int matrices[MAX_SIZE][MAX_SIZE][MAX_SIZE]; // We will format this as follows:
    // The first index is the matrix identifier, the second is the row, and the third is the column.
    int numMatrices, size; // Store the number of matrices and their size

    // Read in the matrices from a file
    numMatrices = readFile(matrices, numMatrices, size);
    if (numMatrices == -1)
    {
        return -1;
    }

    cout << "Jack Bauer" << endl << "Lab #6: Matrix Multiplication" << endl;

    // Display the matrices
    cout << "Matrix A" << endl;
    printMatrix(matrices[0], size);

    cout << "Matrix B" << endl;
    printMatrix(matrices[1], size);

    addMatrix(matrices[0], matrices[1], size);
    multMatrix(matrices[0], matrices[1], size);
    subtractMatrix(matrices[0], matrices[1], size);
     
    return 0;
}

int readFile(int matrices[MAX_SIZE][MAX_SIZE][MAX_SIZE], int& numMatrices, int& size)
{
    char filename[20]; // Create a buffer for our filename
    
     // Get a file name from the user to read in the matrix data
    cout << "Enter an input filename: ";
    cin >> filename;

    std::ifstream inputFile; // Create an input file variable
    inputFile.open(filename); // Open our file

    // Make sure it was a valid file, if not end the function
    if (!inputFile.is_open())
    {
        cout << "Invalid filename" << endl;
        return -1;
    }

    // Make sure we can find the size, if not end the function
    if (!(inputFile >> size))
    {
        cout << "Error reading matrix size" << endl;
        inputFile.close();
        return -1;
    }

    numMatrices = 0; // Begin reading in our matrices
    while (numMatrices < MAX_SIZE) // Make sure we don't go beyond our limit. Each iteration will complete a matrix
    {
        if (inputFile.eof()) break; // If we reach the end of the file, break the loop
        for (int i = 0; i < size; i++) // Build our matrix
        {
            for (int j = 0; j < size; j++)
            {
                if (!(inputFile >> matrices[numMatrices][i][j])) // Assign the values, if there is an issue return the function with an error code
                {
                    cout << "Error reading matrix element" << endl;
                    inputFile.close();
                    return -1;
                }
            }
        }

        numMatrices++; 
    }


    // Close the file as keeping it open is no longer needed
    inputFile.close();

    return numMatrices;
}

void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int size) // Print a matrix
{
    for (int i = 0; i < size; i++) // Print the matrix
    {
        for (int j = 0; j < size; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void addMatrix(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int size) // Add matrix A and matrix B
{
    int resultMatrix[MAX_SIZE][MAX_SIZE];
    cout << "Matrix Sum (A + B)" << endl;

    for (int i = 0; i < size; i++) 
    {
        for (int j = 0; j < size; j++)
        {
            resultMatrix[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
    
    printMatrix(resultMatrix, size);
}

void multMatrix(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int size) // Multiply matrix A and matrix B
{
    int resultMatrix[MAX_SIZE][MAX_SIZE];
    cout << "Matrix Product (A * B)" << endl;

    for (int i = 0; i < size; i++) 
    {
        for (int j = 0; j < size; j++)
        {
            // sum of corresponding entries from row A and col B
            int entry = 0;
            for (int k = 0; k < size; k++)
            {
                entry += matrixA[i][k] * matrixB[k][j];
            }

            resultMatrix[i][j] = entry;
        }
    }

    printMatrix(resultMatrix, size);
}

void subtractMatrix(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int size) // Subtract matrix B from matrix A
{
    int resultMatrix[MAX_SIZE][MAX_SIZE];
    cout << "Matrix Difference (A - B)" << endl;

    for (int i = 0; i < size; i++) 
    {
        for (int j = 0; j < size; j++)
        {
            resultMatrix[i][j] = matrixA[i][j] - matrixB[i][j];
        }
    }
    
    printMatrix(resultMatrix, size);
}
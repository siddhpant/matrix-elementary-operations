#include <iostream>
#include <utility>
#include <vector>
#include <fstream>
#include <string>
#include "../Print/date.h"   //Used Howard Hinnant's free, open-source header-only datetime library, available at https://bit.ly/2K1YI2m
#include "../Print/print_matrix.h"


/*
ord = Order of square matrix.
Matrix = The matrix of given order.
*/
void row_operation(int ord, std::vector<std::vector<double> > row_matrix, int inv){

//Initializing elementary matrix.
std::vector<std::vector<double> > elem_matrix(ord, std::vector<double> (ord, 0.0));
for (size_t i = 0; i < ord; i++) {
    elem_matrix[i][i] = 1.0;
}

//Make filename with datetime and then open stream.
std::string filename("Matrix ");
filename += date::format("%F %T", std::chrono::system_clock::now());
filename += ".txt";
std::ofstream matrix_out(filename.c_str());

//Print initial matrices to file
matrix_out << "Inital matrix/matrices!" << "\r\n";
if (inv == 1) {
    print_matrix(matrix_out, ord, row_matrix, elem_matrix);
} else {
    print_matrix(matrix_out, ord, row_matrix);
}

int ch, r, m, o;       // choice, row, multiplier, other operand
char yn;               // yes or no at end.
do {
    ch = r = m = yn = 0;
    std::cout << '\n' << "Which operation?" << '\n';
    std::cout << "\t 1. R[i] <--> R[j]" << '\n';
    std::cout << "\t 2. R[i] ---> k*R[i]" << '\n';
    std::cout << "\t 3. R[i] ---> R[i] + k*R[j]" << '\n';
    std::cout << "\t 4. R[i] ---> R[i] - k*R[j]" << '\n';
    std::cout << "\t 5. Exit" << '\n';
    std::cout << "Enter your choice (1,2,3,4,5)" << '\n';
    std::cin >> ch;

    switch (ch) {
        case 1: std::cout << "Enter the rows to interchange (Enter 1 2 to change 1 and 2): " << '\n';
                std::cin >> r >> o;
                if ((ord < r) && (ord < o)){
                    std::cout << "Values greater than order of matrix (Out of range). Exiting." << '\n';
                    break;
                }
                --r;                    //Index starts with 0, but the matrix index starts with 1.
                --o;

                for (size_t i = 0; i < ord; i++) {
                    if (i==r) {
                        for (size_t j = 0; j < ord; j++) {
                            if ((i==r) && (j==o)){
                                for (size_t k = 0; k < ord; k++) {
                                    std::swap(row_matrix[i][k], row_matrix[j][k]); //Swapping the rows of provided matrix.
                                    if (inv == 1) {
                                        std::swap(elem_matrix[i][k], elem_matrix[j][k]); //Swapping the rows of elementary matrix.
                                    }
                                }
                                break;
                            }
                        }
                        break;
                    }
                }

                // Print to screen
                std::cout << '\n' << "The modified matrix is:" << "\n\n";
                print_matrix(ord, row_matrix);
                if (inv == 1) {
                    std::cout << "The modified elementary matrix is:" << "\n\n";
                    print_matrix(ord, elem_matrix);
                }

                // Print to file
                matrix_out << "R[i] <--> R[j]" << "\r\n\r\n";
                if (inv == 1) {
                    print_matrix(matrix_out, ord, row_matrix, elem_matrix);
                } else {
                    print_matrix(matrix_out, ord, row_matrix);
                }

                break;


        case 2: std::cout << "Enter the row : " << '\n';
                std::cin >> r;
                if (ord < r){
                    std::cout << "Values greater than order of matrix (Out of range). Exiting." << '\n';
                    break;
                }
                std::cout << "Enter the multiplier : " << '\n';
                std::cin >> m;
                --r;                    //Index starts with 0, but the matrix index starts with 1.

                for (size_t i = 0; i < ord; i++) {
                    if (i==r) {
                        for (size_t j = 0; j < ord; j++) {
                            row_matrix[i][j] *= m; // For provided matrix
                            if (inv == 1) {
                                elem_matrix[i][j] *= m; // For elementary matrix
                            }
                        }
                        break;
                    }
                }

                std::cout << '\n' << "The modified matrix is:" << "\n\n";
                print_matrix(ord, row_matrix);
                if (inv == 1) {
                    std::cout << "The modified elementary matrix is:" << "\n\n";
                    print_matrix(ord, elem_matrix);
                }

                matrix_out << "R[i] ---> k*R[i]" << "\r\n\r\n";
                if (inv == 1) {
                    print_matrix(matrix_out, ord, row_matrix, elem_matrix);
                } else {
                    print_matrix(matrix_out, ord, row_matrix);
                }

                break;


        case 3: std::cout << "Enter the row to be operated upon: " << '\n';
                std::cin >> r;
                std::cout << "Enter multiplier and the other operand row (seperated by space): " << '\n';
                m = 1;                   //By default, user can change by inputting.
                std::cin >> m >> o;
                if ((ord < r) && (ord < o)){
                    std::cout << "Values greater than order of matrix (Out of range). Exiting." << '\n';
                    break;
                }
                --r;                    //Index starts with 0, but the matrix index starts with 1.
                --o;

                for (size_t i = 0; i < ord; i++) {
                    if (i==r) {
                        for (size_t j = 0; j < ord; j++) {
                            if (j==o) {
                                for (size_t k = 0; k < ord; k++) {
                                    row_matrix[i][k] += m*row_matrix[j][k]; //Multiplying and adding the rows of provided matrix.
                                    if (inv == 1) {
                                        elem_matrix[i][k] += m*elem_matrix[j][k]; //Multiplying and adding the rows of elementary matrix.
                                    }
                                }
                                break;
                            }
                        }
                        break;
                    }
                }

                std::cout << '\n' << "The modified matrix is:" << "\n\n";
                print_matrix(ord, row_matrix);
                if (inv == 1) {
                    std::cout << "The modified elementary matrix is:" << "\n\n";
                    print_matrix(ord, elem_matrix);
                }

                matrix_out << "R[i] ---> R[i] + k*R[j]" << "\r\n\r\n";
                if (inv == 1) {
                    print_matrix(matrix_out, ord, row_matrix, elem_matrix);
                } else {
                    print_matrix(matrix_out, ord, row_matrix);
                }

                break;


        case 4: std::cout << "Enter the row to be operated upon: " << '\n';
                std::cin >> r;
                std::cout << "Enter multiplier and the other operand row (seperated by space): " << '\n';
                m = 1; //By default, user can change by inputting.
                std::cin >> m >> o;
                if ((ord < r) && (ord < o)){
                    std::cout << "Values greater than order of matrix (Out of range). Exiting." << '\n';
                    break;
                }
                --r;                    //Index starts with 0, but the matrix index starts with 1.
                --o;

                for (size_t i = 0; i < ord; i++) {
                    if (i==r) {
                        for (size_t j = 0; j < ord; j++) {
                            if (j==o) {
                                for (size_t k = 0; k < ord; k++) {
                                    row_matrix[i][k] -= m*row_matrix[j][k]; //Multiplying and adding the rows of provided matrix.
                                    if (inv == 1) {
                                        elem_matrix[i][k] -= m*elem_matrix[j][k]; //Multiplying and adding the rows of elementary matrix.
                                    }
                                }
                                break;
                            }
                        }
                        break;
                    }
                }

                std::cout << '\n' << "The modified matrix is:" << "\n\n";
                print_matrix(ord, row_matrix);
                if (inv == 1) {
                    std::cout << "The modified elementary matrix is:" << "\n\n";
                    print_matrix(ord, elem_matrix);
                }

                matrix_out << "R[i] ---> R[i] + k*R[j]" << "\r\n\r\n";
                if (inv == 1) {
                    print_matrix(matrix_out, ord, row_matrix, elem_matrix);
                } else {
                    print_matrix(matrix_out, ord, row_matrix);
                }

                break;


        case 5: break;


        default: std::cout << "Wrong choice!" << '\n';
                 break;
    }

    if (ch==5) {
        break;       //Exit from this do-while loop to go back to main.
    }

    std::cout << "Do you want to continue? (y/n)" << '\n';
    std::cin >> yn;
} while((yn == 'y')|| (yn == 'Y')); // while(ch == 'y'||'Y');

}

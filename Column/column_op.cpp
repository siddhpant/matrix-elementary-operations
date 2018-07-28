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
void column_operation(int ord, std::vector<std::vector<double> > column_matrix, int inv){

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
    print_matrix(matrix_out, ord, column_matrix, elem_matrix);
} else {
    print_matrix(matrix_out, ord, column_matrix);
}


int ch, c, m, o;    // choice, column, multiplier, other operand
char yn;            // Yes no at the end.
do {
    ch = c = m = 0;
    std::cout << '\n' << "Which operation?" << '\n';
    std::cout << "\t 1. C[i] <--> C[j]" << '\n';
    std::cout << "\t 2. C[i] ---> k*C[i]" << '\n';
    std::cout << "\t 3. C[i] ---> C[i] + k*C[j]" << '\n';
    std::cout << "\t 4. C[i] ---> C[i] - k*C[j]" << '\n';
    std::cout << "\t 5. Exit" << '\n';
    std::cout << "Enter your choice (1,2,3,4,5)" << '\n';
    std::cin >> ch;

    switch (ch) {
        case 1: std::cout << "Enter the columns to interchange (Enter 1 2 to change 1 and 2): " << '\n';
                std::cin >> c >> o;
                if ((ord < c) && (ord < o)){
                    std::cout << "Values greater than order of matrix (Out of range). Exiting." << '\n';
                    break;
                }
                --c;                  //Index starts with 0, but the matrix index starts with 1.
                --o;

                for (size_t i = 0; i < ord; i++) {
                    if (i==c) {
                        for (size_t j = 0; j < ord; j++) {
                            if (j==o) {
                                for (size_t k = 0; k < ord; k++) {
                                    std::swap(column_matrix[k][i], column_matrix[k][j]); //Swapping the columns of provided matrix.
                                    if (inv == 1) {
                                        std::swap(elem_matrix[k][i], elem_matrix[k][j]); //Swapping the columns of elementary matrix.
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
                print_matrix(ord, column_matrix);
                if (inv == 1) {
                    std::cout << "The modified elementary matrix is:" << "\n\n";
                    print_matrix(ord, elem_matrix);
                }

                //Print to file
                matrix_out << "C[i] <--> C[j]" << "\r\n\r\n";
                if (inv == 1) {
                    print_matrix(matrix_out, ord, column_matrix, elem_matrix);
                } else {
                    print_matrix(matrix_out, ord, column_matrix);
                }

                break;


        case 2: std::cout << "Enter the column : " << '\n';
                std::cin >> c;
                if (ord < c){
                    std::cout << "Values greater than order of matrix (Out of range). Exiting." << '\n';
                    break;
                }
                --c;                    //Index starts with 0, but the matrix index starts with 1.
                std::cout << "Enter the multiplier : " << '\n';
                std::cin >> m;

                for (size_t i = 0; i < ord; i++) {
                    if (i==c) {
                        for (size_t j = 0; j < ord; j++) {
                            column_matrix[j][i] *= m; // For provided matrix
                            if (inv == 1) {
                                elem_matrix[j][i] *= m; // For elementary matrix
                            }
                        }
                        break;
                    }
                }

                std::cout << '\n' << "The modified matrix is:" << "\n\n";
                print_matrix(ord, column_matrix);
                if (inv == 1) {
                    std::cout << "The modified elementary matrix is:" << "\n\n";
                    print_matrix(ord, elem_matrix);
                }

                matrix_out << "C[i] ---> k*C[i]" << "\r\n\r\n";
                if (inv == 1) {
                    print_matrix(matrix_out, ord, column_matrix, elem_matrix);
                } else {
                    print_matrix(matrix_out, ord, column_matrix);
                }

                break;


        case 3: std::cout << "Enter the column to be operated upon: " << '\n';
                std::cin >> c;
                std::cout << "Enter multiplier and the other operand column (seperated by space): " << '\n';
                m = 1;       // By default, user can change by inputting.
                std::cin >> m >> o;
                if ((ord < c) && (ord < o)){
                    std::cout << "Values greater than order of matrix (Out of range). Exiting." << '\n';
                    break;
                }
                --c;                    //Index starts with 0, but the matrix index starts with 1.
                --o;

                for (size_t i = 0; i < ord; i++) {
                    if (i==c) {
                        for (size_t j = 0; j < ord; j++) {
                            if (j==o) {
                                for (size_t k = 0; k < ord; k++) {
                                    column_matrix[k][i] += m*column_matrix[k][j]; //Multiplying and adding the columns of provided matrix.
                                    if (inv == 1) {
                                        elem_matrix[k][i] += m*elem_matrix[k][j]; //Multiplying and adding the columns of elementary matrix.
                                    }
                                }
                                break;
                            }
                        }
                    break;
                    }
                }

                std::cout << '\n' << "The modified matrix is:" << "\n\n";
                print_matrix(ord, column_matrix);
                if (inv == 1) {
                    std::cout << "The modified elementary matrix is:" << "\n\n";
                    print_matrix(ord, elem_matrix);
                }

                matrix_out << "C[i] ---> C[i] + k*C[j]" << "\r\n\r\n";
                if (inv == 1) {
                    print_matrix(matrix_out, ord, column_matrix, elem_matrix);
                } else {
                    print_matrix(matrix_out, ord, column_matrix);
                }

                break;


        case 4: std::cout << "Enter the column to be operated upon: " << '\n';
                std::cin >> c;
                std::cout << "Enter multiplier and the other operand column (seperated by space): " << '\n';
                m = 1;       // By default, user can change by inputting.
                std::cin >> m >> o;
                if ((ord < c) && (ord < o)){
                    std::cout << "Values greater than order of matrix (Out of range). Exiting." << '\n';
                    break;
                }
                --c;                    //Index starts with 0, but the matrix index starts with 1.
                --o;

                for (size_t i = 0; i < ord; i++) {
                    if (i==c) {
                        for (size_t j = 0; j < ord; j++) {
                            if (j==o) {
                                for (size_t k = 0; k < ord; k++) {
                                    column_matrix[k][i] -= m*column_matrix[k][j]; //Multiplying and adding the columns of provided matrix.
                                    if (inv == 1) {
                                        elem_matrix[k][i] -= m*elem_matrix[k][j]; //Multiplying and adding the columns of elementary matrix.
                                    }
                                }
                                break;
                            }
                        }
                    break;
                    }
                }

                std::cout << '\n' << "The modified matrix is:" << "\n\n";
                print_matrix(ord, column_matrix);
                if (inv == 1) {
                    std::cout << "The modified elementary matrix is:" << "\n\n";
                    print_matrix(ord, elem_matrix);
                }

                matrix_out << "C[i] ---> C[i] - k*C[j]" << "\r\n\r\n";
                if (inv == 1) {
                    print_matrix(matrix_out, ord, column_matrix, elem_matrix);
                } else {
                    print_matrix(matrix_out, ord, column_matrix);
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
} while((yn == 'y')||(yn == 'Y')); // while(ch == 'y'||'Y');

}

#include <iostream>
#include <utility>
#include <vector>
#include "../Show/show_matrix.h"


/*
ord = Order of square matrix.
Matrix = The matrix of given order.
*/
void column_operation(int ord, std::vector<std::vector<double> > column_matrix, int inv){

//Initializing elementary matrix.
std::vector<std::vector<double> > elem_matrix(ord, std::vector<double> (ord, 0.0));
for (size_t i = 0; i < ord; i++) {
    for (size_t j = 0; j < ord; j++) {
        if (i=j) {
            elem_matrix[i][j] = 1.0;
        }
    }
}

int ch, c, m, o;    // choice, column, multiplier, other operand
do {
    ch = c = m = 0;
    std::cout << "Which operation?" << '\n';
    std::cout << "\t 1. R[i] <--> R[j]" << '\n';
    std::cout << "\t 2. R[i] ---> k*R[i] " << '\n';
    std::cout << "\t 3. R[i] ---> R[i] + k*R[j]" << '\n';
    std::cout << "\t 4. R[i] ---> R[i] - k*R[j]" << '\n';
    std::cout << "\t 5. Exit" << '\n';
    std::cout << "Enter your choice (1,2,3,4,5)" << '\n';
    std::cin >> ch;

    switch (ch) {
        case 1: std::cout << "Enter the columns to interchange (Enter 1 2 to change 1 and 2): " << '\n';
                std::cin >> c >> o;
                if ((ord < c) && (ord < o)){
                    std::cout << "Values greater than order of matrix (Out of range). Exiting." << '\n';
                    exit(0);
                }

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

                std::cout << '\n' << "The modified matrix is:" << "\n\n";
                show_matrix(ord, column_matrix);
                if (inv == 1) {
                    std::cout << '\n' << "The modified elementary matrix is:" << "\n\n";
                    show_matrix(ord, elem_matrix);
                }

                break;


        case 2: std::cout << "Enter the column : " << '\n';
                std::cin >> c;
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
                show_matrix(ord, column_matrix);
                if (inv == 1) {
                    std::cout << '\n' << "The modified elementary matrix is:" << "\n\n";
                    show_matrix(ord, elem_matrix);
                }

                break;


        case 3: std::cout << "Enter the column to be operated upon: " << '\n';
                std::cin >> c;
                std::cout << "Enter multiplier and the other operand column (seperated by space): " << '\n';
                m = 1;       // By default, user can change by inputting.
                std::cin >> m >> o;

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
                show_matrix(ord, column_matrix);
                if (inv == 1) {
                    std::cout << '\n' << "The modified elementary matrix is:" << "\n\n";
                    show_matrix(ord, elem_matrix);
                }

                break;


        case 4: std::cout << "Enter the column to be operated upon: " << '\n';
                std::cin >> c;
                std::cout << "Enter multiplier and the other operand column (seperated by space): " << '\n';
                m = 1;       // By default, user can change by inputting.
                std::cin >> m >> o;

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
                show_matrix(ord, column_matrix);
                if (inv == 1) {
                    std::cout << '\n' << "The modified elementary matrix is:" << "\n\n";
                    show_matrix(ord, elem_matrix);
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
    std::cin >> ch;
} while(ch == 121||89); // while(ch == 'y'||'Y');

}

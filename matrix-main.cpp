#include <iostream>
#include <process.h>
#include <string.h>
#include "Show/help.h"
#include "Show/matrix_display.h"
#include "Row/row_op.h"
#include "Column/column_op.h"

int main(int argc, char const *argv[]) {

    std::cout << "------------------------------" << '\n';
    std::cout << "|MATRIX ELEMENTARY OPERATIONS|" << '\n';
    std::cout << "------------------------------" << '\n';
    std::cout << '\n' << "Run with -h to show help." << "\n\n";

    if ( strcmp(argv[1], "-h") == 0 ) {
        show_help();
        exit(0);
    }

    int order;                   //Order of matrix
    std::cout << "\n" << "Enter the order of the 2D square matrix : ";
    std::cin >> order;
    if (order > 6) {
        std::cout << "Order is large, do you really want to continue? (y/n) : ";
        char ord_conf;            //Order confirmation :P
        std::cin >> ord_conf;
        if ( (ord_conf != 'y') || (ord_conf != 'Y') ) {
            std::cout << "Order too large, exiting on user input." << '\n';
            exit(0);
        }
    }
    else if (order > 50 || order > 100) {
        std::cout << "Order is insanely large. Program might not handle it properly." << '\n';
        std::cout << "Do you really want to continue? (y/n) (Spoiler alert : Type n)" << '\n';
        char ord_conf;
        std::cin >> ord_conf;
        if ( (ord_conf != 'y') || (ord_conf != 'Y') ) {
            std::cout << "Order too large, exiting on user input." << '\n';
            exit(0);
        }
    }

    // Creating a 2D matrix of given dimensions using a 2D array, and setting all values to 0.
    double matrix[rows][columns] = {0};

    std::cout << "Enter the values of the matrix, values in a row (column values) seperated by a space, "
              << "then press enter (newline) to enter new row:" << '\n';
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < columns; j++) {
            std::cin >> matrix[i][j];
        }
    }

    int choice;
    std::cout << "What do you want to do?" << '\n';
    std::cout << "\t 1. Apply row operations." << '\n';
    std::cout << "\t 2. Apply column operations." << '\n';
    std::cout << "Enter your choice (1,2) : " << '\n';
    std::cin >> choice;

    char yn;
    std::cout << "\n" << "You can apply same operations to a elementary matrix if you want to find inverse." << '\n';
    std::cout << "Do you want to find inverse? (y/n)" << '\n';
    std::cin >> yn;

    int inverse = 0;
    if ( (yn == 'Y')|| (yn == 'y') ) {
        inverse = 1;             //To indicate that the user wants to find inverse.
    }

    if (choice == 1) {
        row_operation(order, matrix, inverse);
    } else if (choice == 2) {
        std::cout << '\a' << "COLUMN OPERATION CAN CHANGE THE LINEAR SYSTEM!"<< '\a' << '\n';
        std::cout << "Proceed at your own risk" << '\n';
        column_operation(order, matrix, inverse);
    } else {
        std::cout << "WRONG CHOICE! Exiting." << '\n';
        exit(0);
    }

    std::cout << "Performed all elementary operations!" << '\n';
    return 0;
}
#include <iostream>
#include <vector>
#include <fstream>

//To print to screen without elementary matrix.
void print_matrix(int ord, std::vector<std::vector<double> > Matrix) {

    for (size_t i = 0; i < ord; i++) {
        std::cout << '\n';
        for (size_t j = 0; j < ord; j++) {
            std::cout << Matrix[i][j] << '\t';
        }
    }

    std::cout << '\n' << std::endl;

}


//Print to screen with elementary matrix.
void print_matrix(int ord, std::vector<std::vector<double> > Matrix, std::vector<std::vector<double> > elem_matrix) {

    for (size_t i = 0; i < ord; i++) {
        std::cout << '\n';

        for (size_t j = 0; j < ord; j++) {
            std::cout << Matrix[i][j] << '\t';
        }

        std::cout << "                                         ";

        for (size_t j = 0; j < ord; j++) {
            std::cout << elem_matrix[i][j] << '\t';
        }
    }

    std::cout << '\n' << std::endl;

}


//To print only operand matrix to file
void print_matrix(std::ofstream &tofile, int ord, std::vector<std::vector<double> > Matrix){

    for (size_t i = 0; i < ord; i++) {
        tofile << "\r\n";
        for (size_t j = 0; j < ord; j++) {
            tofile << Matrix[i][j] << '\t';
        }
    }

    tofile << "\r\n";       // For Windows files.
    tofile << "----------------------------------------------------------------";
    tofile << "\r\n";
    tofile << std::endl;

}


//To print both operand and elementary matrix.
void print_matrix(std::ofstream &tofile, int ord, std::vector<std::vector<double> > Matrix, std::vector<std::vector<double> > elem_matrix){

    for (size_t i = 0; i < ord; i++) {
        tofile << "\r\n";

        for (size_t j = 0; j < ord; j++) {         //Printing elementary matrix.
            tofile << elem_matrix[i][j] << '\t';
        }

        tofile << "                                         ";

        for (size_t j = 0; j < ord; j++) {         // Printing operand matrix
            tofile << Matrix[i][j] << '\t';
        }

    }

    tofile << "\r\n";
    tofile << "----------------------------------------------------------------";
    tofile << "\r\n";
    tofile << std::endl;

}

#pragma once

// To print matrix to the screen
void print_matrix(int ord, std::vector<std::vector<double> > Matrix);

// To actually output the result to a file using the filestream created.

// To output only the matrix provided.
void print_matrix(std::ofstream &tofile, int ord, std::vector<std::vector<double> > Matrix);

// To output the provided matrix along with inverse.
void print_matrix(std::ofstream &tofile, int ord, std::vector<std::vector<double> > Matrix,
                  std::vector<std::vector<double> > elem_matrix);

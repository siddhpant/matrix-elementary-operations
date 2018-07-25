/*
ord = Order of square matrix.
Matrix = The matrix of given order.
*/
void row_operation(int ord, float Matrix[ord][ord], int inv){

//Initializing elementary matrix.
float elem_matrix[ord][ord] = {0};
for (size_t i = 0; i < ord; i++) {
    for (size_t j = 0; j < ord; j++) {
        if (i=j) {
            elem_matrix[i][j] = 1;
        }
    }
}

int ch, r, m, o;
do {
    ch = r = m = 0;
    std::cout << "Which operation?" << '\n';
    std::cout << "\t 1. R[i] <--> R[j]" << '\n';
    std::cout << "\t 2. R[i] ---> k*R[i] " << '\n';
    std::cout << "\t 3. R[i] ---> R[i] + k*R[j]" << '\n';
    std::cout << "\t 4. R[i] ---> R[i] - k*R[j]" << '\n';
    std::cout << "\t 5. Exit" << '\n';
    std::cout << "Enter your choice (1,2,3,4,5)" << '\n';
    std::cin >> ch;

    switch (ch) {
        case 1: std::cout << "Enter the rows to interchange (Enter 1 2 to change 1 and 2): " << '\n';
                std::cin >> r >> o;
                if ((ord < r) && (ord < o){
                    std::cout << "Values greater than order of matrix (Out of range). Exiting." << '\n';
                    exit(0);
                }
                for (size_t i = 0; i < ord; i++) {
                    for (size_t j = 0; j < ord; j++) {
                        if ((i==r) && (j==o)){
                            for (size_t k = 0; k < ord; k++) {
                                std::swap(Matrix[i][k], Matrix[j][k]) //Swapping the rows of provided matrix.
                                if (inv == 1) {
                                    std::swap(elem_matrix[i][k], elem_matrix[j][k]) //Swapping the rows of elementary matrix.
                                }
                            }
                            break;
                        }
                    }
                }
                show_matrix(do_it_later_man);
                break;


        case 2: std::cout << "Enter the row : " << '\n';
                std::cin >> r;
                std::cout << "Enter the multiplier : " << '\n';
                std::cin >> m;
                for (size_t i = 0; i < ord; i++) {
                    if (i==r) {
                        for (size_t j = 0; j < ord; j++) {
                            Matrix[i][j] *= m; // For provided matrix
                            if (inv == 1) {
                                elem_matrix[i][j] *= m; // For elementary matrix
                            }
                        }
                        break;
                    }
                }
                show_matrix(do_it_later_man);
                break;


        case 3: std::cout << "Enter the row to be operated upon: " << '\n';
                std::cin >> r;
                std::cout << "Enter multiplier and the operand row (seperated by space): " << '\n';
                std::cin >> m >> o;
                for (size_t i = 0; i < ord; i++) {
                    for (size_t j = 0; j < ord; j++) {
                        if ((i==r) && (j==o)){
                            for (size_t k = 0; k < ord; k++) {
                                Matrix[i][k] += m*Matrix[j][k]; //Multiplying and adding the rows of provided matrix.
                                if (inv == 1) {
                                    elem_matrix[i][k] += m*elem_matrix[j][k]; //Multiplying and adding the rows of elementary matrix.
                                }
                            }
                            break;
                        }
                    }
                }
                show_matrix(bharo-ise);
                break;


        case 4: std::cout << "Enter the row to be operated upon: " << '\n';
                std::cin >> r;
                std::cout << "Enter multiplier and the operand row (seperated by space): " << '\n';
                std::cin >> m >> o;
                for (size_t i = 0; i < ord; i++) {
                    for (size_t j = 0; j < ord; j++) {
                        if ((i==r) && (j==o)){
                            for (size_t k = 0; k < ord; k++) {
                                Matrix[i][k] -= m*Matrix[j][k]; //Multiplying and adding the rows of provided matrix.
                                if (inv == 1) {
                                    elem_matrix[i][k] -= m*elem_matrix[j][k]; //Multiplying and adding the rows of elementary matrix.
                                }
                            }
                            break;
                        }
                    }
                }
                show_matrix(bharo-ise);
                break;


        case 5: std::cout << "Okay, exiting." << '\n';
                exit(0);


        default: std::cout << "Wrong choice!" << '\n';
                 break;
    }

    std::cout << "Do you want to continue? (y/n)" << '\n';
    std::cin >> ch;
} while(ch == 121||89); // while(ch == 'y'||'Y');

}

#include <iostream>

void show_help(void) {

    std::cout << "This is a program to perform elementary matrix operations PROVIDED BY USER." << '\n';
    std::cout << "This program does NOT automatically calculate inverse!" << "\n\n";

    std::cout << "This program is useful when you want to carry out "
              << "some elementary operations manually, or when you want to "
              << "cross check your own steps." << "\n\n";

    std::cout << "The program also outputs all the row operations "
              << "along with the matrix formed to a text file \" Matrix [YY/MM/DD] [HH:MM:SS].txt \" for "
              << "easy future reference. (Current date and time (UTC) in file name.)" << '\n'
              << "If you are on Windows, the colon in time might look like a bullet point." << "\n\n";

    std::cout << "Since doing elementary operations on a rectangular matrix is meaningless, "
              << "the program just asks for the order of the square matrix "
              << "which is to be operated upon." << "\n\n";

    std::cout << "You have to enter your entire row of matrix in one line, "
              << "and press enter (newline) for entering the other row." << "\n";

    std::cout << "For example, entering a 2x2 matrix is like" << '\n';
    std::cout << "1 2 \t\t <--- Row 1, now press enter." << '\n';
    std::cout << "3 4 \t\t <--- Row 2, now press enter." << "\n\n";

    std::cout << "You can apply the same operations to an elementary matrix "
              << "if you want to find an inverse. Just tell yes when asked." << "\n\n";


    std::cout << "Then follow the on-screen instructions to perform the operations" << '\n';
    std::cout << "They are just inputting your row/column number and multiplier. Easy!" << "\n\n";

}

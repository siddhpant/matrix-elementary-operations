# Matrix Elementary Operations

This program performs elementary operations on the square matrix, both provided by the user. Also outputs to a file.

Users can also perform the same on an elementary matrix if they want. Particularly useful when finding inverses using operations.

***NOTE : This is not an automatic inverse finder!***


## Compilation

```g++ Print/help.cpp Print/print_matrix.cpp Row/row_op.cpp Column/column_op.cpp matrix-main.cpp -o matrix_elementary_operations```

## Use

```./matrix_elementary_operations```

Run with -h for help `./matrix_elementary_operations -h`

You can find your operations, along with matrices, logged in a text file named `Matrix [YY/MM/DD] [HH:MM:SS].txt`. Time is in UTC.

Used [Howard Hinnant's free, open-source header-only datetime library](https://howardhinnant.github.io/date/date.html) for date and time. It is available as `Print/date.h` in this repository.

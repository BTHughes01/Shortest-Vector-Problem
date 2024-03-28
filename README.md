# Shortest Vector Problem Using Lenstra–Lenstra–Lovász lattice basis reduction algorithm
This is a project I developed for my Systems Programming coursework. I achieved a mark of 96% for this work with 100% on the coding section. It is programmed in C with a makefile.

## Building
To build the program, follow these steps:

1. Ensure you have `gcc` installed on your system.
2. Clone this repository to your local machine.
3. Navigate to the root directory of the cloned repository.
4. Open a terminal window and run the following command:
    ```bash
    make
    ```
5. This will compile the program using `gcc` with specified flags.

## Run Instructions
To run the program, follow these steps:

1. After building the program, navigate to the root directory of the repository.
2. Open a terminal window.
3. Run the following command:
    ```bash
    ./runme [arguments]
    ```
   Replace `[arguments]` with the square input vectors, exaples can be seen in the makefile.

## Test Instructions
To test the program, follow these steps:

1. After building the program, navigate to the root directory of the repository.
2. Open a terminal window.
3. Run the following command:
    ```bash
    make test
    ```
Additionally, there are specific commands available for running harder test cases:
- `make hardtest1`
- `make hardtest2`
- `make hardtest3`
- `make hardtest4`

You can also run the basis test using:
```bash
make basistest
```

4. This will execute the program with predefined test cases.

## Cleaning Up
To clean up generated files, run the following command:
```bash
make clean

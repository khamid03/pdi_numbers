
# PDI Numbers Simulation with Multithreading

This project is a C program designed to simulate or process PDI (Presumably Definable Integer) numbers using multithreading. The program allows users to define parameters for the range of numbers and the number of threads for processing, along with additional options for error tracing.

## Program Description

The program processes PDI numbers within a specified range and allows for concurrent processing using multiple threads. The command-line options enable users to control the range of numbers, set the number of threads, and activate error tracing.

## Command-Line Options

The program supports the following command-line options:

- **`-s <start>`**: Specifies the starting value of the range. This is the lower bound of numbers to process.
- **`-e <end>`**: Specifies the ending value of the range. This is the upper bound of numbers to process.
- **`-t <threads>`**: Sets the number of threads to use for concurrent processing. The program will exit if the number of threads is set to zero or negative, as threads cannot be less than or equal to zero.
- **`-v`**: Activates standard error tracing. This option, when set, enables verbose logging for error tracking, helping in debugging or detailed monitoring of the program's execution.

### Example Usage

```bash
./pdi_numbers -s 100 -e 1000 -t 4 -v
```

In this example:
- The program will process PDI numbers from 100 to 1000.
- It will use 4 threads for parallel processing.
- Error tracing will be enabled to track the process.

## Requirements

- A C compiler, such as GCC.
- Standard libraries for threading and other basic functionalities.

## Compilation and Execution

1. **Compile the code** using a C compiler:
   ```bash
   gcc -o pdi_numbers pdi-numbers.c -lpthread
   ```

2. **Run the program** with desired command-line options:
   ```bash
   ./pdi_numbers [-s start] [-e end] [-t threads] [-v]
   ```

## Error Handling

If an invalid option is provided or if the thread count (`-t`) is set to zero or below, the program will output an error message and terminate. Proper use of options ensures smooth execution.

## License

This project is open-source and available under the MIT License.

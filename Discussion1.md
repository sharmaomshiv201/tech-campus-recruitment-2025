 Solutions Considered:
Approach 1 :
Initially, I considered reading the entire file into memory and filtering the logs for the specified date. However, this approach is inefficient for large files (1 TB) as it would consume a lot of memory.

Approach 2 :
This approach reads the file line-by-line and checks if the date matches the specified input. It's memory efficient and scales well for large files. This approach was chosen because it minimizes memory usage and allows the program to handle the large file sizes efficiently.
Chosen Approach:
I chose the line-by-line reading approach because it efficiently handles the file size constraints. The program only keeps necessary logs for the given date in memory, making it ideal for large log files.

Why This Solution:
It optimizes memory usage while maintaining good performance. Additionally, using a buffered read helps speed up file reading for large files. Given the 1 TB file size, this approach ensures that only the required data is stored, which avoids issues with memory overflow.

## Steps to Run

1. Clone the repository to your local machine.
   ```bash
   git clone https://github.com/yourusername/repository-name.git
   cd repository-name

  2. To compile the code
   g++ extract_logs.cpp -o extract_logs

3. Run the program with a specific date (in YYYY-MM-DD format):
./extract_logs 2024-12-01


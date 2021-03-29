# Time to Code

## Problem Statement

### Problem Statement - 2A
* Write functions to **read** from a **Comma Separated Value(CSV)** file and display each line.
* Example file: **test.csv**
```
  Name, Email_ID, Github_Link
  yourname, youremailID, yourgithublink
  yourfriendname, yourfriendemailID, yourfriendsgithublink
```
* Output:
```
  Name = Yourname
  EmailID = youremailID
  GitHub Link = Your Github link...so on.
```
* Refer to [data.csv](data.csv) file for example.

### Problem Statement - 2B
* Store the extracted data in the above step into an **Array of below structure**:
```
typedef struct info_t {
    char* name;
    char* email_id;
    char* git_link;
} info_t;
```
* Write a function to **sort the data** in the array in the **alphabetical order of names**.

## Guidelines:
### Programming
* **Do not use scanf functions**. Assume test values for arguments to functions.
* Implement different functions for each operation instead of writing everything under main function.
* Create a **header file**,  **source code file** and **test file**.
* Use **Dynamic memory** wherever possible.

### Tool usage
* Write **Unit test** cases for each function.
* **Makefile** for **compilation**, **running test** cases and additional targets.
* Create **Documentation** using **Doxygen**.
* Use **cppcheck** and **Valgrind** tools to analyze the code.


## Resources:
* What is a [CSV File](https://www.howtogeek.com/348960/what-is-a-csv-file-and-how-do-i-open-it/)
* [File Handling in C, In Just A Few Hours!](https://aticleworld.com/file-handling-in-c/)

## Solutions
* By [Nikhil Nevin Vas](https://github.com/nikhilvas123/MiniProject_Template/tree/solution_2a/Example_Programs/programming_concpets/Questions_2a)
* By [Milan Apegaonkar](https://github.com/255934/Q_2_sol/tree/master)
* By [Arnob Chowdhury-256131](https://github.com/arc-arnob/LnT-Assignments/tree/master/Questions_2a)
* By [Rohan Gupta](https://github.com/256018/Question2)
* By [Hemanth A - 256889 - assignment 2a and 2b](https://github.com/hemanth-asapu/demoproj1/tree/main/assignment_2a_2b)
* By [Shravya K N](https://github.com/28-shravya/Solution-for-Question2a-StepIn.git)
* By [Ayushman 255949](https://github.com/255949/CSV_Read)

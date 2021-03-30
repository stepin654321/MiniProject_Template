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
*  258274 https://github.com/Ankana9910/Begin.git

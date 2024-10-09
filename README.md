This program is a very simplified version of Excel. 

Running this program will display a menu with options to modify a spreadsheet filled with information from a made up textfile.

It written in C.

There is a lack of error handling, examples of this include:

- Users can input an incorrect student number and the program will keep running without warning, however won't execute the desired option.
- Users can input names and values larger than the maximum allocated size which will create out of bound errors
  - We are assuming that the user will input the correct input
- Malloc was not used to create the "Array" of students, therefore lacks flexibility in terms of size, however the size of the struct is decremented as we deleted students

There is also a lack of options like adding a student, you can only remove a student from the provided textfile.

# C-Assignment-1

Assignment 1



Problem Statement

Assume there is a text file contains some information. You should assume the name of the text file is always fixed and at the time you run your application can be found in the same directory as your “.exe” file does exist. Let’s name the file inData.txt. Your job is to open the file and process its contents and produce another text file outData.txt. 


inData.txt File Format

The file format is as follows:

RectangleWidth     RectangleHeight
CircleRadius

FirstName  LastName     Age
Saving

{
May be there are more data in the rest of the file but the pattern is the same.
}

Here is an example of inData.txt file:


10.20       5.35
15.6

Randy Gill     31
18500 




34.41       78.18
35.1

Mike Gale       28
26100 


In this example there are two rectangles, circles, and people’s data. But you shouldn’t assume there is only 2 or 3 or any number for the pattern.

The numbers in the first line represent the length and width, respectively, of a rectangle. 
The number in the second line represents the radius of a circle. The third line contains the first name, last name, and the age of a person. The first number in the fourth line is the savings account balance at the beginning of the month. This pattern is repeated in the file, i.e, there are more rectangles, circles, and person savings.
(Use M_PI for value of PI. You should use the “cmath” library in order to use M_PI.) 

outData.txt File Format
During a loop you should read the contents of inData.txt and find aggregation of all data you read from inData.txt. 

The aggregation contains:

For Rectangle: 1. Total lengths 2. Total widths 3. Total areas 4. Total perimeters of all rectangles

For Circle: 1. Total radiuses 2. Total areas 3. Total circumferences of all circles

For Persons: 1. Total number 2. Total ages 3. Total saving of persons


Here is an example for contents outData.txt which your application should generate by reading inData.txt example shown above.





-----
Rectangle:
The total lengths= 44.61, width = 83.53, area = 2744.74, 
Perimeter  = 128.14

Circle:
The total Radius = 50.70, area = 764.52, circumference = 98.02

Person:
Total number of persons= 2
Total Age= 59
The total saving= 44600 
------




How to Implement
You need to define some variables for aggregated data such as: 

int sumAge;   

For finding the total person’s age. You need to define other variables for other aggregated data to be represented in outData.txt. 

The next step is open the file inData.txt. 
Define a loop for reading data inData.txt and updating aggregated variables defined in step 1.
After the loop is finished, the aggregated data should be stored in outData.txt exactly shown above.
Write statements that close the input and output files.


Rules to be Obeyed
You should follow the following guidelines:
Call this program assign1.cpp. Early lines of your code should contain following lines:

/*
Student Name: $$$$$$$
Student Number: #######
*/

Enter you student name instead of $$$$$$$ and student number instead of #######.

In Blackboard, submit only assign1.cpp file without compression to zip or rar file. If you compress the file you will receive zero for this assignment.

Your program should be general enough so that if the content of the input file is changed (but it keeps its format and only white spaces may be varies) and the program is run again (without editing and recompiling), it outputs the appropriate results in inData.txt. Note that all float point numbers are presented by two decimal point and they are rounded beyond after two decimal numbers. 

If there is an error during reading inData.txt, your code should take care of the situation, i.e., consider a zero for that particular input that makes the error if you are expecting a number. For example if there is a character ‘A’ instead of width of a rectangle, you should consider a zero for the width and proceed for the rest of data in inData.txt. For any other possible errors, just clear the error and proceed reading the rest of inData.txt.


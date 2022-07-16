## SysWiz - File Tagging feature 
## Graphical User Interface :

![image](https://user-images.githubusercontent.com/92429666/179373802-4a0f020e-8762-4e89-a538-4fa7ee2737e7.png)

The GUI offers two basic functionalities -
1. Search a file using tag.
2. Create a tag for a file.


## Approach - 1
The GUI and logic of file tagging were implemented using C++.
We tried to store the data entered by user in a Map data structure which had string and a set of strings as datatype or 
           ``` 
            map<string,set<string>> myMap
            ```
here we chose the tag as the key and set of path of the file as values. Set of path of file to ensure our database doesn't have redundancy.
Next we tried to store the file tags in a database so as to ensure that our tagged files don't lose their tags after memory is refreshed/ after boot.
The obvious choice was to use a NoSQL database, since data in a NoSQL database are stored as [key,value] pairs retrival would cost ```O(log(n))``` time.
We didn't opt for Relational Database as all the data is stored in form of tables and searching would cost ```O(n)```.

We chose MongoDB as our NoSQL database as it has support for C++. 


![image](https://user-images.githubusercontent.com/92429666/179373789-1dc764a3-b0e1-44b0-8727-7bf9a670b219.png)


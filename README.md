# KNN algorithm to determine the type of an iris

**This project was made by Daniel Assa and Daniel Lifshitz.**
## Type finding by server
The server is currently meant to implement the KNN algorithm with iris types, for a given unclassified iris, we find its *K CLOSEST NEIGHBOURS* in $O\left(n\right)$ and from them determine its type,
using the following three different types of irises: *setosa*, *virgincia*, *versicolor*. 
## Files sent by the client
The client sends the server a file of unclassified iris types, the server classifies them and sends the client the file with the classified types.
## Run the code
### Requirements


The server should have a file ```classified.csv``` in it's working directory full of classified Iris, which contains in each line $5$ columns, for example, the contents of the file should look like this:  
```
5.4,3.9,1.7,0.4,Iris-versicolor
4.6,3.4,1.4,0.3,Iris-setosa
5.0,3.4,1.5,0.2,Iris-virginica
```
The numbers in each column correspond to a feature of the iris:
1. The iris' width
2. The iris's sepal length
3. The iris's sepal width
4. The iris' petal length
5. The iris' type, from the types stated above.  
  
  
The client must also receive a file ```Unclassified.csv``` which contains the same contents as the ```classified.csv``` file, but it misses the type column (or the fifth column), thus making it a file of "unclassified" irises.  
### Compile and run
The project has a given ```Makefile``` for you to use when compiling the code.
In order to compile the server code type in:
```
make server
```
and to run it:
```
./server
```
And the same goes for the client, run this client command after you've run the server command (and while it's running):
```
make client
```
and to run it:
```
./client Data/unclassified.csv Output/classified.csv
```
***In Linux.***    
Where these paths are an example for the pathes where you would have the ```unclassified.csv``` file and the path for the future ```classified.csv``` file.  
**Remember** the ```unclassified.csv``` file is the file the client sends to the server that **needs to exists beforehand**, and the ```classified.csv``` file is the file which will have the types from the irises sent from the server, meaning this file doesn't have to exist, the program can create it. 
Here $k=9$ defaultly.

### Files in working directories
You must have a ```classified.csv``` file in the server's working directory and a '```unclassified.csv``` file for the client (this is the file for which you supply a path at the command line).


## Output
The server sends the client data which will be kept in the ```classified.csv``` file, the same one whose path you will give when running the client. 
For example: 
```
Iris-setosa
Iris-virginica
Iris-virginica
Iris-versicolor
```





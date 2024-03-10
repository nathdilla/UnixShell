#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib> // For rand() and srand()
#include <ctime> // For time()

using namespace std;

int main() {
  ifstream inputFile("virtualMemory.txt");
  string* firstArray;
  string* secondArray;
  string line;
  int firstArraySize = 0;
  int secondArraySize = 0;
  int lineCount = 0;

  // Seed the random number generator
  srand(time(0));

  // Count the number of lines in the file
  while (getline(inputFile, line)) {
    lineCount++;
  }

  // Set the size of the first array
  firstArraySize = lineCount;
  firstArray = new string[firstArraySize];

  // Reset the file pointer to the beginning of the file
  inputFile.clear();
  inputFile.seekg(0, ios::beg);

  // Read lines from the file and store them in the first array
  for (int i = 0; i < firstArraySize; i++) {
    getline(inputFile, line);
    firstArray[i] = line;
  }

  // Set the size of the second array
  secondArraySize = 2 * firstArraySize;
  secondArray = new string[secondArraySize];

  for (int i = 0; i < firstArraySize; i++) {
    cout << "PAGE[" << i << "] : " << firstArray[i] << endl;
  }
  cout << "\n";
  // Iterate through the firstArray
  for (int i = 0; i < firstArraySize; i++) {
    // Generate a random index in the secondArray
    int randomIndex = rand() % secondArraySize;

    // Check if the cell at the random index is already populated
    while (!secondArray[randomIndex].empty()) {
      // Find another random index
      randomIndex = rand() % secondArraySize;
    }

    // Populate the cell at the random index with the value from the firstArray
    secondArray[randomIndex] = firstArray[i];
    cout <<  "PAGE[" << i << "] : " << firstArray[i] << " -> FRAME[" << randomIndex << "] : " << secondArray[randomIndex] << endl;
  }
  cout << "\n";
  // print secondArray
  for (int i = 0; i < secondArraySize; i++) {
    cout << "FRAME[" << i << "] : " << secondArray[i] << endl;
  }


  return 0;
}

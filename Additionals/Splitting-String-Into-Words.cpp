// C++ Program to Split a Sentence into Words using stringstream
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

vector<string> split_sentence(string sen) {
  
    // Create a stringstream object
    stringstream ss(sen);
    
    // Variable to hold each word
    string word;
    
    // Vector to store the words
    vector<string> words;
    
    // Extract words from the sentence
    while (ss >> word) {
      
        // Add the word to the vector
        words.push_back(word);
    }
    
    return words;
}

int main() {
    string sen = "Geeks for Geeks";
    
    // Call the function to split the sentence
    vector<string> words = split_sentence(sen);
    
    for (string w : words) {
        cout << w << endl;
    }
    
    return 0;
}
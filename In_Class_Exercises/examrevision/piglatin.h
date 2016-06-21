#ifndef PIGLATIN_H
#define PIGLATIN_H

#include <fstream>
#include <ostream>

using namespace std; 

int findFirstVowel(const char* word);

bool isVowel(char ch, int position , int length);

void translateWord(const char* eng, char* piglat);

void translateStream(ifstream& inputStream,ostream& outputStream);


#endif

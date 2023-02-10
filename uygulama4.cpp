#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <fstream>
#include <experimental/filesystem> //filesystem, c++ ta klasorun icindeki dosyalari gezmeye yarayan bir kutuphane

using namespace std;
string directorySample = "C:\\Users\\Bilgehan Kaplan\\Desktop\\Chomar"; 

vector<char> malwareVector;
namespace fs = std::experimental::filesystem;

// getfileNameList fonksiyonu, bir klasoru parametre alir,
// bu klasorun icini gezer ve icindeki dosyalarin isimlerini bir vector'e yazar.
vector<string> getFileNameList(string directory)
{
    vector<string> result;

    std::string path = directory;

    for (const auto& entry : fs::directory_iterator(path)) // klasorun icinde gezinme
    {
        result.push_back(entry.path().u8string()); // result vector'une bulunan dosyalari ekleme
    }

    return result;
}

// Verilen dosyayi byte byte okuyarak, elde ettigi byte'lari bir vectore atama.
vector<char> readFile(string fileName)
{
    vector<char> result;
    char ch;
    fstream fin(fileName, fstream::in);
    while (fin >> noskipws >> ch) {
        result.push_back(ch);
    }

    return result;
}

void initializeMalwareVector()
{
    char m0 = 'M';
    char m1 = 'A';
    char m2 = 'L';
    char m3 = 'W';
    char m4 = 'A';
    char m5 = 'R';
    char m6 = 'E';

    malwareVector.push_back(m0);
    malwareVector.push_back(m1);
    malwareVector.push_back(m2);
    malwareVector.push_back(m3);
    malwareVector.push_back(m4);
    malwareVector.push_back(m5);
    malwareVector.push_back(m6);
}

int isContains(vector<char> source, vector<char> find)
{
    int result = -1;

    int sourceSize = source.size();
    int findSize = find.size();

    if (sourceSize < findSize)
    {
        return result;
    }

    for (int i = 0; i < sourceSize; i++)
    {
        bool contains = true;

        for (int j = 0; j < findSize; j++)
        {
            contains = contains && (source[i + j] == find[j]);
        }

        if (contains)
        {
            return i;
        }
    }

    return result;
}

int main(int argc, char* argv[])
{
    std::string directory;

    if (argc > 1)
    {
        directory = std::string(argv[1]);
    }
    else
    {
        directory = directorySample;
    }

    initializeMalwareVector();

    vector<string> fileNameList = getFileNameList(directory);

    int fileCount = fileNameList.size();

    for (int i = 0; i < fileCount; i++)
    {
        string filename = fileNameList[i];

        vector<char> list = readFile(filename);
        
        if((list[0]=="M")&&(list[1]=="Z")){    //Dosyanin Portable Executable kontrolu
		
        int malware = isContains(list, malwareVector);
        if (malware != -1)
        {
            cout << filename << ":" << "BULUNDU (" << malware <<  " adresinde)" << endl;
        }
        else
        {
            cout << filename << ":" << "BULUNAMADI" << endl;
        }
    }
    }

}

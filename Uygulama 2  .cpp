#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

string directorySample = "C:\\Users\\Bilgehan Kaplan \\Desktop\\chomar malware";
vector<char> malwareVector;

// Verilen dosyayý byte byte okuyarak, elde ettigi byte'larý bir vectore atama.
vector<char> readFile(string fileName)
{
    vector<char> result;
    char ch;
    ifstream fin;  
  fin.open("C:\\Users\\Bilgehan Kaplan\\Desktop\\chomar malware.txt"); // Dosyadan okuma iþlemi için açma
  
    while (fin >> noskipws >> ch) {
        result.push_back(ch);
    }

    return result;
}

void initializeMalwareVector() //"MALWARE" ifadesini atama
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

// Verilen dosya yolunda "MALWARE" ifadesini arayan fonksiyon
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
    
        directory = directorySample;

    initializeMalwareVector();

        string filename = directory;

        vector<char> list = readFile(filename);

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

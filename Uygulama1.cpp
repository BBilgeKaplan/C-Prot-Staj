#include <iostream>
#include <fstream>
using namespace std;

int main(){
  char character;
  
  // Dosyadan okuma iþlemi için akýþ oluþturma
  ifstream File;  
  File.open("C:\\Users\\Bilgehan Kaplan\\Desktop\\chomar malware.txt");
 
 // Dosya açma hata kontrolü
  if(!File) {                    
     cout << "dosya açýlamadý!";
     exit(1);
  }  

  if ( File.is_open() ){
  	
    // Dosyanýn ilk iki bytýný yazdýrma
    for(int i=0; i<2; i++)
	{
   		File.get(character);
		cout << character;	
	}     
  }
  
  // Dosyayý kapatma
  File.close();

  return 0;
}

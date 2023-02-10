#include <iostream>
#include <fstream>
using namespace std;

int main(){
  char character;
  
  // Dosyadan okuma işlemi için akış oluşturma
	
  ifstream File;  
  File.open("C:\\Users\\Bilgehan Kaplan\\Desktop\\chomar malware.txt");
 
 // Dosya açma hata kontrolü
	
  if(!File) {                    
     cout << "dosya açılamadı!";
     exit(1);
  }  

  if ( File.is_open() ){
  	
    // Dosyanın ilk iki bytını yazdırma
	  
    for(int i=0; i<2; i++)
	{
   		File.get(character);
		cout << character;	
	}     
  }
  
  // Dosyayı kapatma
	
  File.close();

  return 0;
}

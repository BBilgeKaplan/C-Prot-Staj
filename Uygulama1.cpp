#include <iostream>
#include <fstream>
using namespace std;

int main(){
  char character;
  
  // Dosyadan okuma i�lemi i�in ak�� olu�turma
  ifstream File;  
  File.open("C:\\Users\\Bilgehan Kaplan\\Desktop\\chomar malware.txt");
 
 // Dosya a�ma hata kontrol�
  if(!File) {                    
     cout << "dosya a��lamad�!";
     exit(1);
  }  

  if ( File.is_open() ){
  	
    // Dosyan�n ilk iki byt�n� yazd�rma
    for(int i=0; i<2; i++)
	{
   		File.get(character);
		cout << character;	
	}     
  }
  
  // Dosyay� kapatma
  File.close();

  return 0;
}

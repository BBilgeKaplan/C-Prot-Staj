# [C-Prot](https://www.chomar.com.tr/tr-tr/sayfa.aspx)
Bu repo C-Prot (Chomar) staj süresi boyunca yapılması istenen çalışmaları içermektedir.


### [Uygulama 1](https://github.com/BBilgeKaplan/C-Prot-Staj/blob/main/Uygulama1.cpp)
Program çalıştırıldığında, kodun içerisinde tam yolu verilecek olan bir dosyanın ilk 2 baytı okunup ekrana yazdırılması sağlanmalıdır.
 
### [Uygulama 2](https://github.com/BBilgeKaplan/C-Prot-Staj/blob/main/Uygulama%202%20%20.cpp)
Program çalıştırıldığında, kodun içerisinde tam yolu verilecek olan bir dosya okunarak içeresinde “MALWARE” ifadesi aranmalıdır. Bulunduğu noktanın offset değeri ekrana yazdırılmalıdır.
 
### [Uygulama 3](https://github.com/BBilgeKaplan/C-Prot-Staj/blob/main/Uygulama3.cpp)
Program çalıştırıldığında, programa argüman olarak verilecek bir klasör içerisindeki tüm dosyaları (alt klasörler hariç) kapsayacak şekilde Uygulama 2’deki arama işlemi uygulanmalıdır. Arama sonucu kullanıcıya bilgilendirilmelidir.

### [Uygulama 4](https://github.com/BBilgeKaplan/C-Prot-Staj/blob/main/uygulama4.cpp)
Program çalıştırıldığında, programa argüman olarak verilecek bir klasör içerisindeki tüm dosyaları (alt klasörler hariç) kapsayacak şekilde Uygulama 2’deki arama işlemi uygulanmalıdır. Ancak arama sadece Portable Executable (PE) formatındaki dosyalarda gerçekleşmelidir. Diğer dosyalar atlanmalıdır ve kullanıcıya bilgisi verilmelidir. Bir dosyanın PE formatında olup olmadığının tespiti için ilk 2 baytının “MZ” olup olmadığına bakılması yeterlidir. Gerçekte olması gereken doğrulama işlemlerine bu örnek için gerek yoktur. Dosyanın PE formatında olduğu belirlendikten sonra sadece “executable” flag’ına sahip section’ları kapsayacak şekilde bir arama yapılması gerekmektedir. Yani “MALWARE” ifadesini ararken sadece “executable” flag’ına sahip section’ların sınırları içerisinde arama gerçekleştirilmelidir. Bulunması durumunda section adı ile birlikte konumu kullanıcıya bilgilendirilmelidir.

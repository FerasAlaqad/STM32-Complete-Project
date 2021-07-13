# STM32 Complete Project




In this project, I established a connection between STM32 and computer by Serial Connection protocol, in the same time I used  C# to write a desktop program that can receive massages which it will be sent by STM32, by that desktop program I can send some command to STM32 and want from him to make it.

I wrote STM32 codes by C and C++ in the Keil program. and wrote the desktop program by C# in the Visual Studio program.

▪ To access STM32 code open this file: STM32-Complete-Project/project/MDK-ARM/prorject.uvprojx  (you must open it by Keil program)
▪ To access serial port program's code you have to use Visual Studio



There are the equipments i have used: 

▪ STM32F103C8 
▪ AT24C256 EEPROM 
▪ MPU6050 
▪ TTL USB 
▪ Potansiyometre

Feel free to contact me anytime. 
Email: ferasdc18@gmail.com


![image](https://user-images.githubusercontent.com/87244886/125474300-edcae722-abba-486f-bc4f-3b7a488544af.png)

Projede yapılanlar: Bu kısımda projeyi oluşturma sürecinde yapılan tüm işlemleri tek tek yazılacaktır;

▪ System.IO.Parts kütüphanesi ve bazı hazır Seri haberleşme fonksiyonları kullanılarak 
devreden gelen mesajları ve devreye mesaj göndermek için C# ile program yazıldı.

![image](https://user-images.githubusercontent.com/87244886/125473445-e2bd7a62-00b4-470c-aac4-687505642dad.png)

▪ Programda ComboBox, botun, TextFieled ve ListBox kullanılmaktadır. Veri gönder ile seri 
haberleşme protokolüne mesaj gönderilebilir, Bağlan botunu ile seçilen porta bağlanmayı 
sağlanmaktadır.

▪ Yukarda belirttiğim devre şematiğine göre devreyi kuruldu.

▪ İki tane timer kullanıldı ilki 8 saniyede bir interrupt işareti üretiyor, diğeri ise 3 saniyede bir 
interrupt işareti oluşturur.

▪ CubeMX programından İ2c, USART1 ve ADC seçilip ayarlamalarını yapıldı.
Bu kısımda kod yazma sürecinde yapılan tüm işlemleri tek tek anlatılacaktır;

▪ 8 saniyelik timer içerisinde Mpu6050’den x, y ve z eksenindeki ivme değerleri okundu, Ve 
ADC’den gelen okumayı 16’ya bölerek 0-255 aralığı içerisinde değişmesini sağlandı. (ADC 12 
bitlik olduğu için 0-4095 aralığında değişiyor).
Sprintf fonksiyonu ile transmitData dizi içerisinde sırayla okunan değerleri kayıt edip 8 
sanyede bir USART’a gönderilir.

▪ 3 saniyelik timer içerisinde ADC değeri okunup _writeEEPROM fonksiyonu ile EEPROMA 
gönderilir. 

▪ USART Recieve interrupt kısmı tasarlanan programdan veri gönderildiği zaman aktif olur, bu 
fonksiyonda iki tane dizi kullanılmaktadır, birinci dizi recievten gelen verileri almak için 
yapıldı, ikinci dizi ise birinci diziye gelen son mesajının koyasını kaydetmek için kullanıldı.
Birinci diziyi ikinci diziye kopyalayınca ilk diziyi boşaltılır ve istenilen tüm işlemleri ikinci diziyi 
üzerinde gerçekleştirilir. 
Bu kısımda program tarafından gönderilen mesajları analiz etmek;

▪ Kullanıcı tarafından gönderilen mesajları program tarafından anlaşılabilmesi için <> bu iki 
işaret içerisinde yazılması gerekiyor.

▪ <55+87> veya <89*12> kullanıcı tarafından böyle bir mesaj yazıldığı zaman ilk olarak dizi 
fonksiyonları kullanarak istenilen işlem ne olduğunu belirlenir ona göre switch fonkosyonun 
caselerine işlemciyi yönlendirilir, Sonra işlem işaretinin önceki rakamları bir tane değişken 
içinde kaydedilir işaret sonraki rakamları aynı şekilde başka bir değişkene kayıt edilir sonra 
işarete göre istenilen işlemi yapıp sonucu USART ile cevap olarak gönderilir. 

▪ <R> harfi kullanıcı tarafından gönderildiği zaman EEPROM içerisinde kayıt edilen tüm ADC 
değerleri bir diziye çekilip USART ile toplu olarak gönderilir, Sonra _eraseEEPROM fonksiyonu 
kullanarak EEPROMU boşaltılır.

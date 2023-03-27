#include <Wire.h> // библиотека для протокола I2C
#include <DHT.h> // подключаем библиотеку для датчика
#include <LCD_1602_RUS.h> //Библотека русских символов для LCD 1602

LCD_1602_RUS LCD(0x27,16,2); // присваиваем имя LCD для дисплея
DHT dht1(2, DHT22);                          // сообщаем к какому порту подключен первый DHT22 
DHT dht2(4, DHT22);                          // сообщаем к какому порту подключен второй DHT22 
void setup() {
   LCD.init();            // инициализация LCD дисплея
   LCD.backlight();      // включение подсветки дисплея
   dht1.begin();         // запускаем датчик DHT22
   dht2.begin();         // запускаем датчик DHT22
}

void loop() {
   // считываем температуру (t) и влажность (h) первого датчика
   float h1 = dht1.readHumidity();
   float t1 = dht1.readTemperature();

   // считываем температуру (t) и влажность (h) второго датчика
   
   float h2 = dht2.readHumidity();
   float t2 = dht2.readTemperature();

   // выводим температуру c первого датчика  (t) и влажность (h) на жк дисплей
   LCD.setCursor(0,0);
   LCD.print("%  Улица ");
   LCD.print(h1);

   LCD.setCursor(0,1);
   LCD.print("t° Улица ");
   LCD.print(t1);

   delay(3000); // 3 секунды между переключением надписи
   LCD.clear();

   // выводим температуру cо второго датчика (t) и влажность (h) на жк дисплей
   LCD.setCursor(0,0);
   LCD.print("%  Балкон ");
   LCD.print(h2);

   LCD.setCursor(0,1);
   LCD.print("t° Балкон ");
   LCD.print(t2);

   delay(3000);
   LCD.clear();

   
}

#include <Arduino.h>
#include <SoftwareSerial.h>

#define LED_PIN 2   // Подключение диода 

int i = 0;    // Инициализация переменной для итераций

// Инициализация глобальной переменной для управления состоянием диода
uint8_t state_diod = HIGH;    

//Объявление структуры для вывода данных студентов
#pragma pack(push, 1) 
typedef struct _PACKET {  
  char Name1[4]; 
  char Name2[4];
  uint32_t Group; 
  uint32_t Data; 
} PACKET, *PPACKET;
#pragma pack(pop) 

// Объявление глобальной переменной типа packet
PACKET pac = {{'F', 'E', 'D', 'Y'}, {'K', 'U', 'R', 'M'}, 301, 0};

// Создание объекта класса SoftwareSerial
SoftwareSerial Softserial(16, 17);

void setup() {
  Serial.begin(115200);   // Настройка скорости чтения

  // Сообщение об успешном подключении
  Serial.println("Successful program port initialization!");
  delay(1000);    // Задержка

  // Настройка скорости чтения для SoftwareSerial
  Softserial.begin(9600);
  Softserial.println("Successful serial port initialization!");
  delay(1000);

  // Настройка пина для работы в режиме выходаты
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, state_diod);   // Начальное значение для диода
  delay(500);

}

void loop() {
  // Тест
  /*
  delay(1000);
  Serial.println(i);
  i ++;
  */
  
  // Отправка данных на микроконтроллер
  Softserial.write((uint8_t*)&pac, sizeof(pac));
  // Инкримент для поля Data
  pac.Data ++;
  // Задержка для записи
  delay(1000);

  // Переключение состояния диода
  state_diod = !state_diod;   // Изменение значения переменной на противоположное
  digitalWrite(LED_PIN, state_diod);    // Изменение состояния диода
  delay(500);

}


#include <Arduino.h>

#define LED_PIN 2   // Подключение диода 

int i = 0;    // Инициализация переменной для итераций

void setup() {
  Serial.begin(115200);   // Настройка скорости чтения
  Serial.println("Hello_word!");
  delay(1000);    // Задержка
  pinMode(LED_PIN, OUTPUT);   // Настраиваем пин как выход

}

void loop() {
  // Вывод итераций
  Serial.println(i);
  i ++ ;
  delay(500);

  digitalWrite(LED_PIN, HIGH);  // Включить светодиод
  delay(250);                  // Ждать 0,25 секунду

  digitalWrite(LED_PIN, LOW);   // Выключить
  delay(250);                  // Ждать 0,25 секунду
  /*
  Происходит переключение питания на диоде с 3.3В на 0 из-за этого происходит мигание
  */
}


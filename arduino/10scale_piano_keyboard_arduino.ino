#include <LiquidCrystal_I2C.h>  //lcd를 쓰기위한 기능 추가
const int passiveB = 13;
int bt[11] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };  // 10음계 버튼 11개 높은 옥타브 도 포함/
int melody[10] = {
  261.63,
  280.41,
  300.53,
  322.10,
  345.22,
  370.00,
  396.56,
  425.02,
  455.52,
  523.26,

};  // 10음계 진동수값

LiquidCrystal_I2C lcd(0x27, 16, 4);  //변수명 lcd로 lcd 제어
void setup() {
  // put your setup code here, to run once:
  for (int i = 0; i < 10; i++) {
    pinMode(bt[i], INPUT);
  }
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
}
int t= 0;
int t_check = 1000;
int time_s = 0;
void loop() {
  t = millis();
  if(t > t_check)
  {
    time_s++;
    t_check +=1000;
  }
  // put your main code here, to run repeatedly:
  if(time_s > 1)
  {
   lcd.clear();
   time_s = 0; 
  }
  lcd.home();

  int d = digitalRead(8);
  Serial.println(d);
  
  if (digitalRead(bt[0]) == HIGH) {
    tone(passiveB, melody[0]);
    lcd.print(melody[0]);
  } else if (digitalRead(bt[1]) == HIGH) {
    tone(passiveB, melody[1]);
    lcd.print(melody[1]);
  } else if (digitalRead(bt[2]) == HIGH) {
    tone(passiveB, melody[2]);
    lcd.print(melody[2]);
  } else if (digitalRead(bt[3]) == HIGH) {
    tone(passiveB, melody[3]);
    lcd.print(melody[3]);
  } else if (digitalRead(bt[4]) == HIGH) {
    tone(passiveB, melody[4]);
    lcd.print(melody[4]);
  } else if (digitalRead(bt[5]) == HIGH) {
    tone(passiveB, melody[5]);
    lcd.print(melody[5]);
  } else if (digitalRead(bt[6]) == HIGH) {
    tone(passiveB, melody[6]);
    lcd.print(melody[6]);
  } else if (digitalRead(bt[7]) == HIGH) {
    tone(passiveB, melody[7]);
    lcd.print(melody[7]);
  } else if (digitalRead(bt[8]) == HIGH) {
    tone(passiveB, melody[8]);
    lcd.print(melody[8]);
  } else if (digitalRead(bt[9]) == HIGH) {
    tone(passiveB, melody[9]);
    lcd.print(melody[9]);
  } else if (digitalRead(bt[10]) == HIGH) {
    tone(passiveB, melody[1]*2);
    lcd.print(melody[1]*2);
  } /*else if (digitalRead(bt[11]) == HIGH) {
    tone(passiveB, melody[11]);
    lcd.print(melody[11]);
  } else if (digitalRead(bt[12]) == HIGH) {
    tone(passiveB, melody[12]);
    lcd.print(melody[12]);
  } */else {
    noTone(passiveB);
  }
}
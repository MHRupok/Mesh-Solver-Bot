#include <EEPROM.h>
#include <LiquidCrystal.h>



#define dt 8
#define sn 8
#define sp 25
#define sst 54

#define button_1  51
#define button_2  52
#define button_3  53

#define delay_before_turn 30

int red = 10;
int green = 9;
int yellow = 8;


const int rs = 12, en = 11, d4 = 17, d5 = 16, d6 = 15, d7 = 14;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


int lmf = 5, rmf = 3, lmb = 4, rmb = 2, lme = 6, rme = 7, li = 0;

int v[sn], l[sn], r[sn], in[1000];
int i = 0, j = 0, k = 0;
int a = 0, mo = 0;
unsigned long m = 0, m1 = 0, m2 = 0, m3 = 0, m4 = 0, m5 = 0, m6 = 0;

void setup() {
  Serial.begin(9600);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);

  pinMode(button_1, INPUT);
  pinMode(button_2, INPUT);
  pinMode(button_3, INPUT);

  digitalWrite(red, LOW);
  digitalWrite(green, LOW);
  digitalWrite(yellow, LOW);

  //lcd screen
  lcd.begin(16, 2);
  lcd.clear();
  lcd.print("Bat Mobil");

  // oled(20, 20, 2, "BAT MOBIL");

  //////calibrate/////

  for (i = 0; i < sn; i++)
    r[i] = 5 * EEPROM.read(i);
  if (r[0] > (5 * EEPROM.read(sn)))li = 0;
  else li = 1;

  if (digitalRead(button_3) == HIGH)
  {
    digitalWrite(yellow, HIGH);
    digitalWrite(green, HIGH);
    digitalWrite(red, HIGH);
    delay(1000);
    auto_calibrate();
    //cal();
  }
 
  //  m = millis(); m1 = millis();
  lcd.clear();
}

void loop() {

 
  left_hand();


}

#include <LiquidCrystal_I2C.h>

#include  <Wire.h>

int Admin = 8;
int Vote1 = 7;
int Vote2 = 12;
int Total = 2;

int LED = 3;
int Buzzer = 4;
int LED1 = 5;
int LED2 = 6;

bool READY = false;

int Admin_Status = 0;

int Total_votes = 0;
int Votes1 = 0;
int Votes2 = 0;

int tune = 1000;

volatile bool showTotal = false;

String string1 , string2 , string3;
LiquidCrystal_I2C lcd(0x27,  16, 2);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(Admin , INPUT);
  pinMode(Vote1 , INPUT);
  pinMode(Vote2 , INPUT);

  pinMode(LED , OUTPUT);
  pinMode(Buzzer , OUTPUT);

  lcd.init();
  lcd.backlight();

  string1 = String("Vote 1 ");
  string2 = String("Vote 2 ");
  attachInterrupt(digitalPinToInterrupt(Total), change_total_State, RISING);
}
void change_total_State() {
  showTotal = true;
}
void display_total() {
  Serial.println("display");
  lcd.setCursor(0, 0);
  lcd.print("Votes 1  ");
  lcd.print(Votes1);

  lcd.setCursor(0, 1);
  lcd.print("Votes 2  ");
  lcd.print(Votes2);
  showTotal = false;
}
void UnReady(){
    // delay(500);
    tone(Buzzer,tune);
    delay(500);
    noTone(Buzzer);
    Total++;
    READY = false;
    digitalWrite(LED, LOW);
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    lcd.clear();
}

void loop() {
  // put your main code here, to run repeatedly:
  Admin_Status = digitalRead(Admin);
  if(Admin_Status) {
    READY = true;
    lcd.clear();
    Serial.println(READY);
    lcd.setCursor(0, 0);
    lcd.print("Ready");
    tone(Buzzer,tune);
    delay(500);
    noTone(Buzzer);
  }
  if(showTotal) {
    display_total();
  }
  while(READY){
    lcd.setCursor(0, 1);
    digitalWrite(LED, HIGH);
    if(digitalRead(Vote1) ){
      delay(250);
      if(!digitalRead(Vote2)){
        Votes1++;
        string3 = string1 + Votes1;
        Serial.println(string3);
        lcd.print(string1);
        digitalWrite(LED1 , HIGH);
        UnReady();
        }
    }
    if(digitalRead(Vote2)){
      delay(250);
      if(!digitalRead(Vote1)){
        Votes2++;
        string3 = string2 + Votes2;
        Serial.println(string3);
        lcd.print(string2);
        digitalWrite(LED2 , HIGH);
        UnReady();
      }
    }
  }
}

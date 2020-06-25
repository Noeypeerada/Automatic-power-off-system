#include "LiquidCrystal_I2C.h"
LiquidCrystal_I2C lcd(0x27, 16, 2);
#include "IRremote.h"
int RECV_PIN = 11;
#define code1 16753245 // ค่าปุ่มกดที่ 1
#define code2 16736925 // ค่าปุ่มกดที่ 2
IRrecv irrecv(RECV_PIN);
decode_results results;
int SensorPIR = 2;
int Relay = 3;
int val = 0;
int cou = 0;
void setup() {
  pinMode(SensorPIR, INPUT); // sets the pin as output
  pinMode(Relay, OUTPUT);    // sets the pin as output
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  digitalWrite(Relay, LOW);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Hello, world!");
  delay(2000);
  lcd.clear();
}
void loop() {
  val = digitalRead(SensorPIR);
  Serial.print("val = ");
  Serial.println(val);
  Serial.println(cou);
  lcd.setCursor(0, 0);
  lcd.print("LED status");
  if (val == 1) {
    if (cou < 200) { // จำนวนเคานท์สูงสุดสำหรับหน่วงเวลา relay สามารถปรับค่าได้
      cou = cou + 10; // จำนวนเคานท์ที่เพิ่มขึ้นเมื่อมีการเคลื่อนไหวหน้าเซ็นเซอร์ สามารถปรับค่าได้
    }
  }
  if (val == 0) {
    if (cou > 0) {
      cou = cou -
            10; // จำนวนเคารท์ที่จะลดลงเมื่อไม่มีการเคลื่อนไหวหน้าเซ็นเซอร์ สามารถปรับค่าได้
    }
  }
  if (irrecv.decode(&results)) {
    // Serial.print("รหัสปุ่มกด: ");
    // Serial.println(results.value);
    if (results.value ==
        code1) { // ถ้าค่าที่ส่งมาตรงกับ ค่าในตัวแปร code1 ให้ทำใน ปีกกา if
      // Serial.println("ON");
      cou = 200;
      digitalWrite(Relay, HIGH);
    }
    if (results.value ==
        code2) { // ถ้าค่าที่ส่งมาตรงกับ ค่าในตัวแปร code2 ให้ทำใน ปีกกา if
      //  Serial.println("OFF");
      cou = 0;
      digitalWrite(Relay, LOW);
    }
    irrecv.resume(); // Receive the next value
  }
  if (cou == 0) { //ดับ
    digitalWrite(Relay, LOW);
    // Serial.println("Low");
  }
  if (cou > 0) { //ติด
    digitalWrite(Relay, HIGH);
    // Serial.println("High");
  }
  if (digitalRead(Relay) == HIGH) {
    lcd.setCursor(11, 0);
    lcd.print(": ON");
  } else if (digitalRead(Relay) == LOW) {
    lcd.setCursor(11, 0);
    lcd.print(": OFF");
  }
  delay(200);
  lcd.clear();
}

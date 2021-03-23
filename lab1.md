# การทดลองที่ 1 เรื่อง การเขียนโปรแกรมเพื่อรันบนไมโครคอนโทรเลอร์

## วัตถุประสงค์
  - เพื่อให้เข้าใจการเขียนโปรแกรมเบื้องต้นลงใน micro controller
  - เพื่อให้เข้าใจการต่อ microcontroller กับ seiral
  - 
## อุปกรณ์ที่ใช้
  1. mitrocontroller
  2. serial
  3. usb ที่ต่อกับคอมพิวเตอร์
  
## แหล่งข้อมูล
 https://youtu.be/NLIUsWLEpmg
 
## วิธีการทดลอง
  1. ต่อ microcontroller เข้ากับ serial และ usb ของคอมพิวเตอร์
  2. เขียนโปรแกรมใน platformio เพื่อทำการทดสอบ
    '''
    #include <Arduino.h>

int cnt = 0;

void setup()
{
	Serial.begin(115200);
}

void loop()
{
	cnt++;
	Serial.printf("PATTANI :%d\n",cnt);
	delay(1000);
}
'''

## บันทึกผลการทดลอง
## อภิปรายผลการทดลอง
## คำถามท้ายการทดลอง

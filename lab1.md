# การทดลองที่ 1 เรื่อง การเขียนโปรแกรมเพื่อรันบนไมโครคอนโทรเลอร์

## วัตถุประสงค์
  - เพื่อให้เข้าใจการเขียนโปรแกรมเบื้องต้นลงใน micro controller
  - เพื่อให้เข้าใจการต่อ microcontroller กับ seiral
   
## อุปกรณ์ที่ใช้
  1. mitrocontroller (ESP-01)
  2. serial
  3. usb ที่ต่อกับคอมพิวเตอร์
  
## แหล่งข้อมูล
  1. 01 run example 1 : https://www.youtube.com/watch?v=NLIUsWLEpmg
  2. configuration file : https://github.com/choompol-boonmee/lab63b/blob/master/examples/01_Serial-Monitor/platformio.ini
  3. platformio : https://platformio.org/
  
## วิธีการทดลอง
  1. ต่อ microcontroller เข้ากับ serial และ usb ของคอมพิวเตอร์
  2. เขียนโปรแกรม 01_serial-monitor ใน platformio เพื่อทำการทดสอบ
  3. เปิด command prompt
  4. เปิดโปรแกรมที่ใช้ในการทดสอบ โดยใช้คำสั่ง **cd pattani** 
  5. เลือกคำสั่ง **01_serial-monitor**
  6. พิมพ์คำสั่ง **vi src/main.cpp** 
  7. เมื่อกด Enter จะได้ข้อมูลดังนี้
  ```javascript
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
  ```  
  8. พิมพ์คำสั่ง **vi platformio.ini** เมื่อกด Enter จะได้ดังนี้
  
        ![image](https://user-images.githubusercontent.com/80879772/111911794-83c09d80-8a99-11eb-8f0f-918b05017da2.png)
  
  9. upload คำสั่งไปยัง microcontroller โดยใช้คำสั่ง **pio run -t upload** จะได้ดังนี้
  
       ![image](https://user-images.githubusercontent.com/80879772/111912103-bfa83280-8a9a-11eb-903c-06a83b5ec517.png)
  10. กดปุ่มสีดำบน microcontrolller เพื่อทำการ upload ข้อมูล
  11. กดปุ่มสีแดงบน microcontroller เพื่อทำการ reset
  12. เมื่อโปรแกรม upload ข้อมูลเสร็จ ให้ใช้คำสั่ง **pio device monitor**
  13. โปรแกรมทำการแสดงผล ได้ดังนี้
   
      ![image](https://user-images.githubusercontent.com/80879780/112122249-a9ad8580-8bf2-11eb-9d14-2b73f9642523.png)
 
## บันทึกผลการทดลอง
   จากการทดลอง เมื่อใช้คำสั่ง vi platformio.ini พบว่า
   
      platform คือ espressif8266  
      
      board คือ esp01_1m
      
      framework คือ arduin
      
      upload port คือ COM3
      
      
   เมื่อใช้คำสั่งให้ microcontroller ทำงาน พบว่า โปรแกรมจะแสดงผลเป็นตัวเลขตั้งแต่ 1 ไปเรื่อยๆ โดยแสดงผลทุกๆ 1 วินาที และเมื่อทำการกดปุ่มสีแดง เพื่อ reset ข้อมูล โปรแกรมจะเริ่มแสดงผลข้อมูลตั้งแต่ 1 ใหม่
   
## อภิปรายผลการทดลอง
   จากการทดลอง เมื่อต่อ microcontroller เข้ากับ serial และคอมพิวเตอร์ แล้วทำการเขียนโปรแกรม ซึ่งโปรแกรมประกอบไปด้วย 2 ส่วน ดังนี้
   1. ส่วน Set up โดยให้ serial มีความเร็ว 115200 
   2. ส่วน loop โดยให้มีการนับไปเรื่อยๆ และแสดงผล ซึ่งกำหนดให้มีความหน่วง 1000 พบว่า โปรแกรมจะแสดงผลเป็นตัวเลขตั้งแต่ 1 ไปเรื่อยๆ โดยแสดงผลทุกๆ 1 วินาที และเมื่อทำการกดปุ่มสีแดง เพื่อ reset ข้อมูล โปรแกรมจะเริ่มแสดงผลข้อมูลตั้งแต่ 1 ใหม่
   
## คำถามท้ายการทดลอง
  การต่อ microcontroller กับ serial มีวัตถุประสงค์เพื่ออะไร
  
 __ตอบ__ เพื่อใช้ในการติดต่อสื่อสารกับพอร์ตอนุกรมของคอมพิวเตอร์ เพื่อรับค่าจากไมโครคอนโทรลเลอร์ แล้วนำไปแสดงผล ประมวลผลต่อไป   

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
  การทดลอง : https://youtu.be/NLIUsWLEpmg
  
  configuration file : https://github.com/choompol-boonmee/lab63b/blob/master/examples/01_Serial-Monitor/platformio.ini
  
## วิธีการทดลอง
  1. ต่อ microcontroller เข้ากับ serial และ usb ของคอมพิวเตอร์
  2. เขียนโปรแกรม cd-01_serial-monitor ใน platformio เพื่อทำการทดสอบ
  
     โค๊ด : https://github.com/choompol-boonmee/lab63b/blob/master/examples/01_Serial-Monitor/src/main.cpp
     
  3. upload โปรแกรม cd-01_serial-monitor โดยใช้คำสั่ง upload 
  4. กดปุ่มสีดำบน microcontrolller เพื่อทำการ upload ข้อมูล
  5. กดปุ่มสีแดงบน microcontroller เพื่อทำการ reset
  6. เมื่อโรแกรม upload ข้อมูลเสร็จ ให้ใช้คำสั่ง pio device monitor
   
      ![image](https://user-images.githubusercontent.com/80879780/112122249-a9ad8580-8bf2-11eb-9d14-2b73f9642523.png)
 
## บันทึกผลการทดลอง
   จากการทดลอง พบว่า โปรแกรมจะแสดงผลเป็นตัวเลขตั้งแต่ 1 ไปเรื่อยๆ โดยแสดงผลทุกๆ 1 วินาที และเมื่อทำการกดปุ่มสีแดง เพื่อ reset ข้อมูล โปรแกรมจะเริ่มแสดงผลข้อมูลตั้งแต่ 1 ใหม่
   
## อภิปรายผลการทดลอง
   จากการทดลอง เมื่อต่อ microcontroller เข้ากับ serial และคอมพิวเตอร์ แล้วทำการเขียนโปรแกรม โดยให้ serial มีความเร็ว 115200 และ loop ให้มีการนับไปเรื่อยๆ และแสดงผล โดยที่มีความหน่วง 1000 พบว่า โปรแกรมจะแสดงผลเป็นตัวเลขตั้งแต่ 1 ไปเรื่อยๆ โดยแสดงผลทุกๆ 1 วินาที และเมื่อทำการกดปุ่มสีแดง เพื่อ reset ข้อมูล โปรแกรมจะเริ่มแสดงผลข้อมูลตั้งแต่ 1 ใหม่
   
## คำถามท้ายการทดลอง
  การต่อ microcontroller กับ serial มีวัตถุประสงค์เพื่ออะไร
<ตอบ> เพื่อใช้ในการติดต่อสื่อสารกับพอร์ตอนุกรมของคอมพิวเตอร์ เพื่อรับค่าจากไมโครคอนโทรลเลอร์ แล้วนำไปแสดงผล ประมวลผลต่อไป   

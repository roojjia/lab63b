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
  5. กดปุ่มสีแดงบน microcontroller เพื่อทำการ set
  6. เมื่อโรแกรม upload ข้อมูลเสร็จ ให้ใช้คำสั่ง pio device
    ![image](https://user-images.githubusercontent.com/80879780/112122249-a9ad8580-8bf2-11eb-9d14-2b73f9642523.png)
    
## บันทึกผลการทดลอง
## อภิปรายผลการทดลอง
## คำถามท้ายการทดลอง

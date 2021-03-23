# การทดลองที่ 2 เรื่อง การเขียนโปรแกรมค้นหาไวไฟ

## วัตถุประสงค์
  - เพื่อใช้ microcontroller ในการแสกนค้นหา wifi
  - เพื่อทราบถึงวิธีการเขียนโปรแกรมบน microcontroller
  
## อุปกรณ์ที่ใช้
  1. mitrocontroller
  2. serial
  3. usb ที่ต่อกับคอมพิวเตอร์
  
## แหล่งข้อมูล
  1. 02 run example 2 : https://www.youtube.com/watch?v=yBjab0UNuB8
  2. configuration file : https://github.com/choompol-boonmee/lab63b/blob/master/examples/02_Scan-Wifi/platformio.ini
  
## วิธีการทดลอง
  1. ต่อ microcontroller เข้ากับ serial และ usb ของคอมพิวเตอร์
  2. เขียนโปรแกรม 02_Scan-Wifi ใน platformio เพื่อทำการทดสอบ

      โค๊ด : https://github.com/choompol-boonmee/lab63b/blob/master/examples/02_Scan-Wifi/src/main.cpp

  3. upload โปรแกรม 02_Scan-Wifi โดยใช้คำสั่ง upload
  4. กดปุ่มสีดำบน microcontrolller เพื่อทำการ upload ข้อมูล
  5. กดปุ่มสีแดงบน microcontroller เพื่อทำการ reset
  6. เมื่อโปรแกรม upload ข้อมูลเสร็จ ให้ใช้คำสั่ง pio device monitor
  7. โปรแกรมทำการประมวลผลเพื่อค้นหาสัญญาณ wifi
  
  ![image](https://user-images.githubusercontent.com/80879780/112144508-e33eba80-8c0b-11eb-9a01-092f88370748.png)

  8. เมื่อกดปุ่มสีแดง เพื่อ reset โปรแกรมจะเริ่มแสกนหาสัญญาณ wifi ใหม่ ดังภาพ
  
   ![image](https://user-images.githubusercontent.com/80879780/112144918-4c263280-8c0c-11eb-8687-f4b82159aefb.png)
  
## บันทึกผลการทดลอง
## อภิปรายผลการทดลอง
## คำถามท้ายการทดลอง

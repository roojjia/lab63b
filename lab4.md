# การทดลองที่ 4 เรื่อง การเขียนโปรแกรมอินพุทสัญญาณดิจิทัล

## วัตถุประสงค์
  -   เพื่อนำ microcontroller ที่เขียนโปรแกรมไว้ มาประยุกต์ใช้
  -   เพื่อทราบถึงการใช้โปรแกรมเอ้าพุทของสัญญาณ
  
## อุปกรณ์ที่ใช้
  1. microcontroller (ESP-01)
  2. Adapter ต่อกับสายพอร์ท 0 (สีขาว) กับ พอร์ท 2 (สีเหลือง)
  3. USB to Serial
  4. หลอดไฟ LED
  5. CPU
  6. ตัวโปรแกรมเอ้าพุทสัญญาณ (04_Input-Port)
  7. เซนเซอร์แสง

## แหล่งข้อมูล
  1. 04 run example 4 : https://www.youtube.com/watch?v=nFqoZT26U5k
  2. src code ของโปรแกรม 04_Input-Port : https://github.com/choompol-boonmee/lab63b/blob/master/examples/04_Input-Port/src/main.cpp

## วิธีการทดลอง
  1. ต่อ microcontroller เข้ากับ Adapter ที่ต่อกับสายพอร์ต 0 และ 2 และต่อเข้ากับ USB to Serial
  2. เปิด command prompt
  3. เปิดโปรแกรมที่ใช้ในการทดสอบ โดยใช้คำสั่ง **cd pattani** 
  4. เลือกคำสั่ง **04_Input-Port**
  5. พิมพ์คำสั่ง **vi src/main.cpp** 
  6. เมื่อกด Enter จะได้ข้อมูลดังนี้
  ```javascript
#include <Arduino.h>
#include <ESP8266WiFi.h>

int cnt = 0;

void setup()
{
	Serial.begin(115200);
	pinMode(0, INPUT);
	pinMode(2, OUTPUT);
	Serial.println("\n\n\n");
}

void loop()
{
	int val = digitalRead(0);
	Serial.printf("======= read %d\n", val);
	if(val==1) {
		digitalWrite(2, LOW);
	} else {
		digitalWrite(2, HIGH);
	}
	delay(100);
}

```
  7. upload โปรแกรมไปยัง microcontroller โดยใช้คำสั่ง **pio run -t upload**
  8. กดปุ่ม upload และ ปุ่ม reset เพื่อให้โปรแกรมถูก upload ไปยัง microcontroller 
  9. พิมพ์คำสั่ง **pio device monitor**
  10. โปรแกรมทำการแสดงผล ได้ดังนี้
  
  ![image](https://user-images.githubusercontent.com/80879772/111918801-71eef280-8ab9-11eb-8984-aabf8b9fdfc2.png)
  
  11. นำสายไฟเส้นสีขาว (พอร์ต 0) จิ้มไปที่สายไฟเส้นสีดำ (0 V.) ได้ผลดังนี้
  
  ![image](https://user-images.githubusercontent.com/80879772/111918970-25f07d80-8aba-11eb-801a-21906df54b40.png)
  
  12. นำสายไฟเส้นสีขาว (พอร์ต 0) จิ้มไปที่สายไฟเส้นสีแดง (5 V.) ได้ผลดังนี้
  
  ![image](https://user-images.githubusercontent.com/80879772/111919091-bc24a380-8aba-11eb-8851-4e1b0eaa4363.png)
  
  13. กดปุ่มสีดำ (ได้ 0 และ ไฟติด) และปล่อยปุ่มสีดำ ได้ผลดังนี้
  
  เมื่อกดปุ่ม
  
  ![image](https://user-images.githubusercontent.com/80879772/111919198-4f5dd900-8abb-11eb-9539-e2264f79ed54.png)
  
  เมื่อไม่กดปุ่ม
  
  ![image](https://user-images.githubusercontent.com/80879772/111919180-32c1a100-8abb-11eb-900e-264a6fbd1baa.png)
  
  14. นำ input (สายไฟเส้นสีขาว) ต่อกับสัญญาณจากเซนเซอร์
  15. นำนิ้วมือไปบังที่เซนเซอร์และไม่บังที่เซนเซอร์ สังเกตที่หลอดไฟ LED ได้ผลดังนี้
  
  
  
  
## บันทึกผลการทดลอง
  จากการเขียนโปรแกรม และ upload ไปยัง microcontroller พบว่า โปรแกรมจะแสดงผลได้ดังนี้
    read 1 คือ ที่ iput มีค่าเท่ากับ 1 ทำให้เป็น Low ดังนั้นที่พอร์ต 2 ไฟ LED จะดับ
  
	เมื่อจิ้ม Input ที่เส้นสีดำจะได้     input คือ 0    =  high   ไฟติด 
	เมื่อจิ้ม Input ที่เส้นสีแดงจะได้    input คือ 1    =  low    ไฟดับ
	กดปุ่มสีดำ จะได้                input คือ 0    =  high   ไฟติด 
	ปล่อยปุ่ม จะได้	            input คือ 1    =  low    ไฟดับ
  
  และเมื่อนำ microcontroller ต่อเข้ากับ เซนเซอร์แสง ปรากฏว่า
  
    เมื่อเอานิ้วบังแสง     ไฟดับ
    เมื่อไม่เอานิ้วบังแสง   ไฟติด
  
## อภิปรายผลการทดลอง
  จากการเขียนโปรแกรม 04_Input-Port และ upload ไปยัง microcontroller ซึ่งโปรแกรมประกอบด้วย 2 ส่วน ดังนี้
  1. ส่วน Set up โดยกำหนดให้มีความเร็ว 115200 ms สัญญาณอินพุทจากพอร์ท 0 คือตัวควบคุมให้ไฟเปิดหรือปิด ถ้า 1 ไฟดับ ถ้า 0 ไฟติด โดยดูไฟที่พอร์ท 2 และทำการแสดงผล
  2. ส่วน loop ซึ่งกำหนดให้มีความหน่วง 100 ms โดยเมื่อเอานิ้วบังแสง ทำให้แรงต้านสูงทำให้ค่า input 1 ไฟดับ และเมื่อสว่างทำให้แรงต้านทานน้อย input เป็น 0 ไฟติด
 
## คำถามท้ายการทดลอง
   เซนเซอร์แสงเปลี่ยนพลังงานจากอะไรเป็นอะไร
  __ตอบ__ เปลี่ยนจากพลังงานแสง (โฟตอน) เป็นสัญญาณไฟฟ้า (อิเล็กตรอน)

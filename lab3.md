# การทดลองที่ 3 เรื่อง การเขียนโปรแกรมเอ้าพุทสัญญาณดิจิทัล
## วัตถุประสงค์
  - เพื่อนำ microcontroller ที่ถูกเขียนโปรแกรมไปประยุกต์ใช้

## อุปกรณ์ที่ใช้
1. microcontroller (ESP-01)
2. Adapter ต่อกับสายพอร์ท 0 (สีขาว) กับ พอร์ท 1 (สีเหลือง)
3. Serial
4. หลอดไฟ LED
5. CPU
6. ตัวโปรแกรมเอ้าพุทสัญญาณ (03_Output-Port)
7. รีเลย์
8. ขั้วชาร์ต

## แหล่งข้อมูล
1. 03 run example 3 : https://www.youtube.com/watch?v=CCnN1WJsXQY
2. src code ของโปรแกรม 03_Output-Port : https://github.com/choompol-boonmee/lab63b/blob/master/examples/03_Output-Port/src/main.cpp

## วิธีการทดลอง
 1. ต่อ microcontroller เข้ากับ Adapter ที่ต่อกับสายพอร์ต 0 และ 1 และต่อเข้ากับ USB to serial ได้ดังภาพ
 
 ![image](https://user-images.githubusercontent.com/80879780/112164457-7a157200-8c20-11eb-893e-6fad2ee20bc7.png)
 
  2. เปิด command prompt
  3. เปิดโปรแกรมที่ใช้ในการทดสอบ โดยใช้คำสั่ง **cd pattani** 
  4. เลือกคำสั่ง **03_Output-Port**
  5. พิมพ์คำสั่ง **vi src/main.cpp** 
  6. เมื่อกด Enter จะได้ข้อมูลดังนี้
  ```javascript
#include <Arduino.h>
#include <ESP8266WiFi.h>

int cnt = 0;

void setup()
{
	Serial.begin(115200);
	pinMode(0, OUTPUT);
	Serial.println("\n\n\n");
}

void loop()
{
	cnt++;
	if(cnt % 2) {
		Serial.println("========== ON ===========");
		digitalWrite(0, HIGH);
	} else {
		Serial.println("========== OFF ===========");
		digitalWrite(0, LOW);
	}
	delay(500);
}
```   
   7. upload โปรแกรมไปยัง microcontroller โดยใช้คำสั่ง **pio run -t upload** จะได้ดังนี้
   8. กดปุ่ม upload และปุ่ม reset เพื่อให้โปรแกรมเข้าไปยัง microcontroller
   9. พิมพ์คำสั่ง **pio device monitor**
   10. โปรแกรมทำการแสดงผล ได้ดังนี้
   
   ![image](https://user-images.githubusercontent.com/80879772/111914840-4f071300-8aa6-11eb-9d5b-8e20b52936ef.png)
   
   11. ที่หลอดไฟ จะแสดงผลโดยที่หลอดไฟ LED จะกระพริบสลับกัน ได้ดังนี้
   
   ![image](https://user-images.githubusercontent.com/80879772/111914895-7f4eb180-8aa6-11eb-9819-1f6e211e950a.png)   
   
   ![image](https://user-images.githubusercontent.com/80879772/111914938-a9a06f00-8aa6-11eb-9e0c-ba3749274b68.png)
   
   12. นำ microcontroller ต่อเข้ากับ Relay และ ขั้วชาร์ต ได้ดังนี้

![image](https://user-images.githubusercontent.com/80879772/111915849-d22a6800-8aaa-11eb-9206-7f200b7b2eea.png) ![image](https://user-images.githubusercontent.com/80879772/111915865-dc4c6680-8aaa-11eb-8ff4-62b45dbbad9d.png)

## บันทึกผลการทดลอง
    เมื่อเขียนโปรแกรมลงบน microcontroller พบว่า โปรแกรมจะแสดงผล ON OFF สลับกันไป ที่หลอดไฟ LED พอร์ต 0 จะสว่างและดับ ตามคำสั่ง ON OFF และการนำ microcontroller มาต่อเข้ากับ Relay โดยเมื่อตัวขั้าร์ต พบว่า Relay จะมีการเปิดปิดทันที อีกทั้งยังได้ยินเสียงหน้าสัมผัสของสวิตซ์ไฟ
  
## อภิปรายผลการทดลอง
    เมื่อเขียนโปรแกรม 03_Output-Port ลงบน microcontroller ใช้คำสั่งให้มีการนับไปเรื่อยๆ โดยมีความหน่วงที่ 500 ms  โปรแกรมจะแสดงผล ON OFF สลับกันไป และที่หลอดไฟ LED ที่พอร์ต จจะสว่างและดับตามคำสั่ง on off ที่โปรแกรมได้อัพโหลดลงไปใน microcontroller และเมื่อนำ microcontroller ไปประยุกต์ใช้กับ Relay จะพบว่า Relay ทำงานร่วมกับ microcontroller โดยมีการเปิดและปิดสวิตซ์เหมือนกัน
  
## คำถามท้ายการทดลอง
  เสียงหน้าสัมผัสที่เกิดจาก Relay เกิดขึ้นได้อย่างไร
  
 __ตอบ__  จากการทำงานของ Relay เมื่อมีกระแสไฟฟ้าไหลผ่านขดลวด จะทำให้ขดลวดเกิดสนามแม่เหล็กไปดึง แผ่นหน้าสัมผัสจาก normal close ให้ดึงลงมาแตะหน้าสัมผัสของ normal open ทำให้มีกระแสไหลผ่านหน้าสัมผัสไปได้ จนครบวงจร

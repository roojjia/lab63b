# การทดลองที่ 6 เรื่อง การเขียนโปรแกรมสร้างไวไฟแอคเซสพอยต์ (Wifi AP)
## วัตถุประสงค์
  - เพื่อทราบถึงวิธีการเขียนโปรแกรมไวไฟแอคเซสพอยต์
  
## อุปกรณ์ที่ใช้
 1. microcontroller (ESP-01)
 2. USB to serial
 3. โปรแกรมสร้างไวไฟแอคเซสพอยต์ (06_Wifi-AP-Web-Server)
 
## แหล่งข้อมูล
  1. 06 run wiri AP : https://www.youtube.com/watch?v=T26DVHePlTs
  2. src code โปรแกรม 06_Wifi-AP-Web-Server : https://github.com/choompol-boonmee/lab63b/blob/master/examples/06_Wifi-AP-Web-Server/src/main.cpp
  
## วิธีการทดลอง
  1. ต่อ microcontroller เข้ากับ USB to serial
  2. เปิด command prompt
  3. เปิดโปรแกรมที่ใช้ในการทดสอบ โดยใช้คำสั่ง **cd pattani** 
  4. เลือกคำสั่ง **06_Wifi-AP-Web-Server**
  5. พิมพ์คำสั่ง **vi src/main.cpp** 
  6. เมื่อกด Enter จะได้ข้อมูลดังนี้
  
  ```javascript
#include <ESP8266WiFi.h>
//#include <WiFiClient.h>
#include <ESP8266WebServer.h>

const char* ssid = "TUENG-ESP-WIFI";
const char* password = "choompol";

IPAddress local_ip(192, 168, 1, 1);
IPAddress gateway(192, 168, 1, 1);
IPAddress subnet(255, 255, 255, 0);

ESP8266WebServer server(80);

int cnt = 0;

void setup(void){
	Serial.begin(115200);

	WiFi.softAP(ssid, password);
	WiFi.softAPConfig(local_ip, gateway, subnet);
	delay(100);
  
	server.onNotFound([]() {
		server.send(404, "text/plain", "Path Not Found");
	});

	server.on("/", []() {
		cnt++;
		String msg = "Hello cnt: ";
		msg += cnt;
		server.send(200, "text/plain", msg);
	});

	server.begin();
	Serial.println("HTTP server started");
}

void loop(void){
  server.handleClient();
}

```        
  
  7. กำหนด ssid และ password เพื่อให้เครื่องอื่นสามารถเชื่อมต่อได้ และสร้าง ip address , gateway และ subnet จากนั้นทำการเตรียมเว็บ
  8. กดปุ่ม upload และ ปุ่ม reset เพื่อให้โปรแกรมถูก upload ไปยัง microcontroller
  9. พิมพ์คำสั่ง **pio device monitor**
  10. โปรแกรมทำการแสดงผล ได้ดังนี้
  
  ![image](https://user-images.githubusercontent.com/80879772/111975374-1cefc280-8b33-11eb-90e7-43ce82ee3cee.png)
  
  11. ทำการทดลองค้นหา wifi ที่สร้างขึ้นมา โดยใช้โทรศัพท์
  
  ![image](https://user-images.githubusercontent.com/80879772/111975598-5f190400-8b33-11eb-80c4-72690f3fcacd.png)
  
## บันทึกผลการทดลอง
  จากการเขียนโปรแกรม เมื่อทำการแสดงผล พบว่า ver started และทำการตรวจสอบโดยการค้นหา wifi ที่สร้างขึ้นมา จากโทรศัพท์ ซึ่งจากการค้นหา wifi เราได้พบ wifi ที่ได้ถูกสร้างขึ้นมา จากการเขียนโปรแกรม
  
## อภิปรายผลการทดลอง
  จากการทดลองเขียนโปรแกรม ทำการแสดงผล ขึ้นคำว่า ver started และได้ทำการตรวจสอบ โดยค้นหา wifi สร้างขึ้นมา สามารถสรุปได้ว่า การเขียนโปรแกรมเพื่อสร้างไวไฟแอคเซสพอยต์ขึ้นมาเอง มีวัตถุประสงค์เพื่อให้ผู้ใช้งานอื่นๆสามารถเชื่อมต่อ wifi ได้
  
## คำถามท้ายการทดลอง
  ไวไฟแอคเซสพอยต์ คืออะไร
  __ตอบ__ อุปกรณ์ที่มีหน้าที่ในการกระจายสัญญาณ wireless (ไวร์เลส) เป็นอุปกรณ์พื้นฐานตัวหนึ่งที่สามารถสร้างเครือข่ายไร้สายจากระบบเครือข่าย Lan (แลน)

# การทดลองที่ 5 เรื่อง การเขียนโปรแกรมเชื่อมต่อไวไฟและเว็บเซอร์เวอร์
## วัตถุประสงค์
  -   เพื่อทราบวิธีในการเขียนโปรแกรมเชื่อมต่อไวไฟ และเว็บเซอร์เวอร์
## อุปกรณ์ที่ใช้
  1. microcontroller (ESP-01)
  2. USB to Serial
  3. โปรแกรมเชื่อมต่อไวไฟและเซอร์เวอร์
  
## แหล่งข้อมูล
  1. 05 run wifi  : https://www.youtube.com/watch?v=VX-QNQcO-b4
  2. src code ของโปรแกรม 05_Wifi-Web-Server : https://github.com/choompol-boonmee/lab63b/blob/master/examples/05_Wifi-Web-Server/src/main.cpp
  
## วิธีการทดลอง
  1.ต่อ microcontroller เข้ากับ USB to serial
  2. เปิด command prompt
  3. เปิดโปรแกรมที่ใช้ในการทดสอบ โดยใช้คำสั่ง **cd pattani**
  4. เลือกคำสั่ง 05_Wifi-Web-Server
  5. พิมพ์คำสั่ง vi src/main.cpp
  6. เมื่อกด Enter จะได้ข้อมูลดังนี้
  
  ```javascript
#include <ESP8266WiFi.h>
//#include <WiFiClient.h>
#include <ESP8266WebServer.h>

const char* ssid = "HI_BMFWIFI_2.4G";
const char* password = "0819110933";

ESP8266WebServer server(80);

int cnt = 0;

void setup(void){
	Serial.begin(115200);

	WiFi.mode(WIFI_STA);
	WiFi.begin(ssid, password);
	while (WiFi.status() != WL_CONNECTED) {
		delay(500);
		Serial.print(".");
	}
  Serial.print("\n\nIP address: ");
	Serial.println(WiFi.localIP());

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
  7. โปรแกรมจะต้องเชื่อมต่อกับไวไฟ จึงต้องใส่ชื่อและรหัสผ่านของ wifi
  8. กดปุ่ม upload และ ปุ่ม reset เพื่อให้โปรแกรมถูก upload ไปยัง microcontroller 
  9. พิมพ์คำสั่ง **pio device monitor**
  10. โปรแกรมจะทำการแสดงผล ip address
  11. คัดลอก ip address เพื่อนำไปใช้ทดสอบกับเว็บเบราเซอร์
  
## บันทึกผลการทดลอง
  จากการเขียนโปรแกรม เมื่อแสดงผล จะแสดง ip address และเมื่อคัดลอกและนำไปเปิดบนเว็บเบราเซอร์ก็จะแสดงผล Hello 1 โดยที่จะนับและเปลี่ยนตัวแปรไปเรื่อยๆ
  
## อภิปรายผลการทดลอง
  จากการทดลองเขียนโปรแกรม พบว่า เมื่อ upolad โปรแกรมลงบน microcontroller และทำการแสดงผล จะได้ ip address คัดลอก ip address ไปเปิดที่เว็บเบราเซอร์เพื่อใช้ในการทดสอบ
  
## คำถามท้ายการทดลอง
  ssid และ password ของ wifi คืออะไร และมีความสำคัญอย่างไร
  __ตอบ__ ssid คือ ชื่อของ Network ที่ตั้งขึ้นมา โดยที่ทุกๆเครื่องในระบบต้องตั้งค่า SSID ค่าเดียวกัน
          password คือ รหัสผ่านที่ใช้ในการเชื่อมต่อ wifi
          

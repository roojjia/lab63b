// โปรแกรมสำหรับไฟจราจร 2 เลน

// กำหนดไฟเลน 1
int R1 = 1; // ขา Digital 1 เป็น  ไฟแดงเลน 1
int Y1 = 2; // ขา Digital 2 เป็น  ไฟเหลืองเลน 1
int G1 = 3; // ขา Digital 3 เป็น  ไฟเขียวเลน 1

// กำหนดไฟเลน 2
int R2 = 4; // ขา Digital 4 เป็น  ไฟแดงเลน 2
int Y2 = 5; // ขา Digital 5 เป็น  ไฟเหลืองเลน 2
int G2 = 6; // ขา Digital 6 เป็น  ไฟเขียวเลน 2

void setup(){
    pinMode(R1, OUTPUT);
    pinMode(Y1, OUTPUT);
    pinMode(G1, OUTPUT);
    pinMode(R2, OUTPUT);
    pinMode(Y2, OUTPUT);
    pinMode(G2, OUTPUT);
}

void loop(){
    // ให้สัญญาณไฟเหลือง เลน 1 ก่อน
    digitalWrite(Y1, HIGH); // ให้สัญญาณไฟเหลือง เลน 1
    digitalWrite(G1, LOW);
    delay(2500); //2.5วินาที

    // ปิดไฟเหลืองสองฝั่ง, จากนั้นให้สัญญาณไฟแดงเลน 1, กับให้สัญญาณไฟเขียวเลน 2 พร้อมกัน
    digitalWrite(R1, HIGH); //ให้สัญญาณไฟแดง เลน 1
    digitalWrite(G2, HIGH); //ให้สัญญาณไฟเขียว เลน 2
    digitalWrite(Y1, LOW);
    digitalWrite(Y2, LOW);
    digitalWrite(R2, LOW);
    delay(15000); //15วินาที

    // ให้สัญญาณไฟเหลือง เลน 2
    digitalWrite(Y2, HIGH); // ให้สัญญาณไฟเหลือง เลน 2
    digitalWrite(G2, LOW);
    delay(2500); //2.5วินาที

    // ปิดไฟเหลืองสองฝั่ง, จากนั้นให้สัญญาณไฟแดงเลน 2,กับให้สัญญาณไฟเขียวเลน 1 พร้อมกัน
    digitalWrite(R2, HIGH); //ให้สัญญาณไฟแดง เลน 2
    digitalWrite(G1, HIGH); //ให้สัญญาณไฟเขียว เลน 1
    digitalWrite(Y1, LOW);
    digitalWrite(R1, LOW);
    digitalWrite(Y2, LOW);
    delay(15000); //15วินาที
}

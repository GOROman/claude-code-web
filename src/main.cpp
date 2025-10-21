#include <M5Core2.h>

// LED状態管理用変数
bool ledState = false;
unsigned long previousMillis = 0;
const long interval = 500; // 500ms間隔でLEDを点滅

void setup() {
    // M5Stack Core2の初期化
    M5.begin();

    // ディスプレイの初期化
    M5.Lcd.fillScreen(BLACK);
    M5.Lcd.setTextColor(WHITE);
    M5.Lcd.setTextSize(3);
    M5.Lcd.setCursor(10, 10);
    M5.Lcd.println("M5Stack Core2");
    M5.Lcd.setCursor(10, 50);
    M5.Lcd.println("LED Blink");
    M5.Lcd.setTextSize(2);
    M5.Lcd.setCursor(10, 100);
    M5.Lcd.println("Status: OFF");

    // シリアル通信の初期化
    Serial.begin(115200);
    Serial.println("M5Stack Core2 LED Blink Started");

    // 内蔵LEDピンの初期化（GPIO10が内蔵LED）
    pinMode(GPIO_NUM_10, OUTPUT);
    digitalWrite(GPIO_NUM_10, LOW);
}

void loop() {
    M5.update(); // ボタン状態などの更新

    unsigned long currentMillis = millis();

    // 指定した間隔でLEDを点滅
    if (currentMillis - previousMillis >= interval) {
        previousMillis = currentMillis;

        // LED状態を反転
        ledState = !ledState;
        digitalWrite(GPIO_NUM_10, ledState ? HIGH : LOW);

        // ディスプレイの状態表示を更新
        M5.Lcd.fillRect(10, 100, 300, 30, BLACK);
        M5.Lcd.setCursor(10, 100);
        if (ledState) {
            M5.Lcd.setTextColor(GREEN);
            M5.Lcd.println("Status: ON ");
        } else {
            M5.Lcd.setTextColor(RED);
            M5.Lcd.println("Status: OFF");
        }
        M5.Lcd.setTextColor(WHITE);

        // シリアル出力
        Serial.print("LED Status: ");
        Serial.println(ledState ? "ON" : "OFF");
    }

    delay(10); // CPU使用率を下げるための小さな遅延
}

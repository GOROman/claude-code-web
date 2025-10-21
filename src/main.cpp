#include <M5Core2.h>

// ディスプレイレイアウト定数
const int TITLE_X = 10;
const int TITLE_Y = 10;
const int TITLE_SIZE = 3;

const int SUBTITLE_X = 10;
const int SUBTITLE_Y = 50;

const int STATUS_X = 10;
const int STATUS_Y = 100;
const int STATUS_WIDTH = 300;
const int STATUS_HEIGHT = 30;
const int STATUS_SIZE = 2;

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
    M5.Lcd.setTextSize(TITLE_SIZE);
    M5.Lcd.setCursor(TITLE_X, TITLE_Y);
    M5.Lcd.println("M5Stack Core2");
    M5.Lcd.setCursor(SUBTITLE_X, SUBTITLE_Y);
    M5.Lcd.println("LED Blink");
    M5.Lcd.setTextSize(STATUS_SIZE);
    M5.Lcd.setCursor(STATUS_X, STATUS_Y);
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
        M5.Lcd.fillRect(STATUS_X, STATUS_Y, STATUS_WIDTH, STATUS_HEIGHT, BLACK);
        M5.Lcd.setCursor(STATUS_X, STATUS_Y);
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

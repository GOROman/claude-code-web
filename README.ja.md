# M5Stack Core2 LED Blink Application

**[English](README.md) | 日本語**

M5Stack Core2向けのシンプルなLEDチカチカ（点滅）アプリケーションです。

## 機能

- 内蔵LED（GPIO10）を500ms間隔で点滅
- ディスプレイにLEDの状態（ON/OFF）を表示
- シリアルモニターにLEDの状態を出力

## 必要なもの

- M5Stack Core2デバイス
- PlatformIO（VSCode拡張機能またはCLI）
- USBケーブル（Type-C）

## セットアップ

### 1. PlatformIOのインストール

#### VSCode拡張機能として
1. VSCodeを開く
2. 拡張機能パネルを開く（Ctrl+Shift+X）
3. "PlatformIO IDE"を検索してインストール

#### CLIとして
```bash
pip install platformio
```

### 2. プロジェクトのビルド

```bash
# プロジェクトディレクトリに移動
cd claude-code-web

# 依存関係のインストールとビルド
pio run
```

### 3. M5Stack Core2への書き込み

```bash
# デバイスを接続してアップロード
pio run --target upload
```

### 4. シリアルモニターで確認

```bash
# シリアルモニターを開く
pio device monitor
```

## プロジェクト構造

```
claude-code-web/
├── src/
│   └── main.cpp          # メインプログラム
├── platformio.ini        # PlatformIO設定ファイル
├── README.md            # 英語版
└── README.ja.md         # このファイル（日本語）
```

## コードの説明

### main.cpp

- `setup()`: M5Stack Core2とLEDピンを初期化し、ディスプレイに初期画面を表示
- `loop()`: 500ms間隔でLEDの状態を反転し、ディスプレイとシリアル出力を更新

## カスタマイズ

### 点滅間隔の変更

`src/main.cpp`の以下の行を変更してください：

```cpp
const long interval = 500; // ミリ秒単位（500 = 0.5秒）
```

### LEDピンの変更

M5Stack Core2の内蔵LEDはGPIO10に接続されています。他のピンを使用する場合は、以下の行を変更してください：

```cpp
pinMode(GPIO_NUM_10, OUTPUT); // GPIO_NUM_10を任意のピン番号に変更
```

## トラブルシューティング

### デバイスが認識されない場合

1. USBケーブルがデータ転送対応か確認
2. ドライバが正しくインストールされているか確認（CP210xドライバ）
3. デバイスが正しく接続されているか確認

### ビルドエラーが発生する場合

```bash
# プラットフォームとライブラリを再インストール
pio pkg uninstall
pio run
```

## ライセンス

このプロジェクトはMITライセンスの下で公開されています。

## 作成者

Generated with Claude Code

#pragma once
#include <DxLib.h>
#include <string>

enum DrawType {
    LEFT,
    CENTER,
    RIGHT
};

namespace TextUtil {
	inline void DrawFix2DText(DrawType type, int x, int y, int size, std::string text, unsigned int textColor, unsigned int edgeColor) {
        SetFontSize(size);
        int strWidth = GetDrawStringWidth(text.c_str(), text.size());

        switch (type)
        {
        case LEFT:
            break;
        case CENTER:
            x -= strWidth / 2;
            y -= size / 2;
            break;
        case RIGHT:
            x -= strWidth;
            break;
        }

        DrawString(x, y, text.c_str(), textColor, edgeColor);
    }

}

namespace KeyInput {
	inline const int KEYCOUNT = 256;
	inline char beforeKeyBuf[KEYCOUNT] = { 0 }; //前フレームのキー状態保存用
	inline char afterKeyBuf[KEYCOUNT] = { 0 };  //後フレームのキー状態保存用
	inline char fixDownKeyBuf[KEYCOUNT] = { 0 }; //押された瞬間のキー状態保存用
	inline char fixUpKeyBuf[KEYCOUNT] = { 0 };   //離された瞬間のキー状態保存用
    
    inline void updateKeyState() {
        memcpy_s(KeyInput::beforeKeyBuf, sizeof(char) * KeyInput::KEYCOUNT, KeyInput::afterKeyBuf, sizeof(char) * KeyInput::KEYCOUNT); //after（後フレーム）から before（前フレーム）にコピー
        GetHitKeyStateAll(KeyInput::afterKeyBuf); //後フレームに代入

        for (int n = 0; n < KeyInput::KEYCOUNT; n++) {
            int key_xor = KeyInput::beforeKeyBuf[n] ^ KeyInput::afterKeyBuf[n]; //前と後が0と1なら、1を返す（XOR）
            KeyInput::fixDownKeyBuf[n] = key_xor & KeyInput::afterKeyBuf[n]; //押された瞬間 = (XORと後フレームのANDを取る) 
            KeyInput::fixUpKeyBuf[n] = key_xor & KeyInput::beforeKeyBuf[n]; //離された瞬間 = (XORと前フレームのANDを取る)
        }
    }

    inline bool isKeyFixDown(int keyCode) {
        return KeyInput::fixDownKeyBuf[keyCode];
    }
    
    inline bool isKeyFixUp(int keyCode) {
        return KeyInput::fixUpKeyBuf[keyCode];
	}

}
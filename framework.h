#pragma once
#include <Windows.h>
#include <DxLib.h>

namespace GameFile {
	inline const char* SCREENSHOT_PATH = "screenshot";
}

namespace GameScreen {
	inline const char* TITLE = "Game"; //ウインドウのタイトル
	inline const int WIDTH = 1280; //画面の幅
	inline const int HEIGHT = 720; //画面の高さ
	inline const int COLORBIT = 32; //カラービット
	inline const int BACKGROUND[3] = {0, 0, 0}; //画面の背景
	inline const int FPS = 60; //画面のフレームレート

	//スクショできないため、コメントアウト
	/*
	inline void saveScreenshot() {
		int width, height;
		GetDrawScreenSize(&width, &height);
		DATEDATA dateData;
		GetDateTime(&dateData);
		char filename[256];
		sprintf_s(filename, sizeof(filename), "%s/screenshot_%04d%02d%02d_%02d%02d%02d.png",
			GameFile::SCREENSHOT_PATH,
			dateData.Year, dateData.Mon, dateData.Day,
			dateData.Hour, dateData.Min, dateData.Sec);
		CreateDirectoryA(GameFile::SCREENSHOT_PATH, nullptr); 
		ScreenFlip();                    
		SetDrawScreen(DX_SCREEN_FRONT);
		int saveresult = SaveDrawScreenToPNG(0, 0, width, height, filename);
		SetDrawScreen(DX_SCREEN_BACK);

		NOTIFYICONDATA nid;
		ZeroMemory(&nid, sizeof(NOTIFYICONDATA));
		nid.cbSize = sizeof(NOTIFYICONDATA);
		nid.hWnd = GetMainWindowHandle();
		nid.uID = 1;
		if (saveresult == 0) {
			//通知を出す
			nid.uFlags = NIF_INFO;
			strcpy_s(nid.szInfo, "スクリーンショットを保存しました。");
			strcpy_s(nid.szInfoTitle, "スクリーンショット保存完了");
			nid.dwInfoFlags = NIIF_INFO;
		}
		else {
			//通知を出す
			nid.uFlags = NIF_INFO;
			strcpy_s(nid.szInfo, "スクリーンショットの保存に失敗しました。");
			strcpy_s(nid.szInfoTitle, "スクリーンショット保存失敗");
			nid.dwInfoFlags = NIIF_ERROR;
		}
		Shell_NotifyIcon(NIM_ADD, &nid);
	}
	*/
}
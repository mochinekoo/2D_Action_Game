#include <DxLib.h>
#include "framework.h"
#include "SceneManager.h"
#include "SubWindow.h"
#include "GameUtil.h"

int initApplication(); //アプリケーションを初期化する関数

float deltaTime = 0.0f;

int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {
    if (initApplication() != 0) {
        return -1;
    }

	CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)createSubWindow, nullptr, 0, nullptr);

    int beforeCount = GetNowCount();
    int afterCount = GetNowCount();
    while (true) {
        ClearDrawScreen();
		KeyInput::updateKeyState();

        afterCount = GetNowCount();
        deltaTime = (afterCount - beforeCount) / 1000.0f;
        beforeCount = afterCount;

        SceneBase* currentScene = SceneManager::GetInstance().GetCurrentScene();
        if (currentScene != nullptr) {
            currentScene->Update();
            currentScene->Draw();
        }
        else {
            MessageBox(nullptr, "シーンが見つからなかったため、ソフトを終了します。", nullptr, MB_OK);
            DxLib_End();
            break;
        }

        ScreenFlip();
        WaitTimer(1000 / GameScreen::FPS);
        if (ProcessMessage() == -1) {
            break;
        }
    }
    DxLib_End();
    return 0;
}

int initApplication() {
    SetMainWindowText(GameScreen::TITLE);
    ChangeFontType(DX_FONTTYPE_ANTIALIASING_EDGE_16X16); //アンチエイリアシング＆エッジが使えるように
    ChangeWindowMode(true); //ウインドウモードで起動する
    SetGraphMode(GameScreen::WIDTH, GameScreen::HEIGHT, GameScreen::COLORBIT);
    SetAlwaysRunFlag(true);
    if (DxLib_Init() == -1) {
        return -1;
    }

    SetBackgroundColor(GameScreen::BACKGROUND[0], GameScreen::BACKGROUND[1], GameScreen::BACKGROUND[2]);
    SetDrawScreen(DX_SCREEN_BACK);

	SceneManager::GetInstance().InitScenes();

    return 0;
}
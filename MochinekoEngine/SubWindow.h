#pragma once
#include <Windows.h>

LRESULT CALLBACK SubWindowProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
int initSubWindow(HINSTANCE hinstance);
DWORD WINAPI createSubWindow(LPVOID lpvoid);
#pragma once
#include <windows.h>

class Window {
public:
    static constexpr wchar_t CLASS_NAME[] = L"DemoWindow";

    static LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

    Window(HINSTANCE hInstance);
    bool create(int width, int height, int nCmdShow);
    HWND getHandle() const { return hwnd; }

private:
    HINSTANCE hInstance;
    HWND hwnd;

    bool registerClass();
};

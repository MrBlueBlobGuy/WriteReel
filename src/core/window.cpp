#include "Window.h"

constexpr wchar_t Window::CLASS_NAME[];

LRESULT CALLBACK Window::WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProcW(hwnd, msg, wParam, lParam);
    }
    return 0;
}

Window::Window(HINSTANCE hInstance)
    : hInstance(hInstance), hwnd(nullptr) {}

bool Window::registerClass() {
    WNDCLASSEX wc = { 0 };

    wc.cbSize        = sizeof(WNDCLASSEX);
    wc.style         = 0;
    wc.lpfnWndProc   = Window::WndProc;
    wc.cbClsExtra    = 0;
    wc.cbWndExtra    = 0;
    wc.hInstance     = hInstance;
    wc.hIcon         = LoadIconW(NULL, IDI_APPLICATION);
    wc.hCursor       = LoadCursorW(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.lpszMenuName  = NULL;
    wc.lpszClassName = CLASS_NAME;
    wc.hIconSm       = LoadIconW(NULL, IDI_APPLICATION);

    return RegisterClassExW(&wc);
}

bool Window::create(int width, int height, int nCmdShow) {
    if (!registerClass()) {
        MessageBoxW(NULL, L"Window registration failed!", L"Error", MB_ICONEXCLAMATION | MB_OK);
        return false;
    }

    hwnd = CreateWindowExW(
        0,
        CLASS_NAME,
        L"Demo Window",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT,
        width, height,
        NULL, NULL,
        hInstance,
        NULL
    );

    if (!hwnd) {
        MessageBoxW(NULL, L"CreateWindow failed!", L"Error", MB_ICONEXCLAMATION | MB_OK);
        return false;
    }

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);
    return true;
}

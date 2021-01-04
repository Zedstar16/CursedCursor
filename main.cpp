#include <iostream>
#include <windows.h>

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);


void ascii() {
    std::string s = R"(
 _____                              _        _____
/  __ \                            | |      /  __ \
| /  \/ _   _  _ __  ___   ___   __| |      | /  \/ _   _  _ __  ___   ___   _ __
| |    | | | || '__|/ __| / _ \ / _` |      | |    | | | || '__|/ __| / _ \ | '__|
| \__/\| |_| || |   \__ \|  __/| (_| |      | \__/\| |_| || |   \__ \| (_) || |
 \____/ \__,_||_|   |___/ \___| \__,_|       \____/ \__,_||_|   |___/ \___/ |_|

)";
    std::string delimiter = "\n";
    size_t pos = 0;
    std::string token;
    while ((pos = s.find(delimiter)) != std::string::npos) {
        token = s.substr(0, pos);
        std::cout << token.c_str() << std::endl;
        s.erase(0, pos + delimiter.length());
        Sleep(50);
    }

}

int main() {
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
    std::string str = "Cursed_Cursor.exe";
    for (int i = 0; i <= str.length(); i++) {
        std::string part = "title " + str.substr(0, i);
        system(part.c_str());
        Sleep(50);
    }
    ascii();

    const char *lines[5] = {
            "Keybinds:",
            "",
            "F7 - Toggle cursor locking",
            "F8 - Toggle visibility of this window",
            "F9 - Kills program"
    };
    for (auto &line : lines) {
        std::cout << line << std::endl;
    }
    bool active = false;
    bool show_window = true;

    while (true) {
        Sleep(1);
        if (GetAsyncKeyState(VK_F7) & 0x8000) {
            active = !active;
            Sleep(100);
        }
        if (GetAsyncKeyState(VK_F8) & 0x8000) {
            show_window = !show_window;
            Sleep(100);
            HWND window;
            AllocConsole();
            window = FindWindowA("ConsoleWindowClass", nullptr);
            if (show_window) {
                ShowWindow(window, 1);
            } else {
                ShowWindow(window, 0);
            }
        }
        if (GetAsyncKeyState(VK_F9) & 0x8000) {
            exit(0);
        }
        if (active) {
            SetCursorPos(500, 500);
        }
    }
}
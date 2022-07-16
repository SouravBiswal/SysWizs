#include <windows.h>
#include <stdlib.h>
#include <Commdlg.h>
#define FILE_MENU_NEW 1
#define FILE_MENU_OPEN 2
#define FILE_MENU_EXIT 3
#define Retrieve_files 4
#define hFileMenu 5
#define GENERATE_BUTTON 6
#define OPEN_FILE 7
char szFile[100];
HMENU hMenu;
LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);
void AddMenus(HWND);
void AddControlRetrieve(HWND);
void AddControlTag(HWND);
LRESULT CALLBACK AddControlRetrievedel(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp);
HWND hEdit, hOut, hName, hTag, hMain;

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevinst, LPSTR args, int ncmdshow)
{
    WNDCLASSW wc = {0};

    wc.hbrBackground = (HBRUSH)COLOR_WINDOW;

    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hInstance = hInst;

    wc.lpszClassName = L"myWindowClass";

    wc.lpfnWndProc = WindowProcedure;

    if (!RegisterClassW(&wc))
        return -1;

    hMain = CreateWindowW(L"mywindowClass", L"File tagging System", WS_OVERLAPPEDWINDOW | WS_VISIBLE, 100, 100, 500, 500, NULL, NULL, NULL, NULL);

    MSG msg = {0};

    while (GetMessage(&msg, NULL, NULL, NULL))
    {
        TranslateMessage(&msg);

        DispatchMessage(&msg);
    }
    return 0;
}
/*void open_file(HWND hwnd)
{

    OPENFILENAME ofn;

    ZeroMemory(&ofn, sizeof(ofn));
    ofn.lStructSize = sizeof(ofn);
    ofn.hwndOwner = NULL;
    ofn.lpstrFile = szFile;
    ofn.lpstrFile[0] = '\0';
    ofn.nMaxFile = sizeof(szFile);
    ofn.lpstrFilter = "All\0*.*\0Text\0*.TXT\0";
    ofn.nFilterIndex = 1;
    ofn.lpstrFileTitle = NULL;
    ofn.nMaxFileTitle = 0;
    ofn.lpstrInitialDir = NULL;
    ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

    if(GetOpenFileName(&ofn))
    {

    }

    // Now simpley display the file name
    MessageBox(NULL, ofn.lpstrFile, "File Name", MB_OK);
    return;
}*/
LRESULT CALLBACK WindowProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp)
{

    switch (msg)
    {
    case WM_COMMAND:
        switch (wp)
        {

        case FILE_MENU_EXIT:
            DestroyWindow(hWnd);
            break;
        case hFileMenu:
            AddControlRetrieve(hWnd);
            break;
        case GENERATE_BUTTON:
            char name[30], age[10], out[50];
            GetWindowText(hName, name, 30);
            GetWindowText(hTag, age, 10);
            strcpy(out,"");
            strcat(out, " The Files With the tags are: \n");
            SetWindowText(hOut, out);
            break;
        }
        break;

    case WM_CREATE:
        AddMenus(hWnd);
        break;
    case WM_DESTROY:
        PostQuitMessage(0);

        break;
    default:
        return DefWindowProcW(hWnd, msg, wp, lp);
    }
}
void AddMenus(HWND hWnd)
{
    hMenu = CreateMenu();
    AppendMenu(hMenu, MF_STRING, hFileMenu, "Main");
    AppendMenu(hMenu, MF_STRING, FILE_MENU_EXIT, "Exit");

    SetMenu(hWnd, hMenu);
}

void AddControlRetrieve(HWND hwnd)
{
    CreateWindowW(L"Static", L"File_Search_System :", WS_VISIBLE | WS_CHILD, 20, 20, 160, 38, hwnd, NULL, NULL, NULL);
    CreateWindowW(L"Static", L"Tag_name:", WS_VISIBLE | WS_CHILD, 100, 50, 98, 38, hwnd, NULL, NULL, NULL);
    hOut = CreateWindowW(L"Edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER, 200, 45, 98, 38, hwnd, NULL, NULL, NULL);
    CreateWindowW(L"Static", L"Files_Found :", WS_VISIBLE | WS_CHILD, 100, 90, 160, 38, hwnd, NULL, NULL, NULL);
    CreateWindowW(L"Button", L"SEARCH", WS_VISIBLE | WS_CHILD | WS_BORDER, 310, 45, 98, 38, hwnd, (HMENU)GENERATE_BUTTON, NULL, NULL);
    hOut = CreateWindowW(L"Edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_MULTILINE | WS_HSCROLL | WS_VSCROLL, 100, 110, 200, 100, hwnd, NULL, NULL, NULL);

    CreateWindowW(L"Static", L"-------------------------------------------------------------------------------------------------------", WS_VISIBLE | WS_CHILD, 45, 220, 400, 100, hwnd, NULL, NULL, NULL);
    CreateWindowW(L"Static", L"File_Tagging_System :", WS_VISIBLE | WS_CHILD, 20, 250, 160, 38, hwnd, NULL, NULL, NULL);
    CreateWindowW(L"Static", L"File_name:", WS_VISIBLE | WS_CHILD, 100, 280, 98, 38, hwnd, NULL, NULL, NULL);

    hName = CreateWindowW(L"Edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER, 200, 275, 98, 38, hwnd, NULL, NULL, NULL);

    CreateWindowW(L"Static", L"Tag to be added:", WS_VISIBLE | WS_CHILD, 100, 325, 98, 38, hwnd, NULL, NULL, NULL);
    hTag = CreateWindowW(L"Edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER, 200, 320, 98, 38, hwnd, NULL, NULL, NULL);
    CreateWindowW(L"Button", L"ADD TAG", WS_VISIBLE | WS_CHILD | WS_BORDER, 300, 380, 98, 38, hwnd, (HMENU)OPEN_FILE, NULL, NULL);
}

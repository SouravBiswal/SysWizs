#include <windows.h>
#include <stdlib.h>
#include <bits/stdc++.h>
#include <Commdlg.h>
#define FILE_MENU_NEW 1
#define FILE_MENU_OPEN 2
#define FILE_MENU_EXIT 3
#define Retrieve_files 4
#define hFileMenu 5
#define GENERATE_BUTTON 6
#define OPEN_FILE 7
using namespace std;
char szFile[100];
HMENU hMenu;
LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);
void AddMenus(HWND);
void AddControlRetrieve(HWND);
void AddControlTag(HWND);
void insertValue(string tagName,string filePath);
string getFiles(string tag);
string Chartostring(char cc[]);
LRESULT CALLBACK AddControlRetrievedel(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp);
HWND hEdit, hOut, hName, hTag, hMain,hTagToAdd;
map <string,set <string> > myMap;
map <string,set <string> >TagPerFiles;
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

    hMain = CreateWindowW(L"mywindowClass", L"File tagging System", WS_OVERLAPPEDWINDOW | WS_VISIBLE, 200, 200, 500, 500, NULL, NULL, NULL, NULL);

    MSG msg = {0};

    while (GetMessage(&msg, NULL, NULL, NULL))
    {
        TranslateMessage(&msg);

        DispatchMessage(&msg);
    }
    return 0;
}
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
            {char Fname[1000],TagAdd[1000];
            string Fnames,TagAdds;
            GetWindowText(hName, Fname,1000);
            GetWindowText(hTagToAdd, TagAdd, 1000);
            Fnames=Chartostring(Fname);
            TagAdds=Chartostring(TagAdd);
            insertValue(Fname,TagAdd);
            SetWindowText(hName,"");
            SetWindowText(hTagToAdd,"");
            break;}
        case OPEN_FILE:
            {
            string out,tags;
            char tag[1000],output[1000];
            GetWindowText(hTag, tag, 1000);
            cout<<output<<" "<<tag<<endl;
            strcat(tag,"+");
            tags=Chartostring(tag);
            out="";
            out=getFiles(tags);
            strcpy(output,"");
            for(int i=0;i<out.length();i++)
               output[i]=out[i];
            SetWindowText(hTag,"");
            SetWindowText(hOut, output);
            break;}
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
    hTag = CreateWindowW(L"Edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_MULTILINE| WS_HSCROLL, 200, 45, 100, 38, hwnd, NULL, NULL, NULL);
    CreateWindowW(L"Static", L"Files_Found :", WS_VISIBLE | WS_CHILD, 100, 90, 160, 38, hwnd, NULL, NULL, NULL);
    CreateWindowW(L"Button", L"SEARCH", WS_VISIBLE | WS_CHILD | WS_BORDER, 310, 45, 98, 38, hwnd, (HMENU)OPEN_FILE, NULL, NULL);
    hOut = CreateWindowW(L"Edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_MULTILINE | WS_HSCROLL | WS_VSCROLL, 100, 110, 200, 100, hwnd, NULL, NULL, NULL);

    CreateWindowW(L"Static", L"-------------------------------------------------------------------------------------------------------", WS_VISIBLE | WS_CHILD, 45, 220, 400, 100, hwnd, NULL, NULL, NULL);
    CreateWindowW(L"Static", L"File_Tagging_System :", WS_VISIBLE | WS_CHILD, 20, 250, 160, 38, hwnd, NULL, NULL, NULL);
    CreateWindowW(L"Static", L"File_Directory", WS_VISIBLE | WS_CHILD, 100, 280, 98, 38, hwnd, NULL, NULL, NULL);

    hName = CreateWindowW(L"Edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_MULTILINE| WS_HSCROLL, 200, 275, 98, 38, hwnd, NULL, NULL, NULL);

    CreateWindowW(L"Static", L"Tag to be added:", WS_VISIBLE | WS_CHILD, 100, 325, 98, 38, hwnd, NULL, NULL, NULL);
    hTagToAdd = CreateWindowW(L"Edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_MULTILINE| WS_HSCROLL, 200, 320, 98, 38, hwnd, NULL, NULL, NULL);
    CreateWindowW(L"Button", L"ADD TAG", WS_VISIBLE | WS_CHILD | WS_BORDER, 300, 380, 98, 38, hwnd, (HMENU)GENERATE_BUTTON, NULL, NULL);
}


void insertValue(string tagName,string filePath){
   // Check whether there is already a set given the key.
   // If so, insert to the existing set.
   // Otherwise, create a set and add it to the map.
    string key,value;//Take file path from user
    cout<<tagName<<" "<<filePath<<endl;
    key=filePath;
    value=tagName;
   map<string, set<string> >::iterator found = myMap.find(key);
   if ( found != myMap.end() )
   {
      //cout << "Adding '" << value << "' to an existing set of " << key << "s.\n";
      found->second.insert(value);
   }
   else
   {
      //cout << "Adding '" << value << "' to a new set of " << key << "s.\n";
      set<string> temp;
      temp.insert(value);
      myMap.insert(make_pair(key, temp));
   }
    key=tagName;
    value=filePath;
    map<string, set<string> >::iterator found2 = TagPerFiles.find(key);
    if ( found2 != TagPerFiles.end() )
   {
      //cout << "Adding '" << value << "' to an existing set of " << key << "s.\n";
      found2->second.insert(value);
   }
   else
   {
      //cout << "Adding '" << value << "' to a new set of " << key << "s.\n";
      set<string> temp;
      temp.insert(value);
      TagPerFiles.insert(make_pair(key, temp));
   }
}

string getFiles(string tag)
{
    string out="";
    if ( myMap[tag].size()>0 )
   {
      //cout << "Print the present sets";
      for(auto& it : myMap[tag])
        {out=out+" "+it+" ";
         if(TagPerFiles[it].size()>0)
         {
             for(auto& it2 :TagPerFiles[it] )
                out=out+" "+it2+" ";
         }
         out=out+'\n';
        }
         }
   else
   {out=out+ "no such tag available";
   }// Check if tag is present in map, if not give error, else fetch the files and return them
return out;
}

string Chartostring(char cc[]) // Function to convert string to char array
{
    string temp="" ;
    int i=0;
    while(cc[i]!='+')
    {
        temp=temp+cc[i];
        i++;
    }
    return temp;
    //return convertedChar;
}


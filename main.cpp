#define WIN32_LEAN_AND_MEAN

#include <windows.h> //Windows API functions
#include <commctrl.h>
#include "keygen.h" //Armadillo Key generation
#include "resource.h" //resources

HINSTANCE hInst; //Declares the instance

char serial[256]=""; //Declare serial
char hwid_text[20]=""; //Declare hwid
char hwid_fix[20]=""; //Declare hwid_fix

BOOL CALLBACK DialogProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch(uMsg)
    {
    case WM_INITDIALOG:
    {
        SetWindowTextA(hwndDlg, TPoDT_TITLE);
        HICON hIcon;
        SendMessageA(hwndDlg, WM_COMMAND, IDC_EDT_HWID, 0);
        hIcon=LoadIcon(hInst, MAKEINTRESOURCE(ICON_1616));
        SendMessage(hwndDlg, WM_SETICON, ICON_BIG, (LPARAM)hIcon);
        SetDlgItemTextA(hwndDlg, IDC_EDT_HWID, "0000-0000");
    }
    return TRUE;

    case WM_CLOSE:
        EndDialog(hwndDlg, 0);
        return TRUE;

    case WM_COMMAND:
        switch(LOWORD(wParam))
        {
        case IDC_BTN_ABOUT:
            SetFocus(GetDlgItem(hwndDlg, IDC_EDT_CODE));
            MessageBoxA(hwndDlg, TPoDT_ABOUT, "About", MB_ICONINFORMATION);
            return TRUE;

        case IDC_BTN_GEN:
        {
            SetFocus(GetDlgItem(hwndDlg, IDC_EDT_CODE));
            SendMessageA(hwndDlg, WM_COMMAND, IDC_EDT_HWID, 0);
        }
        return TRUE;

        case IDC_EDT_HWID:
        {
            unsigned hardwarefp=0;
            int len=GetDlgItemTextA(hwndDlg, IDC_EDT_HWID, hwid_text, 20);
            if(len>7)
            {
                hwid_fix[0]=0;
                for(int i=0; i<len; i++)
                {
                    if((hwid_text[i]>47 and hwid_text[i]<58) or (hwid_text[i]>64 and hwid_text[i]<71))
                        wsprintfA(hwid_fix, "%s%c", hwid_fix, hwid_text[i]);
                }
                sscanf(hwid_fix, "%X", &hardwarefp);
                strcpy(serial, CreateSignedKey(TPoDT_LVL, (char*)"TPODT", (char*)"", hardwarefp, TPoDT_OTH0,TPoDT_OTH1,TPoDT_OTH2,TPoDT_OTH3,TPoDT_OTH4));
                SetDlgItemTextA(hwndDlg, IDC_EDT_CODE, serial); //Set 'serial' in the code box
            }
            else
            {
                SetDlgItemTextA(hwndDlg, IDC_EDT_CODE, "Please enter a valid HWID!");
            }
        }
        return TRUE;
        }
    }
    return FALSE;
}


int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    hInst=hInstance;
    InitCommonControls();
    return DialogBox(hInstance, MAKEINTRESOURCE(DLG_MAIN), NULL, (DLGPROC)DialogProc);
}

#include <Polycode.h>
#include "egb.h"
#include "PolycodeView.h"
#include "windows.h"

using namespace Polycode;

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    PolycodeView *view = new PolycodeView(hInstance, nCmdShow, L"Endless Ganja Bathroom");
    egb *game = new egb(view);

    MSG msg;
    do {
        if (PeekMessage(&msg, NULL, 0,0,PM_REMOVE)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
    } while(game->Update());

    delete view;
    delete game;
    return 0;
}
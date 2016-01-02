#include "Windows.h"
#include "Game.h"
#include <fcntl.h>
#include <io.h>
#include "Sound.h"

//#include "KeyBoard.h"
/*
*	CallBack Funtion
*	@Parameter
*	hWnd handle Windows ( what window will be process)
*	msg message ID
*	wParam unsigned int pointer function
*	LParam long signed int pointer function
*	Have to pass all the parameters in case they can be used
*	@return Pointer to function to process the msg
*/
#define FPS 60
#define MSPF 1000.0f/ 60




LRESULT WINAPI callBack( HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) 
{
	switch(msg)
	{
		case WM_DESTROY:
		PostQuitMessage(0);
		break;
		case WM_KEYDOWN:
                KeyBoard :: getInstace() -> onKeyPressed(wParam);
				break;
		case WM_KEYUP:
				KeyBoard :: getInstace() -> onKeyReleased(wParam);
				break;
	}
	return DefWindowProc(hWnd, msg, wParam, lParam); // Ensures that every fucking message is process!
													// return a default process for every default msg
}
/*
* Main fuction can not be overload
* @Parameters
* hInstance handle the instance Wnd
* 
*/ 
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE, LPWSTR, INT)
{
	#ifdef _DEBUG
	AllocConsole();

	HANDLE handle_out = GetStdHandle(STD_OUTPUT_HANDLE);
    int hCrt = _open_osfhandle((long) handle_out, _O_TEXT);
    FILE* hf_out = _fdopen(hCrt, "w");
    setvbuf(hf_out, NULL, _IONBF, 1);
    *stdout = *hf_out;

	HANDLE handle_in = GetStdHandle(STD_INPUT_HANDLE);
    hCrt = _open_osfhandle((long) handle_in, _O_TEXT);
    FILE* hf_in = _fdopen(hCrt, "r");
    setvbuf(hf_in, NULL, _IONBF, 128);
    *stdin = *hf_in;
	#endif


	WNDCLASSEX wc;
	ZeroMemory (&wc,sizeof(wc)); // Make all the parameters of this struct become 0

	wc.cbSize = sizeof( WNDCLASSEX);
	wc.lpfnWndProc = callBack;
	wc.hInstance = hInstance;
	wc.lpszClassName = L"My Frame Work"; // class name

	RegisterClassEx(&wc);// Register the WND class

	RECT rect;	// the rect represents for client area of the window
	rect.left = 100;
	rect.right = 100 + SCWIDTH * 2;
	rect.top = 100;
	rect.bottom = 100 + SCHEIGHT * 2;

	AdjustWindowRect (&rect, WS_OVERLAPPEDWINDOW, false); // automaticlly adjust the window depend on what its size

	HWND hWnd = CreateWindow (L"My Frame Work",    // create a handle window object by createWindow function
							L"Contra 2016", 
							WS_OVERLAPPEDWINDOW, 
							rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top,
							NULL,
							NULL,
							wc.hInstance,
							NULL);

	ShowWindow(hWnd, SW_SHOWDEFAULT); // show the window and how it is to be shown by the flag
	UpdateWindow(hWnd);

	MSG msg; // create the Message ( MSG) object the handle event
	ZeroMemory(&msg, sizeof(MSG));
	
	Game game(hWnd);
	

	__int64 cntsPerSec = 0; 
	QueryPerformanceFrequency((LARGE_INTEGER*)&cntsPerSec);

	float secsPerCnt = 1.0f / (float)cntsPerSec;

	float delta = 0.0f;

	unsigned int nFrameCount = 0;

	float timeCount = 0;

	__int64 currTimeStamp = 0; 

	__int64 prevTimeStamp = 0; 

	QueryPerformanceCounter((LARGE_INTEGER*)&prevTimeStamp);

	while ( msg.message != WM_QUIT) // the main game loop 
	{
		
		if(  PeekMessage(&msg, NULL, 0, 0, PM_REMOVE ) )// Have to process all the windows event
														// peek all the message int queue then remove it and process it
														// hWnd is NULL handle any event in current thread
														// range of messages to be examined ( 0, 0) returns all available messages
														// flag to remove event after process or not
		{
			TranslateMessage(&msg);
			DispatchMessage( &msg);
		}
		else
		{
			
			// Game Loop here

			bool render = false;

			QueryPerformanceCounter((LARGE_INTEGER*)&currTimeStamp);
			
			double deltaTimeInMiliSecond = (double)(currTimeStamp - prevTimeStamp) * secsPerCnt * 1000.0f;
			prevTimeStamp = currTimeStamp;
			
			delta += deltaTimeInMiliSecond; 
			timeCount += deltaTimeInMiliSecond;
			if( timeCount >= (double)1000.0f)
			{
				std::cout << "FPS : "<<nFrameCount <<"\n";
				nFrameCount = 0;
				timeCount = 0;

			}
			
			while(delta >= MSPF)
			{
				render = true;
				delta -= MSPF;
				game.update();
			}

			if(render )
			{
				nFrameCount++;
				game.render();
			}

		}
		
		
		

	}

	game.cleanUp();
	UnregisterClass( L"Framework Window",wc.hInstance );

	return 0;
}
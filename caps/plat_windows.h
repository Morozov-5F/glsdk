#ifndef PLATFORM_WINDOWS_H
#define PLATFORM_WINDOWS_H


#include <windows.h>		// Header File For Windows
#include <tchar.h>


namespace plat
{
	class Window
	{
	public:
		Window();
		~Window();

		void *GetParamForLoad();

		static LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

	private:
		HWND m_hWnd;
		HDC m_hDC;
		HGLRC m_hRC;
		HINSTANCE m_hInstance;

		//Called to cleanup.
		void KillWindow();
	};
}

#endif //PLATFORM_WINDOWS_H
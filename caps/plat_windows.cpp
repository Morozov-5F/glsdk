
#include <exception>
#include "plat_windows.h"


namespace plat
{
	Window::Window()
		: m_hWnd(NULL)
		, m_hDC(NULL)
		, m_hRC(NULL)
		, m_hInstance(NULL)
	{
		int			PixelFormat;			// Holds The Results After Searching For A Match
		WNDCLASS	wc;						// Windows Class Structure
		DWORD		dwExStyle;				// Window Extended Style
		DWORD		dwStyle;				// Window Style
		RECT		WindowRect;				// Grabs Rectangle Upper Left / Lower Right Values

		WindowRect.left=(long)0;
		WindowRect.right=(long)640;
		WindowRect.top=(long)0;
		WindowRect.bottom=(long)480;

		m_hInstance			= GetModuleHandle(NULL);				// Grab An Instance For Our Window

		wc.style			= CS_HREDRAW | CS_VREDRAW | CS_OWNDC;	// Redraw On Size, And Own DC For Window.
		wc.lpfnWndProc		= (WNDPROC) WndProc;					// WndProc Handles Messages
		wc.cbClsExtra		= 0;									// No Extra Window Data
		wc.cbWndExtra		= 0;									// No Extra Window Data
		wc.hInstance		= m_hInstance;							// Set The Instance
		wc.hIcon			= LoadIcon(NULL, IDI_WINLOGO);			// Load The Default Icon
		wc.hCursor			= LoadCursor(NULL, IDC_ARROW);			// Load The Arrow Pointer
		wc.hbrBackground	= NULL;									// No Background Required For GL
		wc.lpszMenuName		= NULL;									// We Don't Want A Menu
		wc.lpszClassName	= _T("OpenGL");								// Set The Class Name

		if (!RegisterClass(&wc))									// Attempt To Register The Window Class
		{
			throw std::exception("Failed To Register The Window Class.");
		}

		dwExStyle=WS_EX_APPWINDOW | WS_EX_WINDOWEDGE;			// Window Extended Style
		dwStyle=WS_OVERLAPPEDWINDOW;							// Windows Style

		AdjustWindowRectEx(&WindowRect, dwStyle, FALSE, dwExStyle);		// Adjust Window To True Requested Size

		// Create The Window
		if (!(m_hWnd=CreateWindowEx(	dwExStyle,							// Extended Style For The Window
			_T("OpenGL"),						// Class Name
			_T("Base Window"),								// Window Title
			dwStyle |							// Defined Window Style
			WS_CLIPSIBLINGS |					// Required Window Style
			WS_CLIPCHILDREN,					// Required Window Style
			0, 0,								// Window Position
			WindowRect.right-WindowRect.left,	// Calculate Window Width
			WindowRect.bottom-WindowRect.top,	// Calculate Window Height
			NULL,								// No Parent Window
			NULL,								// No Menu
			m_hInstance,						// Instance
			NULL)))								// Don't Pass Anything To WM_CREATE
		{
			throw std::exception("Window Creation Error.");
		}

		static	PIXELFORMATDESCRIPTOR pfd=				// pfd Tells Windows How We Want Things To Be
		{
			sizeof(PIXELFORMATDESCRIPTOR),				// Size Of This Pixel Format Descriptor
			1,											// Version Number
			PFD_DRAW_TO_WINDOW |						// Format Must Support Window
			PFD_SUPPORT_OPENGL |						// Format Must Support OpenGL
			PFD_DOUBLEBUFFER,							// Must Support Double Buffering
			PFD_TYPE_RGBA,								// Request An RGBA Format
			32,											// Select Our Color Depth
			0, 0, 0, 0, 0, 0,							// Color Bits Ignored
			0,											// No Alpha Buffer
			0,											// Shift Bit Ignored
			0,											// No Accumulation Buffer
			0, 0, 0, 0,									// Accumulation Bits Ignored
			24,											// 16Bit Z-Buffer (Depth Buffer)  
			8,											// No Stencil Buffer
			0,											// No Auxiliary Buffer
			PFD_MAIN_PLANE,								// Main Drawing Layer
			0,											// Reserved
			0, 0, 0										// Layer Masks Ignored
		};

		if (!(m_hDC=GetDC(m_hWnd)))							// Did We Get A Device Context?
		{
			KillWindow();								// Reset The Display
			throw std::exception("Can't Create A GL Device Context.");
		}

		if (!(PixelFormat=ChoosePixelFormat(m_hDC,&pfd)))	// Did Windows Find A Matching Pixel Format?
		{
			KillWindow();
			throw std::exception("Can't Find A Suitable PixelFormat.");
		}

		if(!SetPixelFormat(m_hDC,PixelFormat,&pfd))		// Are We Able To Set The Pixel Format?
		{
			KillWindow();
			throw std::exception("Can't Find A Suitable PixelFormat.");
		}

		if (!(m_hRC=wglCreateContext(m_hDC)))				// Are We Able To Get A Rendering Context?
		{
			KillWindow();
			throw std::exception("Can't Create A GL Rendering Context.");
		}

		if(!wglMakeCurrent(m_hDC, m_hRC))					// Try To Activate The Rendering Context
		{
			KillWindow();
			throw std::exception("Can't Create A GL Rendering Context.");
		}

		ShowWindow(m_hWnd,SW_SHOW);						// Show The Window
		SetForegroundWindow(m_hWnd);						// Slightly Higher Priority
		SetFocus(m_hWnd);									// Sets Keyboard Focus To The Window
	}

	Window::~Window()
	{
		KillWindow();
	}

	void Window::KillWindow()
	{
		if (m_hRC)											// Do We Have A Rendering Context?
		{
			wglMakeCurrent(NULL,NULL);
			wglDeleteContext(m_hRC);
		}

		if (m_hDC)					// Are We Able To Release The DC
		{
			ReleaseDC(m_hWnd, m_hDC);
		}

		if (m_hWnd)					// Are We Able To Destroy The Window?
		{
			DestroyWindow(m_hWnd);
		}

		UnregisterClass(_T("OpenGL"), m_hInstance);
		m_hInstance = NULL;
	}

	LRESULT CALLBACK Window::WndProc( HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam )
	{
		switch (uMsg)									// Check For Windows Messages
		{
		case WM_ACTIVATE:							// Watch For Window Activate Message
			{
				return 0;								// Return To The Message Loop
			}

		case WM_SYSCOMMAND:							// Intercept System Commands
			{
				switch (wParam)							// Check System Calls
				{
				case SC_SCREENSAVE:					// Screensaver Trying To Start?
				case SC_MONITORPOWER:				// Monitor Trying To Enter Powersave?
					return 0;							// Prevent From Happening
				}
				break;									// Exit
			}

		case WM_CLOSE:								// Did We Receive A Close Message?
			{
				PostQuitMessage(0);						// Send A Quit Message
				return 0;								// Jump Back
			}

		case WM_KEYDOWN:							// Is A Key Being Held Down?
			{
				return 0;								// Jump Back
			}

		case WM_KEYUP:								// Has A Key Been Released?
			{
				return 0;								// Jump Back
			}

		case WM_SIZE:								// Resize The OpenGL Window
			{
				return 0;								// Jump Back
			}
		}

		// Pass All Unhandled Messages To DefWindowProc
		return DefWindowProc(hWnd,uMsg,wParam,lParam);
	}

	void *Window::GetParamForLoad()
	{
		return (void*)m_hDC;
	}
}

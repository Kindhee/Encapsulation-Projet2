#include "pch.h"
#include "main.h"

class Ball_temp
{
public:
	Ball_temp(float lifetime)
	{
		this->lifetime = lifetime;

		x = 150;
		y = 150;

		ball.setRadius(lifetime);

		float rad = ball.getRadius();
		ball.setOrigin(rad/2, rad/2);

		speed = 0.1;
	}

	sf::CircleShape ball;

	float lifetime;

	float x;
	float y;

	int dirX = 1;
	int dirY = 1;

	float speed = 2;

	void draw(sf::RenderWindow* window)
	{
		lifetime -= 0.001;

		sf::Vector2u size = window->getSize();
		float rad = ball.getRadius();

		int futureX = x + dirX * speed;
		int futureY = y + dirY * speed;

		if (futureX > size.x-rad || futureX < 0)
			dirX = -dirX;
		if (futureY > size.y-rad || futureY < 0)
			dirY = -dirY;

		x += dirX * speed;
		y += dirY * speed;

		ball.setPosition(x, y);
		window->draw(ball);
	}
};

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	WNDCLASSEXW wcex;
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style          = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc    = WndProc;
	wcex.cbClsExtra     = 0;
	wcex.cbWndExtra     = 0;
	wcex.hInstance      = hInstance;
	wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_APP));
	wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName   = nullptr;
	wcex.lpszClassName  = L"WinAppClass";
	wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));
	if ( RegisterClassExW(&wcex)==0 )
		return 0;

	HWND hWnd = CreateWindowW(L"WinAppClass", L"Title", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);
	if ( hWnd==NULL )
		return 0;

#ifdef _DEBUG
	AllocConsole();
	FILE* pNewStdout = nullptr;
	FILE* pNewStderr = nullptr;
	FILE* pNewStdin = nullptr;

	::freopen_s(&pNewStdout, "CONOUT$", "w", stdout);
	::freopen_s(&pNewStderr, "CONOUT$", "w", stderr);
	::freopen_s(&pNewStdin, "CONIN$", "r", stdin);
#endif

	sf::RenderWindow window(hWnd);

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	float timer = 0;
	std::vector<Ball_temp*> balls;

	MSG msg;
	while (window.isOpen())
	{
		std::cout << timer << std::endl;
		timer+=0.333; // A adapter au delta time!
		while (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		window.clear();

		if (timer > 600)
		{
			timer = 0;
			Ball_temp* ball = new Ball_temp(60.f);
			balls.push_back(ball);
		}

		for (size_t i =balls.size(); i > 0; i--)
		{
			Ball_temp* b = balls[i-1];
			b->draw(&window);
			if (balls[i-1]->lifetime <= 0.f)
			{
				delete balls[i-1];
				balls.erase(balls.begin() + (i-1));
			}
		}

		window.display();
	}

#ifdef _DEBUG
	_CrtDumpMemoryLeaks();
#endif

	return 0;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
		case WM_COMMAND:
		{
			int id = LOWORD(wParam);
			int notif = HIWORD(wParam);
			return DefWindowProc(hWnd, message, wParam, lParam);
			break;
		}
		case WM_PAINT:
		{
			PAINTSTRUCT ps;
			HDC hdc = BeginPaint(hWnd, &ps);
			EndPaint(hWnd, &ps);
			break;
		}
		case WM_DESTROY:
		{
			PostQuitMessage(0);
			break;
		}
		default:
		{
			return DefWindowProc(hWnd, message, wParam, lParam);
			break;
		}
	}
	return 0;
}

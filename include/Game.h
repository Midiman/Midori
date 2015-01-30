#ifndef GAME_H
#define GAME_H

class Game
{
	public:
		Game(int argc, char *argv[]);
		~Game();
		
		bool	Init();
		bool	InitSubsystems();
		bool	InitData();

		void	Run();
		bool 	CheckForEvents();
		void	Update();
		void	Draw();
		void	End();
		
		int		GetWidth();
		int		GetHeight();
		int		GetHalfWidth();
		int		GetHalfHeight();
		
		void	OnError(int error, const char* desc);
		void	OnKeypress(GLFWwindow* window, int key, int scancode, int action, int mods);
		
	private:
		int		m_iWidth, m_iHeight;
		bool	m_bRunning, m_bRedraw, m_bWantsQuit;
		GLFWwindow*	m_window;
};

#endif

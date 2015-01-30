#include <iostream>
#include <string>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Game.h"

using namespace std;

Game::Game(int argc, char *argv[]) {
	m_iWidth = 1280;
	m_iHeight = 720;
	
	m_bRunning = true;
	m_bRedraw = false;
	m_bWantsQuit = false;
}

Game::~Game() {
	cout << "Game::~Game" << endl;
}

bool Game::Init() {
	cout << "Game::Init" << endl;
	
	if( !InitSubsystems() ) {
		return false;
	}
	if( !InitData() ) {
		return false;
	}
	return true;
}

bool Game::InitSubsystems() {
	if ( !glfwInit() ) { 
		return false; 
	}
	
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	glfwWindowHint(GLFW_SAMPLES, 2);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	m_window = glfwCreateWindow(m_iWidth, m_iHeight, "", NULL, NULL);
	
	if ( !m_window ) { 
		glfwTerminate(); 
		return false; 
	}
	
	glfwSetKeyCallback(m_window, OnKeypress );
	
	glfwMakeContextCurrent(m_window);
	
	
	return true;
}

bool Game::InitData() {
	return true;
}

bool Game::CheckForEvents() {
	m_bRedraw = true;
	if ( m_bWantsQuit ) { m_bRunning = false; }
	return true;
}

void Game::Run() {
	while (m_bRunning) {
		if ( CheckForEvents() ) {
			Update();
		}
		if (m_bRedraw) {
			m_bRedraw = false;
			Draw();
		}
	}
}

void Game::Update() {
	cout << "Game::Update" << endl;
	glfwPollEvents();
}

void Game::Draw() {
	cout << "Game::Draw" << endl;
	glfwSwapBuffers(m_window);
}

void Game::End() {
	cout << "Game::End" << endl;
	glfwDestroyWindow(m_window);
	glfwTerminate();
}

int Game::GetWidth() {
	return m_iWidth;
}

int Game::GetHeight() {
	return m_iHeight;
}

int Game::GetHalfWidth() {
	return m_iWidth / 2;
}

int Game::GetHalfHeight() {
	return m_iHeight / 2;
}

void Game::OnError(int error, const char* desc) {
	cout << desc << endl;
}

void Game::OnKeypress(GLFWwindow* window, int key, int scancode, int action, int mods) {
	if ( key == GLFW_KEY_ESCAPE && action == GLFW_PRESS ) {
		
	}
} 

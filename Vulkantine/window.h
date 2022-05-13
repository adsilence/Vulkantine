/*
class to handle window creation and management
*/
#pragma once

#include <string>

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

// Window class to handle the actual window object
class Window {
public:
	Window(int width, int height, std::string name);
	~Window();

	//remove copy constructors for memory purposes
	Window(const Window&) = delete;
	Window& operator=(const Window&) = delete;

	bool shouldClose();
	VkExtent2D getExtent() { return {static_cast<uint32_t>(width), static_cast<uint32_t>(height)}; }
	void createWindowSurface(VkInstance instance, VkSurfaceKHR* surface);

	bool windowResized() { return framebufferResized; }
	void resetWindowResizedFlag() { framebufferResized = false; }
	void setWindowShouldClose();
private:
	GLFWwindow* window;

	//window information
	int width;
	int height;
	std::string name;
	bool framebufferResized;

	void initWindow();
	static void framebufferResizeCallback(GLFWwindow* window, int width, int height);
};

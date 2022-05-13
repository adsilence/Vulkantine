/*
main driver for the engine
*/
#pragma once

#include "json.hpp"

#include "window.h"
#include "device.h"

using json = nlohmann::json;
extern json settings;

class Engine {
public:
	int width = settings["window_width"];
	int height = settings["window_height"];

	Engine();
	~Engine();

	void start();

	void update();
	void render();

	void stop();
private:
	Window window{width, height, "Vulkantine"};
	Device device{ window };
};


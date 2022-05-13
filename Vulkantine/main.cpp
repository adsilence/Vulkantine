/* 
Entry point for the program 
Right now it just sets global values and starts the engine
*/

#include "spdlog/spdlog.h"
#include "json.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <stb_image_write.h>

#include "engine.h"

#include <iostream>
#include <fstream>

using json = nlohmann::json;
json settings{};

int main() {
	std::ifstream in("res/settings.json");
	in >> settings;

	if (settings["dev_mode"] == true) {
		spdlog::set_level(spdlog::level::debug);
	}
	else {
		spdlog::set_level(spdlog::level::info);
	}

	Engine engine{};
	try {
		engine.start();
	}
	catch (const std::exception& e) {
		spdlog::critical("{}", e.what());
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
#include <unordered_map>
#include <fstream>
#include <sstream>
#include <iostream>

std::unordered_map<std::string, u32> key_mapping;

void load_input_config(const char* filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Could not open configuration file!" << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream stream(line);
        std::string action, key;
        if (std::getline(stream, action, '=') && std::getline(stream, key)) {
            if (key.size() == 1) {
                key_mapping[action] = toupper(key[0]);
            } else if (key == "UP") {
                key_mapping[action] = VK_UP;
            } else if (key == "DOWN") {
                key_mapping[action] = VK_DOWN;
            } else if (key == "LEFT") {
                key_mapping[action] = VK_LEFT;
            } else if (key == "RIGHT") {
                key_mapping[action] = VK_RIGHT;
            } else if (key == "ENTER") {
                key_mapping[action] = VK_RETURN;
            } else if (key == "ESC") {
                key_mapping[action] = VK_ESCAPE;
            }
        }
    }
}
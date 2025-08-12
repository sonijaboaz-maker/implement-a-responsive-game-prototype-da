#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// Game Prototype Dashboard API Specification

// Dashboard Configuration
struct DashboardConfig {
    int screenWidth;
    int screenHeight;
    std::string title;
};

// Game Prototype
struct GamePrototype {
    std::string name;
    std::string description;
    int players;
    std::vector<std::string> tags;
};

// Dashboard API
class Dashboard {
public:
    Dashboard(DashboardConfig config);
    ~Dashboard();

    void addGamePrototype(GamePrototype game);
    void removeGamePrototype(std::string gameName);
    void updateGamePrototype(std::string gameName, GamePrototype newGame);

    void displayDashboard();

private:
    DashboardConfig config_;
    std::vector<GamePrototype> gamePrototypes_;
};

// Implementation
Dashboard::Dashboard(DashboardConfig config) : config_(config) {}

Dashboard::~Dashboard() {}

void Dashboard::addGamePrototype(GamePrototype game) {
    gamePrototypes_.push_back(game);
}

void Dashboard::removeGamePrototype(std::string gameName) {
    auto it = std::find_if(gamePrototypes_.begin(), gamePrototypes_.end(),
                           [&gameName](const GamePrototype& game) {
                               return game.name == gameName;
                           });
    if (it != gamePrototypes_.end()) {
        gamePrototypes_.erase(it);
    }
}

void Dashboard::updateGamePrototype(std::string gameName, GamePrototype newGame) {
    auto it = std::find_if(gamePrototypes_.begin(), gamePrototypes_.end(),
                           [&gameName](const GamePrototype& game) {
                               return game.name == gameName;
                           });
    if (it != gamePrototypes_.end()) {
        *it = newGame;
    }
}

void Dashboard::displayDashboard() {
    std::cout << "Dashboard Title: " << config_.title << std::endl;
    std::cout << "Screen Size: " << config_.screenWidth << "x" << config_.screenHeight << std::endl;
    std::cout << "Game Prototypes:" << std::endl;
    for (const auto& game : gamePrototypes_) {
        std::cout << "  " << game.name << " - " << game.description << std::endl;
    }
}

int main() {
    DashboardConfig config;
    config.screenWidth = 1024;
    config.screenHeight = 768;
    config.title = "Game Prototype Dashboard";

    Dashboard dashboard(config);

    GamePrototype game1;
    game1.name = "Game 1";
    game1.description = "Description 1";
    game1.players = 2;
    game1.tags = {"tag1", "tag2"};

    GamePrototype game2;
    game2.name = "Game 2";
    game2.description = "Description 2";
    game2.players = 4;
    game2.tags = {"tag3", "tag4"};

    dashboard.addGamePrototype(game1);
    dashboard.addGamePrototype(game2);

    dashboard.displayDashboard();

    return 0;
}
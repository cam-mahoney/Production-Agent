#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

// --- Data Structures ---

struct Location {
    int id;
    std::string name;
    std::string notes;
};

struct Role {
    std::string name;
    std::string notes;
};

struct Line {
    int id;
    int scene_id;
    std::string text;
};

struct Scene {
    int id;
    std::string name;
    int location_id;
    std::string date_time;
    std::vector<int> line_ids;
};

int main() {
    // --- Initializing Data (Per Issue #4 Examples) ---

    // Locations: unordered_map for fast ID lookup
    std::unordered_map<int, Location> locations = {
        {101, {101, "Community Theater - Stage A", "Park in rear lot; check-in at stage door"}},
        {102, {102, "Downtown Coffee Shop", "Arrive 15 minutes early; quiet set"}}
    };

    // Role: Single record
    Role my_role = {"Camden - Supporting", "Wardrobe: blue jacket; Prop: notebook"};

    // Lines: vector for ordered iteration
    std::vector<Line> lines = {
        {1001, 1, "I thought this would be easier than it is."},
        {1002, 1, "But I showed up anyway."},
        {2001, 2, "You said you'd be here. I waited."}
    };

    // Scenes: vector for ordered iteration
    std::vector<Scene> scenes = {
        {1, "Opening Monologue", 101, "2026-05-02 09:00", {1001, 1002}},
        {2, "Coffee Shop Argument", 102, "2026-05-02 13:30", {2001}}
    };

    // --- Printing Summary ---
    std::cout << "--- ACTOR PRODUCTION SUMMARY ---" << std::endl;
    std::cout << "Role: " << my_role.name << " (" << my_role.notes << ")\n" << std::endl;

    for (const auto& scene : scenes) {
        // Resolve location name from the map
        std::string loc_name = locations.count(scene.location_id) ? locations.at(scene.location_id).name : "Unknown Location";

        std::cout << "SCENE " << scene.id << ": " << scene.name << std::endl;
        std::cout << "WHERE: " << loc_name << " @ " << scene.date_time << std::endl;
        std::cout << "LINES:" << std::endl;

        // Print associated lines
        for (const auto& line : lines) {
            if (line.scene_id == scene.id) {
                std::cout << "  [" << line.id << "] " << line.text << std::endl;
            }
        }
        std::cout << "-------------------------------" << std::endl;
    }

    return 0;
}

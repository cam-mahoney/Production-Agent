#pragma once

#include <string>
#include <vector>

struct Scene {
    int id = 0;
    std::string name;
    int location_id = 0;
    std::string date_time;
    std::vector<int> line_ids;

    Scene() = default;
    Scene(int id_, const std::string& name_, int location_id_, const std::string& date_time_, std::vector<int> line_ids_ = {});
};

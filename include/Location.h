#pragma once

#include <string>

struct Location {
    int id = 0;
    std::string name;
    std::string notes;

    Location() = default;
    Location(int id_, const std::string& name_, const std::string& notes_);
};

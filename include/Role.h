#pragma once

#include <string>

struct Role {
    std::string name;
    std::string notes;

    Role() = default;
    Role(const std::string& name_, const std::string& notes_);
};

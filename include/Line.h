#pragma once

#include <string>

struct Line {
    int id = 0;
    int scene_id = 0;
    std::string text;

    Line() = default;
    Line(int id_, int scene_id_, const std::string& text_);
};

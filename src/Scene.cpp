#include "Scene.h"

Scene::Scene(int id_, const std::string& name_, int location_id_, const std::string& date_time_, std::vector<int> line_ids_)
    : id(id_), name(name_), location_id(location_id_), date_time(date_time_), line_ids(std::move(line_ids_)) {}

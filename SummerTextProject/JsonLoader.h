#pragma once

#include <fstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <nlohmann/json.hpp>

template <typename T>
std::vector<T> LoadJsonArray(const std::string& filename)
{
    std::ifstream file(filename);

    if (!file.is_open())
    {
        throw std::runtime_error(
            "Could not open file: " + filename
        );
    }

    nlohmann::json data;
    file >> data;

    if (!data.is_array())
    {
        throw std::runtime_error(
            filename + " must contain a JSON array."
        );
    }

    return data.get<std::vector<T>>();
}
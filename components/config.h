#pragma once

#include <string>
#include <unordered_map>
#include <fstream>
#include <boost/lexical_cast.hpp>
#include <vector>
#include <iostream>

namespace universal_fa::components
{
    class Config
    {
    public:
        Config(const std::string& filename)
        {
            //parse file, left side of = is key, right side is value
            std::ifstream file(filename);
            
            if (!file.is_open())
                throw std::runtime_error("Failed to open file");

            std::string line;
            while (std::getline(file, line))
            {
                auto pos = line.find('=');
                if (pos == std::string::npos || line[0] == '#')
                    continue;
                m_data[line.substr(0, pos)] = line.substr(pos + 1);
            }
        }

        Config(const Config& other) = default;

        ~Config() = default;

        template <typename T>
        T get(const std::string& key, std::optional<T> default_value = std::nullopt) const
        {
            auto it = m_data.find(key);
            if (it == m_data.end())
            {
                if (default_value.has_value())
                    return default_value.value();
                else
                    std::cout << "Key not found: " << key << std::endl;
                    return T();
            }
            return boost::lexical_cast<T>(it->second);
        }

        template <typename T>
        std::vector<T> get_vector(const std::string& key, char delim, std::optional<std::vector<T>> default_value = std::nullopt) const
        {
            auto it = m_data.find(key);
            if (it == m_data.end())
            {
                if (default_value.has_value())
                    return default_value.value();
                else
                    std::cout << "Key not found: " << key << std::endl;
                    return std::vector<T>();
            }

            std::vector<T> result;
            std::string value = it->second;
            std::string token;
            std::istringstream tokenStream(value);
            while (std::getline(tokenStream, token, delim))
            {
                result.push_back(boost::lexical_cast<T>(token));
            }
            return result;
        }

    private:
        std::unordered_map<std::string, std::string> m_data;
    };
}

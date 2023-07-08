#include "../FiniteAutomataTester.h"
#include <filesystem>
#include <algorithm>

namespace universal_fa
{

FiniteAutomataTester::FiniteAutomataTester(const std::string& project_dir)
{
    //get all files in project_dir/configs
    std::string configs_dir = project_dir + "/configs";
    for (const auto& entry : std::filesystem::directory_iterator(configs_dir))
    {
        std::string file_path = entry.path().string();
        FiniteAutomata fa = utils::build_fa_from_file(file_path);
        m_fas.push_back(fa);
    }
    //write a lambda that sorts the vector of FAs by name
    auto sort_by_name = [](const FiniteAutomata& lhs, const FiniteAutomata& rhs)
    {
        //the names are in the format m_one, m_two, m_three, etc.
        auto lhs_name = lhs.get_name();
        auto rhs_name = rhs.get_name();
        
        //remove the m_ from the names
        lhs_name.erase(0, 2);
        rhs_name.erase(0, 2);

        //convert the names to ints
        static const std::unordered_map<std::string, int> name_to_int = { {"one", 1}, {"two", 2}, {"three", 3}, {"four", 4}, {"five", 5}, {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9}, {"ten", 10} };
        auto lhs_int = name_to_int.at(lhs_name);
        auto rhs_int = name_to_int.at(rhs_name);

        return lhs_int < rhs_int;
    };

    //sort the vector of FAs by name
    std::sort(m_fas.begin(), m_fas.end(), sort_by_name);

}

void FiniteAutomataTester::run()
{
    for (auto& fa : m_fas)
    {
        std::cout << "Testing FA: " << fa.get_name() << " rule is: " << fa.get_description() << std::endl;
        fa.process();
    }
}

}
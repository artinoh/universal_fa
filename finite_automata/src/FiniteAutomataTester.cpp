#include "../FiniteAutomataTester.h"
#include <filesystem>

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
}

}
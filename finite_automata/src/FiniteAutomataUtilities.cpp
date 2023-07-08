#include "../FiniteAutomataUtilities.h"

namespace universal_fa::utils
{
    FiniteAutomata build_fa_from_file(const std::string& file_path)
    {
        std::cout << "Building FA from file: " << file_path << std::endl;
        return FiniteAutomataBuilder().build();
    }
}
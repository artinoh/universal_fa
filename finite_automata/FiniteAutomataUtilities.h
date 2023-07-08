#pragma once

#include "FiniteAutomataBuilder.h"
#include <string>
#include <unordered_map>

namespace universal_fa::utils
{
    FiniteAutomata build_fa_from_file(const std::string& file_path);

}

#pragma once

#include "FiniteAutomataBuilder.h"
#include <string>
#include <unordered_map>

/*
Utility functions for building finite automata from files.

*/

namespace universal_fa::utils
{
    FiniteAutomata build_fa_from_file(const std::string& file_path);
}

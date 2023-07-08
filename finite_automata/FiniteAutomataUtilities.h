#pragma once

#include "../components/config.h"
#include "FiniteAutomataBuilder.h"
#include <string>


namespace universal_fa::utils
{
    FiniteAutomata build_fa_from_file(const std::string& file_path);
}

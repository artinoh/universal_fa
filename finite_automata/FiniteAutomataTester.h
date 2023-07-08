#pragma once
#include "FiniteAutomataUtilities.h"

namespace universal_fa
{

class FiniteAutomataTester
{
public:
    FiniteAutomataTester(const std::string& project_dir);

private:
    std::vector<FiniteAutomata> m_fas;

};

}
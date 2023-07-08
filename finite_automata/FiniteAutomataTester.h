#pragma once
#include "FiniteAutomataUtilities.h"
#include <vector>

namespace universal_fa
{

class FiniteAutomataTester
{
public:
    FiniteAutomataTester(const std::string& project_dir);
    void run();

private:
    std::vector<FiniteAutomata> m_fas;

};

}
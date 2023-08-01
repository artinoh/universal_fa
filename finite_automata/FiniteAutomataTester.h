#pragma once
#include "FiniteAutomataUtilities.h"
#include <vector>

/*
Constructs a vector of finite automata from a directory of automata files.
and runs the process method on each automata so they each process their test strings.

*/

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
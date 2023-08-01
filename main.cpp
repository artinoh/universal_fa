#include "finite_automata/FiniteAutomataTester.h"


/*
Requirements: GCC, CMake, Make
Run the build.sh script to build the project.
Once Build is complete, run the run.sh script to run the project.
The run script will run the program with the project directory as the argument.
This directory should contain a directory called configs, which contains the automata files.

The FinateAutomataTester class will create a finite automata for each file in the configs directory and run the process method on each automata.

Once compiled to test a new automata, add a new file to the configs directory with the naming convention: m_NUMBER.config
Example:
name=m_one
description=ends_with_0
initial_state=0
alphabet=0,1
final_states=1
transitions.0=0=1,1=0
transitions.1=0=1,1=0
test_strings=Λ,100,011,10abc1,0,1,0101011,11010,0001,1110

When the program is run via run.sh, it will print the transitions for each automata, then print the results of processing each test string for each automata.
*/


int main(int argc, char** argv)
{
    if (argc != 2)
    {
        std::cout << "Usage: " << argv[0] << " <project_dir>" << std::endl;
        return 1;
    }

    universal_fa::FiniteAutomataTester fa_tester(argv[1]);
    fa_tester.run();
    return 0;
}
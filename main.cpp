#include "finite_automata/FiniteAutomataTester.h"


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
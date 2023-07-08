#set c++ version
cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
project(universal_fa)


add_executable(universal_fa 
                main.cpp
                finite_automata/src/FiniteAutomata.cpp
                finite_automata/src/FiniteAutomataTester.cpp
                finite_automata/src/FiniteAutomataBuilder.cpp
                finite_automata/src/FiniteAutomataUtilities.cpp)

# Find the Boost libraries
find_package(Boost REQUIRED)


# Link the required libraries to the target
target_link_libraries(universal_fa 
                        ${Boost_LIBRARIES}
)

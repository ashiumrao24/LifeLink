cmake_minimum_required(VERSION 3.10)

project(LifeLink)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(LifeLink
    src/main.cpp
    src/application.cpp
    src/donor.cpp
    src/request.cpp
    src/matcher.cpp
    src/matchingEngine.cpp
    src/match.cpp
    src/distanceCalculator.cpp
    src/donorRepository.cpp
    src/requestRepository.cpp
    src/inputHelper.cpp
    src/dateUtils.cpp
)
cmake_minimum_required (VERSION 2.6)
project (ipcn)

# 使用C++11 g++ -std=c++11 
add_compile_options(-std=c++11)

#link_directories("${PROJECT_SOURCE_DIR}/lib/curlcpp-1.1/build/src")
link_directories("/usr/local/lib")
#include_directories("${PROJECT_SOURCE_DIR}/lib/curlcpp-1.1/include")

include_directories("/usr/local/include")

#  -ljsoncpp -lcurl
link_libraries(curl jsoncpp)

file(GLOB SRCS "*.cpp"  "*.h" "*.hpp" )

add_executable(ipcn ${SRCS} )
# 1. 声明要求的 CMake 最低版本
cmake_minimum_required(VERSION 3.10)
project(MyAlgorithmPro)

# 🟥 严师的防乱码装甲：强制 GCC 编译器输出 GBK 编码的可执行文件
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    add_compile_options(-fexec-charset=GBK)
endif()

# 下面是你原本的代码
add_executable(coin_target coin_change.cpp)
# 1. 声明要求的 CMake 最低版本
cmake_minimum_required(VERSION 3.10)

# 2. 给你的工程起个响亮的名字！
project(MyAlgorithmPro)

# 3. 核心指令：告诉 CMake，我要把 coin_change.cpp 编译成一个叫 coin_target 的可执行文件
add_executable(coin_target coin_change.cpp)

# 如果你以后想单独运行“打家劫舍”，只需要再加一行：
# add_executable(robber_target house_robber.cpp)
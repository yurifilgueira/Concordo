cmake_minimum_required(VERSION 3.16.3)
project(teste VERSION 0.1 LANGUAGES CXX )

include_directories( include )


add_executable( program
                src/application/Program.cpp
                src/entities/Channel.cpp 
                src/entities/Message.cpp
                src/entities/Server.cpp
                src/entities/User.cpp)
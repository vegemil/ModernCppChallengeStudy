
cmake_minimum_required(VERSION 3.1)

project(ModernCppChallenge LANGUAGES CXX)

set(CMAKE_MODULE_PATH       ${CMAKE_SOURCE_DIR}/Scripts)
set(ROOT_DIR                ${CMAKE_SOURCE_DIR})
set(CMAKE_INSTALL_PREFIX    ${CMAKE_SOURCE_DIR}/Solved)

include(GetModules)
include_directories(External/include)

# Ch.1 
add_subdirectory(Math/Problem01)
add_subdirectory(Math/Problem02)
add_subdirectory(Math/Problem03)
add_subdirectory(Math/Problem04)
add_subdirectory(Math/Problem05)
add_subdirectory(Math/Problem06)
add_subdirectory(Math/Problem07)
add_subdirectory(Math/Problem08)
add_subdirectory(Math/Problem09)
add_subdirectory(Math/Problem10)
add_subdirectory(Math/Problem11)
add_subdirectory(Math/Problem12)
add_subdirectory(Math/Problem13)
add_subdirectory(Math/Problem14)

# Ch.2
add_subdirectory(Language/Problem15)      
add_subdirectory(Language/Problem16)      
add_subdirectory(Language/Problem17)      
add_subdirectory(Language/Problem18)      
add_subdirectory(Language/Problem19)      
add_subdirectory(Language/Problem20)      
add_subdirectory(Language/Problem21)      
add_subdirectory(Language/Problem22)      

# Ch.3
add_subdirectory(Regex/Problem23)
add_subdirectory(Regex/Problem24)
add_subdirectory(Regex/Problem25)
add_subdirectory(Regex/Problem26)
add_subdirectory(Regex/Problem27)
add_subdirectory(Regex/Problem28)
add_subdirectory(Regex/Problem29)
add_subdirectory(Regex/Problem30)
add_subdirectory(Regex/Problem31)

# Ch.4
add_subdirectory(Filesystem/Problem32)    
add_subdirectory(Filesystem/Problem33)    
add_subdirectory(Filesystem/Problem34)    
add_subdirectory(Filesystem/Problem35)    
add_subdirectory(Filesystem/Problem36)    
add_subdirectory(Filesystem/Problem37)    
add_subdirectory(Filesystem/Problem38)    

# Ch.5
add_subdirectory(DateTime/Problem39)      
add_subdirectory(DateTime/Problem40)      
add_subdirectory(DateTime/Problem41)      
add_subdirectory(DateTime/Problem42)      
add_subdirectory(DateTime/Problem43)      
add_subdirectory(DateTime/Problem44)      

# Ch.6
#add_subdirectory(Algorithm/Problem45)    
add_subdirectory(Algorithm/Problem49)    
add_subdirectory(Algorithm/Problem51) 

# add_subdirectory(Concurrency)   # Ch.7
# add_subdirectory(Serialization) # Ch.9
# add_subdirectory(DesignPattern) # Ch.8
# add_subdirectory(Archives)      # Ch.10
# add_subdirectory(Database)      #
# add_subdirectory(Images)        # 
# add_subdirectory(Cryptography)  # Ch.11

# add_subdirectory(Extra)         # Bonus challenge!


if(CMAKE_COMPILER_IS_GNUCXX)
    add_definitions("-Wall -Wextra -Wno-unused-parameter -Wno-maybe-uninitialized")
endif()

if(MINGW)
  SET(CMAKE_C_LINK_EXECUTABLE "${CMAKE_C_LINK_EXECUTABLE} --static -static-libgcc")
  SET(CMAKE_CXX_LINK_EXECUTABLE "${CMAKE_CXX_LINK_EXECUTABLE} --static -static-libgcc -static-libstdc++")
endif()

if(MSVC)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MP /EHsc /GS")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /wd4065 /wd4244 /wd4267 /wd4800 /wd4996")
endif()

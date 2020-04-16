cmake_minimum_required(VERSION 3.5)
project(navio_vendor)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)

file(GLOB common_sources "src/Common/*.cpp")
file(GLOB navio_sources "src/Navio+/*.cpp")
file(GLOB navio2_sources "src/Navio2/*.cpp")
file(GLOB examples_sources "src/Examples/AHRS.cpp")

add_library(${PROJECT_NAME} SHARED
  ${common_sources}
  ${navio_sources}
  ${navio2_sources}
  ${examples_sources}
)

target_include_directories(${PROJECT_NAME} PUBLIC
  "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
  "$<INSTALL_INTERFACE:include>")


ament_export_include_directories(include)
ament_export_interfaces(export_${PROJECT_NAME})
ament_export_libraries(${PROJECT_NAME})


# add_executable(ahrs src/Examples/AHRS.cpp)

# target_link_libraries(ahrs 
#   navio_vendor
# )


if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # prevent cppcheck from being found, since it fails to process the file utest.cpp
  set(ament_cmake_cppcheck_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()

  # ament_add_gtest(${PROJECT_NAME}_utest test/utest.cpp)
  # if(TARGET ${PROJECT_NAME}_utest)
  #   target_include_directories(${PROJECT_NAME}_utest PUBLIC include)
  #   target_link_libraries(${PROJECT_NAME}_utest ${PROJECT_NAME})
  # endif()
endif()

ament_package()

install(DIRECTORY include/
  DESTINATION include)

install(TARGETS ${PROJECT_NAME}
  EXPORT export_${PROJECT_NAME}
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin)

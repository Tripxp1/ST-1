
include_directories(${${PROJECT_NAME}_SOURCE_DIR}/include)
set(header ${${PROJECT_NAME}_SOURCE_DIR}/include)
set(src ${${PROJECT_NAME}_SOURCE_DIR}/src/alg.cpp)

message(PROJECT_SOURCE_DIR="${src}")

add_library(${PROJECT_NAME} SHARED
  ${header}
  ${src})
  
add_executable(${PROJECT_NAME}.info main.cpp)
target_link_libraries(${PROJECT_NAME}.info ${PROJECT_NAME})

#file(COPY ${${PROJECT_NAME}_SOURCE_DIR}/src/checker.py DESTINATION "/home/runner/work/ADS-0/ADS-0")

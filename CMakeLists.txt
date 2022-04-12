cmake_minimum_required( VERSION 3.14 )
project( ActsDD4hep VERSION 0.1 LANGUAGES CXX )

add_library(ActsDD4hep INTERFACE)
target_include_directories(ActsDD4hep INTERFACE include)
target_link_libraries(ActsDD4hep INTERFACE DD4hep::DDCore)

install(
  TARGETS ActsDD4hep
  EXPORT ActsDD4hepTargets
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
# install(
  # DIRECTORY include/ActsDD4hep
  # DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

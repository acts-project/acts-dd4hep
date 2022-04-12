cmake_minimum_required( VERSION 3.14 )
project( ActsDD4hep VERSION 0.1 LANGUAGES CXX )

include(GNUInstallDirs) # GNU-like installation paths, e.g. lib/, include/, ...

set(public_headers
  "include/ActsDD4hep/ActsExtension.hpp"
  "include/ActsDD4hep/ActsExtension.ipp"
  "include/ActsDD4hep/ConvertMaterial.hpp"
)


add_library(ActsDD4hep INTERFACE ${public_headers})
target_link_libraries(ActsDD4hep INTERFACE DD4hep::DDCore)
target_include_directories(
  ActsDD4hep
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)
set_target_properties(ActsDD4hep PROPERTIES PUBLIC_HEADER "${public_headers}")

install(
  TARGETS ActsDD4hep
  EXPORT ActsDD4hepTargets
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/ActsDD4hep)

install(
  EXPORT ActsDD4hepTargets 
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/ActsDD4hep)


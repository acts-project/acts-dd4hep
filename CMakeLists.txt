cmake_minimum_required( VERSION 3.14 )
project( ActsDD4hep VERSION 1.0.0 LANGUAGES CXX )

include(GNUInstallDirs) # GNU-like installation paths, e.g. lib/, include/, ...

set(public_headers
  "include/ActsDD4hep/ActsExtension.hpp"
  "include/ActsDD4hep/ActsExtension.ipp"
  "include/ActsDD4hep/ConvertMaterial.hpp"
)

find_package(DD4hep 1.11 REQUIRED CONFIG COMPONENTS DDCore DDDetectors)

add_library(ActsDD4hep INTERFACE)
add_library(ActsDD4hep::ActsDD4hep ALIAS ActsDD4hep)
target_link_libraries(ActsDD4hep INTERFACE DD4hep::DDCore DD4hep::DDRec)
target_include_directories(
  ActsDD4hep
  INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)
set_target_properties(ActsDD4hep PROPERTIES PUBLIC_HEADER "${public_headers}")
set_target_properties(ActsDD4hep PROPERTIES EXPORT_NAME ActsDD4hep::ActsDD4hep)

install(
  TARGETS ActsDD4hep
  EXPORT ActsDD4hepTargets
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/ActsDD4hep)

install(
  EXPORT ActsDD4hepTargets 
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/ActsDD4hep)

include(CMakePackageConfigHelpers)
set(install_package_config_dir "${CMAKE_INSTALL_LIBDIR}/cmake/ActsDD4hep")

write_basic_package_version_file(
  ${PROJECT_BINARY_DIR}/ActsDD4hepConfigVersion.cmake
  COMPATIBILITY SameMajorVersion)
configure_package_config_file(
  ${CMAKE_CURRENT_LIST_DIR}/ActsDD4hepConfig.cmake.in
  ${PROJECT_BINARY_DIR}/ActsDD4hepConfig.cmake
  INSTALL_DESTINATION ${install_package_config_dir}
  PATH_VARS CMAKE_INSTALL_BINDIR CMAKE_INSTALL_INCLUDEDIR CMAKE_INSTALL_LIBDIR)

install(
  FILES
  ${PROJECT_BINARY_DIR}/ActsDD4hepConfig.cmake
  ${PROJECT_BINARY_DIR}/ActsDD4hepConfigVersion.cmake
  DESTINATION ${install_package_config_dir})

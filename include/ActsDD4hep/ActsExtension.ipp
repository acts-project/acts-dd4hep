// This file is part of the Acts project.
//
// Copyright (C) 2017-2018 CERN for the benefit of the Acts project
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.


inline Acts::ActsExtension::ActsExtension(const std::string& axes) {
  addType("axes", "definitions", axes);
}

inline Acts::ActsExtension::ActsExtension(const ActsExtension& ext,
                                   const dd4hep::DetElement& /*elem*/)
    : m_flagStore(ext.m_flagStore), m_values(ext.m_values) {}

inline double Acts::ActsExtension::getValue(const std::string& tag,
                                     const std::string& category) const
    noexcept(false) {
  return getT(m_values, tag, category);
}

inline void Acts::ActsExtension::addValue(double value, const std::string& tag,
                                   const std::string& category) {
  addT(m_values, value, tag, category, 0.0);
}

inline bool Acts::ActsExtension::hasCategory(const std::string& category) const {
  for (auto [key, value] : m_values) {
    if (key.find(category) != std::string::npos) {
      return true;
    }
  }
  return false;
}

inline bool Acts::ActsExtension::hasValue(const std::string& tag,
                                   const std::string& category) const {
  return hasT(m_values, tag, category);
}

inline bool Acts::ActsExtension::hasType(const std::string& type,
                                  const std::string& category) const {
  return hasT(m_flagStore, type, category);
}

inline void Acts::ActsExtension::addType(const std::string& type,
                                  const std::string& category,
                                  const std::string& word) {
  std::string catDec = "<-- category -->";
  addT(m_flagStore, word, type, category, catDec);
}

inline const std::string Acts::ActsExtension::getType(
    const std::string& type, const std::string& category) const
    noexcept(false) {
  return getT(m_flagStore, type, category);
}

inline std::string Acts::ActsExtension::toString() const {
  std::string rString = "--------------- Acts::ActsExtension --------------- ";
  rString += '\n';
  rString += "- flag store: ";
  rString += '\n';
  for (auto const& [key, value] : m_flagStore) {
    rString += key;
    rString += " : ";
    rString += value;
    rString += '\n';
  }
  rString += "- value store: ";
  rString += '\n';
  for (auto const& [key, value] : m_values) {
    rString += key;
    rString += " : ";
    rString += std::to_string(value);
    rString += '\n';
  }
  return rString;
}

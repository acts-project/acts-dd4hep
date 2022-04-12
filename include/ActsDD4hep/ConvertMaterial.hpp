
// This file is part of the Acts project.
//
// Copyright (C) 2022 CERN for the benefit of the Acts project
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#include "ActsDD4hep/ActsExtension.hpp"

#include <DD4hep/DetElement.h>
#include <DD4hep/DetFactoryHelper.h>

#include "XML/XMLElements.h"
#include <boost/foreach.hpp>
#include <boost/tokenizer.hpp>

namespace Acts {

/// Helper method that decorates an ActsExtension with proto material
/// description for boundaries
/// - it assigns bins for inner / representing / outer

/// Helper method that decorates an ActsExtension with proto material
/// description,
/// - it assigns bins for inner / representing / outer
///
/// @param x_material the material tag to be inspected
/// @param actsExtension the extension that is augmented
/// @param baseTag the xml tag to be checked
void xmlToProtoSurfaceMaterial(const xml_comp_t& x_material,
                               ActsExtension& actsExtension,
                               const std::string& baseTag);
}

inline void Acts::xmlToProtoSurfaceMaterial(const xml_comp_t& x_material,
                                     ActsExtension& actsExtension,
                                     const std::string& baseTag) {
  // Add the layer material flag
  actsExtension.addType(baseTag);
  // prepare everything here
  std::string mSurface = x_material.attr<std::string>("surface");
  std::string mBinning = x_material.attr<std::string>("binning");
  boost::char_separator<char> sep(",");
  boost::tokenizer binTokens(mBinning, sep);
  const auto n = std::distance(binTokens.begin(), binTokens.end());
  if (n == 2) {
    // Fill the bins
    auto bin = binTokens.begin();
    std::string bin0 = *(bin);
    std::string bin1 = *(++bin);
    size_t nBins0 = x_material.attr<int>("bins0");
    size_t nBins1 = x_material.attr<int>("bins1");
    // Add the material tags
    std::string btmSurface = baseTag + std::string("_") + mSurface;
    actsExtension.addValue(nBins0, bin0, btmSurface);
    actsExtension.addValue(nBins1, bin1, btmSurface);
  }
}

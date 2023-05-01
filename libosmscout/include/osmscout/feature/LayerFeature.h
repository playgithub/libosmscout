#ifndef OSMSCOUT_FEATURE_LAYERFEATURE_H
#define OSMSCOUT_FEATURE_LAYERFEATURE_H

/*
  This source is part of the libosmscout library
  Copyright (C) 2014  Tim Teulings

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307  USA
*/

#include <cstdint>
#include <limits>

#include <osmscout/TypeConfig.h>
#include <osmscout/TypeFeature.h>

#include <osmscout/FeatureReader.h>

namespace osmscout {

  class OSMSCOUT_API LayerFeatureValue : public FeatureValue
  {
  private:
    int8_t layer=0;

  public:
    LayerFeatureValue() = default;

    explicit LayerFeatureValue(int8_t layer)
      : layer(layer)
    {
      // no code
    }

    void SetLayer(int8_t layer)
    {
      this->layer=layer;
    }

    int8_t GetLayer() const
    {
      return layer;
    }

    void Read(FileScanner& scanner) override;
    void Write(FileWriter& writer) override;

    LayerFeatureValue& operator=(const FeatureValue& other) override;
    bool operator==(const FeatureValue& other) const override;
  };

  class OSMSCOUT_API LayerFeature : public Feature
  {
  private:
    TagId tagLayer;

  public:
    /** Name of this feature */
    static const char* const NAME;

  public:
    void Initialize(TagRegistry& tagRegistry) override;

    std::string GetName() const override;

    size_t GetValueAlignment() const override;
    size_t GetValueSize() const override;
    FeatureValue* AllocateValue(void* buffer) override;

    void Parse(TagErrorReporter& reporter,
               const TagRegistry& tagRegistry,
               const FeatureInstance& feature,
               const ObjectOSMRef& object,
               const TagMap& tags,
               FeatureValueBuffer& buffer) const override;
  };

  using LayerFeatureValueReader = FeatureValueReader<LayerFeature, LayerFeatureValue>;
}

#endif

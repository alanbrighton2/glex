#ifndef SFBOUNDINGBOX_H
#define SFBOUNDINGBOX_H

#include <memory>
#include <utility>
#include <ostream>

using namespace std;

#include "SFMath.h"

enum AXIS {X, Y, Z};

class SFBoundingBox {
public:
  SFBoundingBox(const Vector3, const float, const float, const float);
  virtual ~SFBoundingBox();
  void SetCentre(Vector3 &);

  bool CollidesWith(const shared_ptr<SFBoundingBox>);

private:
  shared_ptr<Vector3> centre, extent_x, extent_y, extent_z;

  pair<float,float> projectOntoAxis(const SFBoundingBox &, enum AXIS);

  friend class SFAsset;
  friend ostream& operator<<(ostream &, const SFBoundingBox &);
};

#endif

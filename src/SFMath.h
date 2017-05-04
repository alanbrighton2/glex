#ifndef SFMATH_H
#define SFMATH_H

/**
 * A Vector representation somewhat in the style of the IBM/Sony Vectormath library.
 */
class Vector3 {
public:
  inline Vector3 (const float, const float, const float);
  inline Vector3 (const Vector3 &);
  inline const float getX() const;
  inline const float getY() const;
  inline const float getZ() const;

  inline const Vector3 operator +( const Vector3 &) const;
  inline const Vector3 operator *( float) const;

private:
  float m_x, m_y, m_z;
};

inline Vector3::Vector3 (const float x, const float y, const float z) : m_x(x), m_y(y), m_z(z) {}

inline Vector3::Vector3 (const Vector3 &v) : m_x(v.m_x), m_y(v.m_y), m_z(v.m_z) {}

inline const float Vector3::getX() const {
  return m_x;
}

inline const float Vector3::getY() const {
  return m_y;
}

inline const float Vector3::getZ() const {
  return m_z;
}



inline const Vector3 Vector3::operator +( const Vector3 & vec ) const {
  return Vector3(
		 m_x + vec.m_x,
		 m_y + vec.m_y,
		 m_z + vec.m_z
		 );
}

inline const Vector3 Vector3::operator *( float scalar ) const {
  return Vector3 (
		 m_x * scalar,
		 m_y * scalar,
	         m_z * scalar
		 );
}

/**
 * A Point representation somewhat in the style of the IBM/Sony Vectormath library.
 */
class Point3 {
public:
  inline Point3 (const float, const float, const float);
  inline Point3 (const Vector3 &);
  inline Point3 (const Point3 &);
  inline const float getX() const;
  inline const float getY() const;
  inline const float getZ() const;
private:
  float m_x, m_y, m_z;
};

inline Point3::Point3 (const float x, const float y, const float z) : m_x(x), m_y(y), m_z(z) {}

inline Point3::Point3 (const Vector3 & v) : m_x(v.getX()), m_y(v.getY()), m_z(v.getZ()) {}

inline Point3::Point3 (const Point3 & p) : m_x(p.m_x), m_y(p.m_y), m_z(p.m_z) {}

inline const float Point3::getX() const {
  return m_x;
}

inline const float Point3::getY() const {
  return m_y;
}

inline const float Point3::getZ() const {
  return m_z;
}

/*
 * Useful functions
 */

inline static float projection( const Point3 & pnt, const Vector3 & unitVec ) {
  float result;
  result =  ( pnt.getX() * unitVec.getX() );
  result += ( pnt.getY() * unitVec.getY() );
  result += ( pnt.getZ() * unitVec.getZ() );
  return result;
}

static const Vector3 xAxis() {
  return Vector3(1.0f, 0.0f, 0.0f);
}

static const Vector3 yAxis() {
  return Vector3(0.0f, 1.0f, 0.0);
}

static const Vector3 zAxis() {
  return Vector3(0.0f, 0.0, 1.0f);
}


#endif

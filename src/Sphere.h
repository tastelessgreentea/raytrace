#ifndef SPHEREH
#define SPHEREH
#include "Hitable.h"

class Sphere: public Hitable {
public:
  Sphere() {}
  Sphere(Vec3 cen, float r): center(cen), radius(r) {};
  virtual bool hit(const Ray& r, float t_min, float t_maxx, HitRecord& rec) const;
  Vec3 center;
  float radius;

private:
  void hitableRecord(const Ray& r, HitRecord& rec, float t) const;
};

bool Sphere::hit(const Ray& r, float t_min, float t_max, HitRecord& rec) const {
  Vec3 oc = r.origin() - center;
  float a = dot(r.direction(), r.direction());
  float b = 2.0 * dot(oc, r.direction());
  float c = dot(oc, oc) - radius * radius;
  float discriminant = b * b - 4 * a * c;

  if (discriminant > 0) {
    float temp = (-b - sqrt(discriminant)) / (2.0 * a);
    if (temp < t_max && temp > t_min) {
      hitableRecord(r, rec, temp);
      return true;
    }
    temp = (-b + sqrt(discriminant)) / (2.0 * a);
    if (temp < t_max && temp > t_min) {
      hitableRecord(r, rec, temp);
      return true;
    }
  }

  return false;
}

void Sphere::hitableRecord(const Ray& r, HitRecord& rec, float t) const {
  rec.t = t;
  rec.p = r.point_at_parameter(rec.t);
  rec.normal = (rec.p - center) / radius;
}

#endif

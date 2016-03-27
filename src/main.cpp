#include <iostream>
#include "Sphere.h"
#include "HitableList.h"
#include "float.h"
#include "Camera.h"

Vec3 color(const Ray& r, Hitable* world) {
  HitRecord rec;
  if (world->hit(r, 0.0, MAXFLOAT, rec)) {
    return 0.5*Vec3(rec.normal.x()+1, rec.normal.y()+1, rec.normal.z()+1);
  }

  Vec3 unit_direction = unit_vector(r.direction());
  float t = 0.5 * (unit_direction.y() + 1.0);
  return (1.0-t) * Vec3(1.0,1.0,1.0) + t * Vec3(0.5, 0.7, 1.0);
}

int main() {
  int nx = 400;
  int ny = 200;
  int ns = 100;

  Hitable* list[2];
  list[0] = new Sphere(Vec3(0, 0, -1), 0.5);
  list[1] = new Sphere(Vec3(0, -100.5, -1), 100);
  Hitable *world = new HitableList(list, 2);
  Camera cam;
  std::cout << "P3\n" << nx << " " << ny << "\n255\n" << std::endl;
  for (int j = ny-1; j >= 0; j--) {
    for (int i = 0; i < nx; i++) {
      Vec3 c(0, 0, 0);
      for (int a=0; a < ns; a++) {
        float u = float(i + drand48()) / float(nx);
        float v = float(j + drand48()) / float(ny);
        Ray r = cam.get_ray(u, v);
        c += color(r, world);
      }
      c /= float(ns);

      int ir = int(255.99*c[0]);
      int ig = int(255.99*c[1]);
      int ib = int(255.99*c[2]);

      std::cout << ir << " " << ig << " " << ib << "\n";
    }
  }
}

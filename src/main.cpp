#include <iostream>
#include "Ray.h"

Vec3 color(const Ray& r) {
  Vec3 unit_direction = unit_vector(r.direction());
  float t = 0.5 * (unit_direction.y() + 1.0);
  return (1.0-t) * Vec3(1.0,1.0,1.0) + t * Vec3(0.5, 0.7, 1.0);
}

int main() {
  int nx = 400;
  int ny = 200;

  Vec3 lower_left_corner(-2.0, -1.0, -1.0);
  Vec3 horizontal(4.0, 0.0, 0.0);
  Vec3 vertical(0.0, 2.0, 0.0);
  Vec3 origin(0.0, 0.0, 0.0);

  std::cout << "P3\n" << nx << " " << ny << "\n255\n" << std::endl;
  for (int j = ny-1; j >= 0; j--) {
    for (int i = 0; i < nx; i++) {
      float u = float(i) / float(nx);
      float v = float(j) / float(ny);
      Ray r(origin, lower_left_corner + u * horizontal + v * vertical);
      Vec3 c = color(r);

      int ir = int(255.99*c[0]);
      int ig = int(255.99*c[1]);
      int ib = int(255.99*c[2]);

      std::cout << ir << " " << ig << " " << ib << "\n";
    }
  }
}

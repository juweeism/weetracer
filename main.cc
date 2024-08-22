#include "Include/color.h"
#include "Include/ray.h"
#include "Include/vec3.h"
#include <iostream>

int main() {

  // Image

  auto aspect_ratio = 16.0 / 9.0;
  int image_width = 400;

  int image_height = int(image_width / aspect_ratio);
  image_height = (image_height < 1) ? 1 : image_height;

  // Camera

  auto focal_length = 1.0;
  auto viewport_height = 2.0;
  auto viewport_width = viewport_height * (double(image_width) / image_height);
  auto camera_center = point3(0, 0, 0);

  // Render

  std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

  for (int j = 0; j < image_height; j++) {
    std::clog << "\rScanlines remaining: " << (image_height - j) << ' '
              << std::flush;
    for (int i = 0; i < image_width; i++) {
      auto r = double(i) / (image_width - 1);
      auto g = double(j) / (image_height - 1);
      auto b = 0.0;

      auto pixel_color = color(r, g, b);
      write_color(pixel_color);
    }
  }
  std::clog << "\rDone.                 \n";
}

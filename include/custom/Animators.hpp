#ifndef ANIMATORS_INCLUDE_CPP_
#define ANIMATORS_INCLUDE_CPP_

#include <raylib-cpp.hpp>
#include <custom/Utils.hpp>

namespace Animators {
  class PizzaCircle {
    private:
      float progress, radius, starting_angle, progress_until_spin, segments;
      bool reverse;
      raylib::Vector2 center;
      raylib::Color color;
    public:
      PizzaCircle(raylib::Vector2 center, float radius, raylib::Color color,float starting_angle = 0, float progress = 0, float progress_until_spin = 0.16, float segments = 100);
      void animate(float delta_progress);
      void draw();
      float getProgress();
      void setReverse(bool set);
      ~PizzaCircle();
    };
}

#endif

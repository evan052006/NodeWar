#include "Color.hpp"
#include "raylib.h"
#include <cmath>
#include <enet/enet.h>
#include <raylib-cpp.hpp>
#include <custom/Utils.hpp>
#include <custom/Animators.hpp>

Animators::PizzaCircle::PizzaCircle(raylib::Vector2 center, float radius, raylib::Color color,float starting_angle, float progress, float progress_until_spin, float segments) {
  this->center = center;
  this->radius = radius;
  this->color = color;
  this->starting_angle = starting_angle;
  this->progress = progress;
  this->progress_until_spin = progress_until_spin;
  this->segments = segments;
}

void Animators::PizzaCircle::draw() {
  if (progress < progress_until_spin) {
    float current_radius = Utils::map_value(progress, 0, progress_until_spin, 0, radius);
    float x = current_radius * std::cos(DEG2RAD * starting_angle) + center.x;
    float y = current_radius * std::sin(DEG2RAD * starting_angle) + center.y;
    DrawLineV(center, raylib::Vector2(x, y), color);
  } else {
    float endAngle = Utils::map_value(progress, progress_until_spin, 1, 0, 360);
//    endAngle = std::fmod(endAngle + starting_angle, 360);
    DrawCircleSector(center, radius, starting_angle, endAngle + starting_angle, 100, color);
  } 
}

void Animators::PizzaCircle::animate(float delta_progress) {
  progress = std::fmod(progress + delta_progress, 1);
  draw();
}

Animators::PizzaCircle::~PizzaCircle() {
}

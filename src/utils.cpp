#include <custom/Utils.hpp>

float Utils::map_value(float value, float value_min, float value_max, float target_min, float target_max) {
    return (value - value_min)*(target_max - target_min)/(value_max - value_min) + target_min;
}

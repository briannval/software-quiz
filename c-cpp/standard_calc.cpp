#include "stdbool.h"
#include "standard_calc.h"
#include <cmath>
#include <algorithm>

using namespace std;

/**
 * @brief Bounds the provided angle between [-180, 180) degrees.
 *
 * e.g.)
 *      bound_to_180(135) = 135.0
 *      bound_to_180(200) = -160.0
 *
 * @param angle: The input angle in degrees.
 *
 * @return float: The bounded angle in degrees.
 */
float bound_to_180(float angle) {
    // Same explanation as Python version, standard_calc.py

    angle = fmod(angle, 360);

    if (angle >= 180.0f) {
        return angle - 360.0f;
    }

    if (angle <= 180.0f) {
        return angle + 360.0f;
    }

    return angle;
}

/**
 * @brief Determines whether an angle is between two other angles
 *
 *  e.g.)
 *      is_angle_between(0, 45, 90) = true
 *      is_angle_between(45, 90, 270) = false
 * 
 * @param first_angle:  The first bounding angle in degrees.
 * @param middle_angle: The angle in question in degrees.
 * @param second_angle: The second bounding angle in degrees.
 * @return bool: TRUE when `middle_angle` is not in the reflex angle of `first_angle` and `second_angle`, FALSE otherwise
 */
bool is_angle_between(float first_angle, float middle_angle, float second_angle) {
    // Same explanation as Python version, standard_calc.py

    float bounded_first_angle = bound_to_180(first_angle);
    float bounded_second_angle = bound_to_180(second_angle);
    float bounded_middle_angle = bound_to_180(middle_angle);

    if (bounded_middle_angle == bounded_first_angle || bounded_middle_angle == bounded_second_angle) {
        return true;
    }

    float abs_diff = abs(bounded_second_angle - bounded_first_angle);
    float greater_angle = max(bounded_first_angle, bounded_second_angle);
    float smaller_angle = min(bounded_first_angle, bounded_second_angle);

    if (abs_diff == 180.0f) {
        return true;
    }

    if (abs_diff > 180.0f) {
        return bounded_middle_angle > greater_angle || bounded_middle_angle < smaller_angle;
    }

    return bounded_middle_angle < greater_angle && bounded_middle_angle > smaller_angle;
}

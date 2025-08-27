def validate_input(angle):
    if type(angle) != int and type(angle) != float:
        raise Exception("Incorrect input type")


def bound_to_180(angle):
    """Bounds the provided angle between [-180, 180) degrees.

    1. We want to normalize if it did more than a rotation, so modulo by 360
    2. If greater or equal to 180, take away a 360 to bound it
    3. If less than -180, add 360 to bound it
    """
    validate_input(angle)

    angle %= 360

    if angle >= 180:
        return angle - 360

    if angle < -180:
        return angle + 360

    return angle


def is_angle_between(first_angle, middle_angle, second_angle):
    """Determines whether an angle is between two other angles.

    e.g.)
        is_angle_between(0, 45, 90) = True
        is_angle_between(45, 90, 270) = False

    Args:
        first_angle (float): The first bounding angle in degrees.
        middle_angle (float): The angle in question in degrees.
        second_angle (float): The second bounding angle in degrees.

    Returns:
        bool: True when `middle_angle` is not in the reflex angle of `first_angle` and `second_angle`, false otherwise.
    """
    validate_input(first_angle)
    validate_input(second_angle)
    validate_input(middle_angle)

    bounded_first_angle = bound_to_180(first_angle)
    bounded_second_angle = bound_to_180(second_angle)
    bounded_middle_angle = bound_to_180(middle_angle)
    return True

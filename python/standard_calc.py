def validate_input(angle):
    if isinstance(angle, int) or isinstance(angle, float):
        return
    raise Exception("Incorrect input type")


def bound_to_180(angle):
    """Bounds the provided angle between [-180, 180) degrees.

    We want to normalize if it did more than a rotation, so modulo by 360
    If greater or equal to 180, take away a 360 to shift it within the range
    If less than -180, add 360 to shift it within the range
    This ensures the returned value is always within the range [-180, 180)

    Keep in mind that all operations are manipulations using a full circle (360),
    so we are sure that it will not modify the value

    The implementation below satisfies the above.
    The same explanation holds for the C++ version.
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

    The condition is that the middle angle cannot be within the REFLEX angle.

    A reflex angle is > 180 and < 360, so it's the longer arc between the first and second angle,
    that the middle angle cannot be contained in.

    The two angles are the endpoints that bound the arcs, they are not inside either arc.
    Hence, if the middle angle is equal to either, then it is contained in between, since
    it is not possible for it to be in a reflex angle.

    Then we define Ga and Sa which are the greater and smaller angles of the two,
    after being bounded using previous function

    If abs(Ga - Sa) = 180, then the two angles are 180 degrees apart,
    so both arcs are NOT reflex angles.

    Hence, by vacuous truth, the middle angle is always between both angles.

    Now, if abs(Ga - Sa) > 180, then [Sa, Ga] is the range of the reflex,
    so middle MUST NOT be in that range.

    However, if abs(Ga - Sa) < 180, then [Sa, Ga] is the range of the non-reflex,
    so middle MUST be in that range.

    The implementation below satisfies the above.
    The same explanation holds for the C++ version.
    """
    validate_input(first_angle)
    validate_input(second_angle)
    validate_input(middle_angle)

    bounded_first_angle = bound_to_180(first_angle)
    bounded_second_angle = bound_to_180(second_angle)
    bounded_middle_angle = bound_to_180(middle_angle)

    if (
        bounded_middle_angle == bounded_first_angle
        or bounded_middle_angle == bounded_second_angle
    ):  # not in either arcs
        return True

    abs_diff = abs(bounded_second_angle - bounded_first_angle)
    greater_angle = max(bounded_first_angle, bounded_second_angle)
    smaller_angle = min(bounded_first_angle, bounded_second_angle)

    print(bounded_first_angle)
    print(bounded_second_angle)
    print(abs_diff)

    if abs_diff == 180:  # the alternate is also 180, so always True
        return True

    if abs_diff > 180:  # then we should check the inverse for the non-reflex angle
        return (
            bounded_middle_angle > greater_angle or bounded_middle_angle < smaller_angle
        )

    return bounded_middle_angle < greater_angle and bounded_middle_angle > smaller_angle

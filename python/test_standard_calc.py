from standard_calc import bound_to_180, is_angle_between

""" Tests for bound_to_180() """


def test_bound_basic1():
    """
    Different cases to consider
    1. Zero
    2. Integer
    3. Decimal
    4. Boundary
    """

    assert bound_to_180(0) == 0
    assert bound_to_180(0.0) == 0.0

    assert bound_to_180(180) == -180
    assert bound_to_180(30) == 30
    assert bound_to_180(270) == -90
    assert bound_to_180(8815) == 175

    assert bound_to_180(179.5) == 179.5
    assert bound_to_180(179.99999) == 179.99999


""" Tests for is_angle_between() """


def test_between_basic1():
    """
    1. Test equal
    2. Test vacuous
    3. Test diff not in reflex
    4. Test diff in reflex
    """
    assert is_angle_between(0, 1, 2)

    assert is_angle_between(1, 1, 2)
    assert is_angle_between(1, 2, 2)

    assert is_angle_between(0, -180, 450)
    assert is_angle_between(1080, 1260, 67890029)  # random number

    assert not is_angle_between(45, 90, 270)
    assert not is_angle_between(10, 50, 350)
    assert is_angle_between(10, 0, 350)
    assert is_angle_between(80, 90, -170)

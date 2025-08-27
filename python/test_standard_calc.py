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


""" Tests for is_angle_between() """


def test_between_basic1():
    assert is_angle_between(0, 1, 2)

inherit M_TEST;

/**
 * @var {"/std/item/key"} testOb
 */

void test_is_key () {
    expect("is_key returns true", (: ({
        assert_equal(testOb->is_key(), 1),
        assert_equal(testOb->is_item(), 1),
        assert_equal(testOb->is_weapon(), 0),
        assert_equal(testOb->is_armor(), 0),
        assert_equal(testOb->is_living(), 0),
    }) :));
}

void test_direct_lock_str_with_obj () {
    expect("direct_lock_str_with_obj returns true", (: ({
        assert_equal(testOb->direct_lock_str_with_obj(), 0),
        assert_equal(testOb->direct_lock_str_with_obj("direction"), 0),
        assert_equal(testOb->direct_lock_str_with_obj("direction", "bad key"), 0),
        assert_equal(testOb->direct_lock_str_with_obj("direction", testOb), 1),
    }) :));
}
void test_direct_unlock_str_with_obj () {
    expect("direct_unlock_str_with_obj returns true", (: ({
        assert_equal(testOb->direct_unlock_str_with_obj(), 0),
        assert_equal(testOb->direct_unlock_str_with_obj("direction"), 0),
        assert_equal(testOb->direct_unlock_str_with_obj("direction", "bad key"), 0),
        assert_equal(testOb->direct_unlock_str_with_obj("direction", testOb), 1),
    }) :));
}
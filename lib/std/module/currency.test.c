inherit M_TEST;

private nosave object testOb;
void before_each_test () {
    if (objectp(testOb)) destruct(testOb);
    testOb = clone_object("/std/module/currency.c");
}
void after_each_test () {
    if (objectp(testOb)) destruct(testOb);
}

void test_currencies () {
    expect_function("query_currencies", testOb);
    expect_function("query_currency", testOb);
    expect_function("add_currency", testOb);

    expect("query_currency returns -1 for invalid currency", (: ({
        assert_equal(testOb->query_currency("unknown"), -1),
        assert_equal(testOb->query_currency("invalid"), -1),
    }) :));
    expect("currency handles adding and querying", (: ({
        assert_equal(testOb->query_currencies(), ({ })),
        assert_equal(testOb->query_currency("copper"), 0),

        assert_equal(testOb->add_currency("copper", -10), 0), // can't remove
        assert_equal(testOb->query_currencies(), ({ })),
        assert_equal(testOb->query_currency("copper"), 0), // still 0

        assert_equal(testOb->add_currency("copper", 10), 1), // add
        assert_equal(testOb->query_currencies(), ({ "copper" })),
        assert_equal(testOb->query_currency("copper"), 10),

        assert_equal(testOb->add_currency("copper", -100), 0), // can't remove
        assert_equal(testOb->query_currencies(), ({ "copper" })),
        assert_equal(testOb->query_currency("copper"), 10), // still 10

        assert_equal(testOb->add_currency("copper", -5), 1), // can remove
        assert_equal(testOb->query_currencies(), ({ "copper" })), // some remains
        assert_equal(testOb->query_currency("copper"), 5),
    }) :));
}
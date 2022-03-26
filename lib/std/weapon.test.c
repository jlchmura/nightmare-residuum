inherit M_TEST;
inherit STD_CONTAINER;

private nosave object testOb;
void before_each_test () {
    if (!testOb) testOb = clone_object("/std/weapon.c");
}
void after_each_test () {
    if (objectp(testOb)) destruct(testOb);
}
string *test_order () {
    return ({ "test_is_weapon", "test_type", "test_wielded", });
}
string *test_ignore () {
    return ::test_ignore() + ({ "query_wieldable_limbs", "query_wielded_weapons" });
}

nosave private string *__WieldableLimbs;
string *query_wieldable_limbs () {
    return __WieldableLimbs;
}
nosave private object *__WieldedWeapons;
object *query_wielded_weapons () {
    return __WieldedWeapons;
};

void test_is_weapon () {
    expect_function("is_weapon", testOb);
    expect("is_weapon returns true", (: ({
        assert(testOb->is_weapon(), "==", 1),
        assert(testOb->is_item(), "==", 1),
        assert(testOb->is_armor(), "==", UNDEFINED),
        assert(testOb->is_food(), "==", UNDEFINED),
    }) :));
}

void test_type () {
    expect_function("query_type", testOb);
    expect_function("set_type", testOb);

    expect("weapon handles type", (: ({
        assert(testOb->query_type(), "==", 0),

        testOb->set_type("blade"),
        assert(testOb->query_type(), "==", "blade"),

        testOb->set_type("knife"),
        assert(testOb->query_type(), "==", "knife"),
    }) :));
}

void test_wielded () {
    expect_function("query_wielded", testOb);
    expect_function("set_wielded", testOb);
    expect_function("query_short", testOb);

    testOb->set_short("weapon");
    expect("weapon handles wielded", (: ({
        assert(testOb->query_wielded(), "==", 0),
        assert(testOb->query_short(), "==", "weapon"),

        testOb->set_wielded(this_object()),
        assert(testOb->query_wielded(), "==", this_object()),
        assert(testOb->query_short(), "==", "weapon (wielded)"),
    }) :));
}

void test_item_verb_wield_applies () {
    expect_function("direct_wield_obj", testOb);
    expect_function("direct_unwield_obj", testOb);

    __WieldableLimbs = ({ "left hand", "right hand" });
    __WieldedWeapons = ({ });

    expect("weapon handles verb apply direct_wield_obj", (: ({
        assert(environment(testOb), "==", 0),
        assert(testOb->direct_wield_obj(), "==", 0),
        assert(testOb->handle_move(this_object()), "==", 1),
        assert(environment(testOb), "==", this_object()),
        assert(testOb->direct_wield_obj(), "==", 1),

        __WieldedWeapons += ({ testOb }),
        testOb->set_wielded(this_object()),
        assert(testOb->direct_unwield_obj(), "==", 1),
    }) :));

    __WieldableLimbs = 0;
    __WieldedWeapons = 0;
}

// void test_handle_eat () {
//     object r = new(STD_ROOM);

//     expect_function("handle_eat", testOb);

//     expect("food handle_eat behaves", (: ({
//         // setup food
//         assert(testOb->set_strength(5), "==", 0),
//         assert(testOb->query_strength(), "==", 5),

//         // setup test object
//         assert(this_object()->handle_move($(r)), "==", 1),
//         assert(this_object()->update_vitals(), "==", 0), // initialize vitals
//         assert(this_object()->add_hp(5), "==", 0),
//         assert(this_object()->query_hp(), "==", 5),
//         assert(this_object()->add_sp(5), "==", 0),
//         assert(this_object()->query_sp(), "==", 5),
//         assert(this_object()->add_mp(5), "==", 0),
//         assert(this_object()->query_mp(), "==", 5),

//         // test eating
//         assert(testOb->handle_eat(this_object()), "==", 0),
//         assert(this_object()->query_hp(), "==", 10),
//         assert(this_object()->query_sp(), "==", 10),
//         assert(this_object()->query_mp(), "==", 10),

//         assert(objectp(testOb), "==", 0), // food was removed
//     }) :));

//     // cleanup
//     this_object()->handle_move("/domain/Nowhere/room/void.c");
//     if (r) destruct(r);
// }
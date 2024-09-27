inherit M_TEST;

void test_gender () {
    expect("gender settable and queryable", (: ({
        assert_equal(testOb->query_gender(), "neither"),

        testOb->set_gender("male"),
        assert_equal(testOb->query_gender(), "male"),

        testOb->set_gender("female"),
        assert_equal(testOb->query_gender(), "female"),

        testOb->set_gender("neither"),
        assert_equal(testOb->query_gender(), "neither"),

        testOb->set_gender(0),
        assert_equal(testOb->query_gender(), "none"),

        testOb->set_gender("invalid"),
        assert_equal(testOb->query_gender(), "none"),
    }) :));
}

void test_species () {
    expect("species settable and queryable", (: ({
        assert_equal(testOb->query_species(), "unknown"),

        testOb->set_species("human"),
        assert_equal(testOb->query_species(), "human"),

        testOb->set_species("custodian"),
        assert_equal(testOb->query_species(), "custodian"),

        assert_catch((: testOb->set_species(UNDEFINED) :), "*Bad argument 1 to body->set_species\n"),
    }) :));
}

void test_limbs () {
    expect("species limbs are queryable", (: ({
        assert_equal(testOb->query_limbs(), ({ })),

        testOb->set_species("human"),
        assert_equal(sort_array(testOb->query_limbs(), 1), ({ "head", "left arm", "left foot", "left hand", "left leg", "right arm", "right foot", "right hand", "right leg", "torso" })),

        assert_equal(testOb->query_limb("torso"), ([ "damage": 0, "maxdamage": 1, "pct": 100, "status": 0, "type": "FATAL", ])),
    }) :));

    expect("species random limb behaves", (: ({
        // check random limb is valid
        assert_equal(member_array(testOb->query_random_limb(), ({ "head", "left arm", "left foot", "left hand", "left leg", "right arm", "right foot", "right hand", "right leg", "torso" })) > -1, 1),
        // run a second check
        assert_equal(member_array(testOb->query_random_limb(), ({ "head", "left arm", "left foot", "left hand", "left leg", "right arm", "right foot", "right hand", "right leg", "torso" })) > -1, 1),
    }) :));
}

void test_limbs_and_level () {
    destruct(testOb);
    testOb = new(STD_LIVING);
    expect("setting species first has maxdamage", (: ({
        testOb->set_stat("endurance", 20),
        testOb->set_species("human"),
        testOb->set_level(10),
        assert_equal(testOb->query_limb("torso"), ([ "damage": 0, "maxdamage": 342, "pct": 100, "status": 0, "type": "FATAL" ])),
    }) :));

    destruct(testOb);
    testOb = new(STD_LIVING);
    expect("setting level first has maxdamage", (: ({
        testOb->set_stat("endurance", 20),
        testOb->set_level(10),
        testOb->set_species("human"),
        assert_equal(testOb->query_limb("torso"), ([ "damage": 0, "maxdamage": 342, "pct": 100, "status": 0, "type": "FATAL" ])),
    }) :));

    destruct(testOb);
    testOb = new(STD_LIVING);
    expect("maxdamage to increase with endurance", (: ({
        testOb->set_stat("endurance", 20),
        testOb->set_level(10),
        testOb->set_species("human"),
        assert_equal(testOb->query_limb("torso"), ([ "damage": 0, "maxdamage": 342, "pct": 100, "status": 0, "type": "FATAL" ])),

        testOb->set_stat("endurance", 40),
        assert_equal(testOb->query_limb("torso"), ([ "damage": 0, "maxdamage": 562, "pct": 100, "status": 0, "type": "FATAL" ])),
    }) :));

    destruct(testOb);
}

void test_injections () {
    expect("injections are addable and queryable", (: ({
        assert_equal(testOb->query_injections(), ([ ])),

        testOb->add_injection("healing nanites", 5),
        assert_equal(testOb->query_injection("healing nanites"), 5),
        assert_equal(testOb->query_injections(), ([ "healing nanites": 5, ])),

        testOb->add_injection("healing nanites", 5),
        assert_equal(testOb->query_injections(), ([ "healing nanites": 10, ])),
        assert_equal(testOb->query_injection("healing nanites"), 10),

        testOb->add_injection("damaging nanites", 5),
        assert_equal(testOb->query_injections(), ([ "healing nanites": 10, "damaging nanites": 5, ])),
        assert_equal(testOb->query_injection("damaging nanites"), 5),

        testOb->add_injection("damaging nanites", 5),
        assert_equal(testOb->query_injections(), ([ "healing nanites": 10, "damaging nanites": 10, ])),
        assert_equal(testOb->query_injection("damaging nanites"), 10),
    }) :));

    destruct(testOb);
    testOb = new(STD_LIVING);
    expect("injections are handled by heart_beat", (: ({
        testOb->set_race("human"),
        testOb->set_level(1),
        testOb->add_injection("healing nanites", 10),
        testOb->add_injection("damaging nanites", 10),

        // heart_beat for handle_injections
        testOb->heart_beat(),

        // damaging nanites work before healing nanites
        assert_equal(testOb->query_injections(), ([ "healing nanites": 10, "damaging nanites": 8, ])),
        assert_equal(testOb->query_injection("healing nanites"), 10),
        assert_equal(testOb->query_injection("damaging nanites"), 8),

        // heart_beat for handle_injections
        testOb->heart_beat(),

        // damaging nanites work before healing nanites again
        assert_equal(testOb->query_injections(), ([ "healing nanites": 10, "damaging nanites": 6, ])),
        assert_equal(testOb->query_injection("healing nanites"), 10),
        assert_equal(testOb->query_injection("damaging nanites"), 6),

        // remove damaging nanites for healing nanites test
        testOb->add_injection("damaging nanites", -6),
        assert_equal(testOb->query_injection("damaging nanites"), 0),

        // heart_beat for handle_injections
        testOb->heart_beat(),

        // damaging nanites work before healing nanites again
        assert_equal(testOb->query_injections(), ([ "healing nanites": 8, ])),
        assert_equal(testOb->query_injection("healing nanites"), 8),

        // heart_beat for handle_injections
        testOb->heart_beat(),

        // damaging nanites work before healing nanites again
        assert_equal(testOb->query_injections(), ([ "healing nanites": 6, ])),
        assert_equal(testOb->query_injection("healing nanites"), 6),
    }) :));
}

void test_heal () {
    destruct(testOb);
    testOb = new(STD_LIVING);

    expect("heal restores hp/sp/mp and limb damage", (: ({
        testOb->set_species("human"),
        // verify initial state
        assert_equal(testOb->query_hp(), 22),
        assert_equal(testOb->query_sp(), 12),
        assert_equal(testOb->query_mp(), 12),
        assert_equal(testOb->query_limb("torso"), ([ "damage": 0, "maxdamage": 23, "pct": 100, "status": 0, "type": "FATAL" ])),

        // reduce vitals/limbs
        testOb->set_hp(1),
        testOb->set_sp(1),
        testOb->set_mp(1),
        testOb->handle_limb_heal("torso", -20),
        // verify reduced vitals/limbs
        assert_equal(testOb->query_hp(), 1),
        assert_equal(testOb->query_sp(), 1),
        assert_equal(testOb->query_mp(), 1),
        assert_equal(testOb->query_limb("torso"), ([ "damage": 20, "maxdamage": 23, "pct": 100, "status": 0, "type": "FATAL" ])),

        // test heal vitals/limbs
        testOb->heal(10),
        assert_equal(testOb->query_hp(), 11),
        assert_equal(testOb->query_sp(), 11),
        assert_equal(testOb->query_mp(), 11),
        assert_equal(testOb->query_limb("torso"), ([ "damage": 15, "maxdamage": 23, "pct": 100, "status": 0, "type": "FATAL" ])),
    }) :));
}
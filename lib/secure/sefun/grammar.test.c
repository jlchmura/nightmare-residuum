#include <time.h>

inherit M_TEST;

private nosave object testOb;
void before_all_tests () {
    testOb = clone_object("/secure/sefun/grammar");
}
void after_all_tests () {
    if (objectp(testOb)) destruct(testOb);
}

void test_remove_article () {
    string *values = ({}), *results = ({});

    expect_function("remove_article", testOb);

    values += ({ testOb->remove_article("thing") });
    results += ({ "thing" });
    values += ({ testOb->remove_article("the thing") });
    results += ({ "thing" });
    values += ({ testOb->remove_article("a thing") });
    results += ({ "thing" });
    values += ({ testOb->remove_article("an item") });
    results += ({ "item" });

    expect_arrays_equal(values, results, "remove_article handled articles");
}

void test_cardinal () {
    string *values = ({}), *results = ({});

    expect_function("cardinal", testOb);

    values += ({ testOb->cardinal(0) });
    results += ({ "zero" });
    values += ({ testOb->cardinal(1) });
    results += ({ "one" });
    values += ({ testOb->cardinal(-1) });
    results += ({ "negative one" });
    values += ({ testOb->cardinal(10) });
    results += ({ "ten" });
    values += ({ testOb->cardinal(-10) });
    results += ({ "negative ten" });
    values += ({ testOb->cardinal(100) });
    results += ({ "one hundred" });
    values += ({ testOb->cardinal(1000) });
    results += ({ "one thousand" });
    values += ({ testOb->cardinal(10000) });
    results += ({ "ten thousand" });
    values += ({ testOb->cardinal(12345) });
    results += ({ "twelve thousand, three hundred and forty-five" });
    values += ({ testOb->cardinal(-12345) });
    results += ({ "negative twelve thousand, three hundred and forty-five" });
    values += ({ testOb->cardinal(100000) });
    results += ({ "many" });
    values += ({ testOb->cardinal(-100000) });
    results += ({ "negative many" });

    expect_arrays_equal(values, results, "cardinal handled numbers");
}

void test_pluralize () {
    string *values = ({}), *results = ({});
    object ob;

    expect_function("pluralize", testOb);

    // test parameter as string
    values += ({ testOb->pluralize("elf") });
    results += ({ "elves" });
    values += ({ testOb->pluralize("staff") });
    results += ({ "staves" });
    values += ({ testOb->pluralize("a red house") });
    results += ({ "red houses" });
    values += ({ testOb->pluralize("a sack of rice") });
    results += ({ "sacks of rice" });
    values += ({ testOb->pluralize("plumbus") });
    results += ({ "plumbi" });
    values += ({ testOb->pluralize("gooblebox") });
    results += ({ "goobleboxes" });
    values += ({ testOb->pluralize("flooblecrank") });
    results += ({ "flooblecranks" });
    values += ({ testOb->pluralize("bloobleyank") });
    results += ({ "bloobleyanks" });

    // test parameter as object
    ob = new(STD_OBJECT);
    ob->set_name("tester");
    values += ({ testOb->pluralize(ob) });
    results += ({ "testers" });
    // @TODO plural_name override
    // ob->set_plural_name("gaggle of testers")
    // values += ({ testOb->(ob) });
    // results += ({ "gaggle of testers" });

    expect_arrays_equal(values, results, "pluralize handled words");
}

void test_consolidate () {
    string *values = ({}), *results = ({});

    expect_function("consolidate", testOb);

    values += ({ testOb->consolidate(5, "elf") });
    results += ({ "five elves" });

    values += ({ testOb->consolidate(0, "giraffe") });
    results += ({ "zero giraffes" });

    values += ({ testOb->consolidate(25, "cat") });
    results += ({ "twenty-five cats" });

    values += ({ testOb->consolidate(54321, "dog") });
    results += ({ "fifty-four thousand, three hundred and twenty-one dogs" });

    values += ({ testOb->consolidate(-54321, "care") });
    results += ({ "negative fifty-four thousand, three hundred and twenty-one cares" });

    expect_arrays_equal(values, results, "pluralize handled words");
}
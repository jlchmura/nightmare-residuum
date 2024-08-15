inherit STD_NPC;

void create () {
    ::create();
    set_name("R-0111010");
    set_id(({ "synthetic creature", "synthetic", "creature", }));
    set_short("a synthetic creature");
    set_long("A creature seemingly constructed of synthetic components. It consists of a large elongated torso structure supported by four jointed legs, all encased in a scale-like exoskeleton. There are two articulated arms at each end of the structure, almost looking like a type of crustacean. The creature does not seem to have a discernable head or face.");
    set_species("custodian");
}

string *names = ({ });
void handle_receive_living_in_env (object living) {
    string name;
    ::handle_receive_living_in_env(living);

    if (!living->is_character()) return;

    name = living->query_cap_name();
    if (member_array(name, names) == -1) {
        handle_command("say Welcome to our facility, " + name + ".");
        names += ({ name });
        call_out((: names -= ({ $1 }) :), 30, name);
    }
}
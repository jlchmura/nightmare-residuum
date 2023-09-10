inherit STD_ITEM;

string sculpture_long () {
    string desc = "";
    object tc = this_character();
    string prop;

    if (tc && (prop = tc->query_property("human_museum")) && !regexp(prop, "s1")) {
        tc->set_property("human_museum",  prop + "s1");
    }

    if (query_account_setting("screenreader") == "on") {
        desc += "It depicts a blue and white planet off the horizon of the grey surface of an orbiting moon against the dark backdrop of space.";
    } else {
        // https://dom111.github.io/image-to-ansi/
        desc = "#!PAGER!#";
        desc += "\e[38;5;0;48;5;0m▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄\e[38;5;254;48;5;0m▄▄\e[38;5;255;48;5;0m▄\e[38;5;188;48;5;0m▄\e[38;5;233;48;5;0m▄\e[38;5;0;48;5;0m▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄\e[48;5;0m \e[m\n";
        desc += "\e[38;5;0;48;5;0m                                  \e[38;5;248;48;5;0m▄\e[38;5;238;48;5;251m▄\e[38;5;251;48;5;8m▄\e[38;5;239;48;5;254m▄\e[38;5;102;48;5;250m▄\e[38;5;59;48;5;242m▄\e[38;5;0;48;5;248m▄\e[38;5;0;48;5;0m▄\e[48;5;0m\n";
        desc += "\e[38;5;0;48;5;0m                                  \e[38;5;238;48;5;246m▄\e[38;5;245;48;5;233m▄\e[38;5;242;48;5;237m▄\e[38;5;246;48;5;246m▄\e[38;5;248;48;5;243m▄\e[38;5;249;48;5;237m▄\e[38;5;0;48;5;236m▄\e[48;5;0m\n";
        desc += "\e[38;5;0;48;5;0m                                  \e[38;5;0;48;5;234m▄\e[38;5;237;48;5;238m▄\e[38;5;239;48;5;102m▄\e[38;5;59;48;5;102m▄\e[38;5;247;48;5;248m▄\e[38;5;145;48;5;248m▄\e[38;5;0;48;5;0m▄\e[48;5;0m\n";
        desc += "\e[38;5;0;48;5;0m                                   \e[38;5;235;48;5;238m▄\e[38;5;246;48;5;248m▄\e[38;5;248;48;5;245m▄\e[38;5;243;48;5;239m▄\e[38;5;247;48;5;0m▄\e[38;5;240;48;5;0m▄\e[38;5;252;48;5;236m▄\e[38;5;8;48;5;0m▄\e[48;5;0m\n";
        desc += "\e[38;5;0;48;5;0m                                \e[38;5;232;48;5;0m▄\e[38;5;253;48;5;0m▄\e[38;5;251;48;5;0m▄\e[38;5;252;48;5;247m▄\e[38;5;252;48;5;8m▄\e[38;5;7;48;5;59m▄\e[38;5;255;48;5;145m▄\e[38;5;254;48;5;8m▄\e[38;5;239;48;5;240m▄\e[38;5;246;48;5;252m▄\e[38;5;249;48;5;254m▄\e[38;5;188;48;5;255m▄\e[38;5;254;48;5;0m▄\e[38;5;0;48;5;0m▄\e[48;5;0m\n";
        desc += "\e[38;5;0;48;5;0m                              \e[38;5;0;48;5;0m▄\e[38;5;252;48;5;251m▄\e[38;5;251;48;5;255m▄\e[38;5;254;48;5;254m▄\e[38;5;254;48;5;253m▄\e[38;5;254;48;5;254m▄▄\e[38;5;251;48;5;188m▄\e[38;5;188;48;5;253m▄\e[38;5;188;48;5;254m▄\e[38;5;249;48;5;247m▄\e[38;5;242;48;5;242m▄\e[38;5;250;48;5;59m▄\e[38;5;240;48;5;246m▄\e[38;5;102;48;5;188m▄\e[38;5;255;48;5;0m▄\e[38;5;0;48;5;0m▄\e[48;5;0m\n";
        desc += "\e[38;5;0;48;5;0m                              \e[38;5;102;48;5;238m▄\e[38;5;251;48;5;251m▄\e[38;5;59;48;5;251m▄\e[38;5;247;48;5;251m▄\e[38;5;188;48;5;252m▄\e[38;5;188;48;5;188m▄\e[38;5;253;48;5;254m▄\e[38;5;254;48;5;253m▄\e[38;5;251;48;5;253m▄▄\e[38;5;248;48;5;250m▄\e[38;5;8;48;5;246m▄\e[38;5;239;48;5;247m▄\e[38;5;0;48;5;238m▄\e[38;5;239;48;5;240m▄\e[38;5;59;48;5;245m▄\e[38;5;245;48;5;255m▄\e[38;5;251;48;5;0m▄\e[38;5;0;48;5;0m▄\e[48;5;0m\n";
        desc += "\e[38;5;0;48;5;0m                              \e[38;5;248;48;5;242m▄\e[38;5;252;48;5;7m▄\e[38;5;248;48;5;250m▄\e[38;5;232;48;5;239m▄\e[38;5;245;48;5;246m▄\e[38;5;251;48;5;145m▄\e[38;5;254;48;5;250m▄\e[38;5;254;48;5;254m▄\e[38;5;250;48;5;255m▄\e[38;5;252;48;5;254m▄\e[38;5;7;48;5;251m▄\e[38;5;248;48;5;248m▄\e[38;5;247;48;5;246m▄\e[38;5;0;48;5;0m▄\e[38;5;0;48;5;234m▄\e[38;5;238;48;5;59m▄\e[38;5;59;48;5;59m▄\e[38;5;243;48;5;241m▄\e[38;5;236;48;5;0m▄\e[48;5;0m\n";
        desc += "\e[38;5;0;48;5;0m                              \e[38;5;145;48;5;251m▄\e[38;5;250;48;5;252m▄\e[38;5;8;48;5;247m▄\e[38;5;0;48;5;0m▄\e[38;5;241;48;5;246m▄\e[38;5;242;48;5;249m▄\e[38;5;246;48;5;249m▄\e[38;5;247;48;5;252m▄\e[38;5;145;48;5;7m▄\e[38;5;145;48;5;250m▄\e[38;5;247;48;5;249m▄\e[38;5;247;48;5;145m▄\e[38;5;245;48;5;8m▄\e[48;5;0m   \e[38;5;0;48;5;237m▄\e[38;5;0;48;5;241m▄\e[48;5;0m\n";
        desc += "\e[38;5;0;48;5;0m                              \e[38;5;253;48;5;249m▄\e[38;5;247;48;5;248m▄\e[38;5;0;48;5;238m▄\e[48;5;0m \e[38;5;250;48;5;59m▄\e[38;5;254;48;5;245m▄\e[38;5;188;48;5;245m▄\e[38;5;254;48;5;253m▄\e[38;5;251;48;5;188m▄\e[38;5;254;48;5;252m▄\e[38;5;250;48;5;249m▄\e[38;5;7;48;5;245m▄\e[38;5;241;48;5;242m▄\e[48;5;0m\n";
        desc += "\e[38;5;0;48;5;0m                             \e[38;5;236;48;5;0m▄\e[38;5;255;48;5;255m▄\e[38;5;253;48;5;252m▄\e[38;5;0;48;5;0m▄▄\e[38;5;250;48;5;253m▄\e[38;5;252;48;5;254m▄\e[38;5;252;48;5;250m▄\e[38;5;7;48;5;253m▄\e[38;5;251;48;5;254m▄\e[38;5;251;48;5;188m▄\e[38;5;251;48;5;145m▄\e[38;5;251;48;5;7m▄\e[38;5;248;48;5;248m▄\e[48;5;0m\n";
        desc += "\e[38;5;0;48;5;0m                             \e[38;5;246;48;5;248m▄\e[38;5;254;48;5;254m▄\e[38;5;251;48;5;188m▄\e[38;5;0;48;5;0m▄\e[38;5;7;48;5;243m▄\e[38;5;188;48;5;248m▄\e[38;5;188;48;5;102m▄\e[38;5;246;48;5;249m▄\e[38;5;246;48;5;250m▄\e[38;5;245;48;5;145m▄\e[38;5;246;48;5;7m▄\e[38;5;246;48;5;145m▄\e[38;5;250;48;5;249m▄\e[38;5;251;48;5;245m▄\e[48;5;0m\n";
        desc += "\e[38;5;0;48;5;0m                             \e[38;5;0;48;5;59m▄\e[38;5;254;48;5;254m▄\e[38;5;0;48;5;145m▄\e[38;5;0;48;5;0m▄\e[38;5;249;48;5;252m▄\e[38;5;252;48;5;254m▄\e[38;5;253;48;5;254m▄\e[38;5;253;48;5;246m▄\e[38;5;237;48;5;246m▄\e[38;5;249;48;5;245m▄\e[38;5;245;48;5;242m▄\e[38;5;255;48;5;7m▄\e[38;5;255;48;5;253m▄\e[38;5;252;48;5;252m▄\e[48;5;0m\n";
        desc += "\e[38;5;0;48;5;0m                             \e[38;5;0;48;5;236m▄\e[38;5;246;48;5;253m▄\e[38;5;253;48;5;232m▄\e[38;5;254;48;5;0m▄\e[38;5;246;48;5;245m▄\e[38;5;250;48;5;250m▄\e[38;5;252;48;5;188m▄\e[38;5;252;48;5;253m▄\e[38;5;145;48;5;8m▄\e[38;5;237;48;5;247m▄\e[38;5;252;48;5;252m▄\e[38;5;253;48;5;255m▄\e[38;5;255;48;5;255m▄\e[38;5;254;48;5;253m▄\e[38;5;0;48;5;0m▄\e[48;5;0m\n";
        desc += "\e[38;5;0;48;5;0m                             \e[38;5;0;48;5;0m▄\e[38;5;237;48;5;241m▄\e[38;5;246;48;5;247m▄\e[38;5;251;48;5;243m▄\e[38;5;249;48;5;243m▄\e[38;5;247;48;5;145m▄\e[38;5;7;48;5;7m▄\e[38;5;252;48;5;252m▄\e[38;5;248;48;5;249m▄\e[38;5;237;48;5;8m▄\e[38;5;247;48;5;251m▄\e[38;5;7;48;5;253m▄\e[38;5;253;48;5;254m▄\e[38;5;255;48;5;254m▄\e[38;5;251;48;5;241m▄\e[48;5;0m\n";
        desc += "\e[38;5;0;48;5;0m                               \e[38;5;0;48;5;235m▄\e[38;5;0;48;5;247m▄\e[38;5;0;48;5;254m▄\e[38;5;8;48;5;247m▄\e[38;5;248;48;5;250m▄\e[38;5;250;48;5;252m▄\e[38;5;250;48;5;247m▄\e[38;5;0;48;5;0m▄\e[38;5;59;48;5;8m▄\e[38;5;145;48;5;145m▄\e[38;5;252;48;5;188m▄\e[38;5;254;48;5;255m▄\e[38;5;253;48;5;253m▄\e[38;5;0;48;5;0m▄\e[48;5;0m\n";
        desc += "\e[38;5;0;48;5;0m                                  \e[38;5;0;48;5;59m▄\e[38;5;242;48;5;102m▄\e[38;5;247;48;5;248m▄\e[38;5;145;48;5;251m▄\e[48;5;0m \e[38;5;0;48;5;0m▄\e[38;5;233;48;5;242m▄\e[38;5;252;48;5;253m▄\e[38;5;254;48;5;254m▄\e[38;5;253;48;5;254m▄\e[48;5;0m\n";
        desc += "\e[38;5;0;48;5;0m                                   \e[38;5;243;48;5;242m▄\e[38;5;7;48;5;7m▄\e[38;5;145;48;5;245m▄\e[38;5;234;48;5;0m▄\e[38;5;241;48;5;0m▄\e[38;5;0;48;5;0m▄\e[38;5;238;48;5;247m▄\e[38;5;251;48;5;188m▄\e[38;5;188;48;5;255m▄\e[38;5;253;48;5;0m▄\e[48;5;0m\n";
        desc += "\e[38;5;0;48;5;0m                                   \e[38;5;8;48;5;8m▄\e[38;5;242;48;5;8m▄\e[38;5;242;48;5;242m▄\e[38;5;236;48;5;237m▄\e[38;5;8;48;5;242m▄\e[38;5;0;48;5;0m▄▄\e[38;5;238;48;5;240m▄\e[38;5;239;48;5;8m▄\e[38;5;246;48;5;7m▄\e[38;5;188;48;5;232m▄\e[38;5;0;48;5;0m▄\e[48;5;0m\n";
        desc += "\e[38;5;0;48;5;0m                                   \e[38;5;242;48;5;8m▄\e[38;5;245;48;5;247m▄\e[38;5;248;48;5;248m▄\e[38;5;248;48;5;246m▄\e[38;5;243;48;5;102m▄\e[48;5;0m  \e[38;5;0;48;5;0m▄\e[38;5;240;48;5;242m▄\e[38;5;8;48;5;8m▄\e[38;5;248;48;5;253m▄\e[38;5;7;48;5;252m▄\e[38;5;0;48;5;0m▄\e[48;5;0m\n";
        desc += "\e[38;5;0;48;5;0m                                   \e[38;5;0;48;5;233m▄\e[38;5;241;48;5;8m▄\e[38;5;248;48;5;250m▄\e[38;5;247;48;5;248m▄\e[38;5;246;48;5;243m▄\e[38;5;0;48;5;0m▄\e[48;5;0m  \e[38;5;0;48;5;236m▄\e[38;5;242;48;5;102m▄\e[38;5;241;48;5;246m▄\e[38;5;247;48;5;250m▄\e[38;5;232;48;5;0m▄\e[48;5;0m\n";
        desc += "\e[38;5;0;48;5;0m                                   \e[38;5;239;48;5;0m▄\e[38;5;239;48;5;238m▄\e[38;5;243;48;5;246m▄\e[38;5;249;48;5;248m▄\e[38;5;247;48;5;247m▄\e[38;5;0;48;5;239m▄\e[48;5;0m   \e[38;5;0;48;5;0m▄\e[38;5;59;48;5;8m▄\e[38;5;245;48;5;246m▄\e[38;5;247;48;5;248m▄\e[48;5;0m\n";
        desc += "\e[38;5;0;48;5;0m                                   \e[38;5;0;48;5;242m▄\e[38;5;246;48;5;8m▄\e[38;5;239;48;5;238m▄\e[38;5;145;48;5;249m▄\e[38;5;248;48;5;59m▄\e[38;5;241;48;5;0m▄\e[48;5;0m    \e[38;5;0;48;5;0m▄\e[38;5;8;48;5;8m▄\e[38;5;250;48;5;249m▄\e[38;5;0;48;5;0m▄\e[48;5;0m\n";
        desc += "\e[38;5;0;48;5;0m                                    \e[38;5;245;48;5;243m▄\e[38;5;246;48;5;243m▄\e[38;5;247;48;5;247m▄\e[38;5;250;48;5;251m▄\e[38;5;8;48;5;248m▄\e[38;5;243;48;5;0m▄\e[48;5;0m    \e[38;5;0;48;5;246m▄\e[38;5;252;48;5;251m▄\e[38;5;254;48;5;249m▄\e[38;5;232;48;5;0m▄\e[48;5;0m\n";
        desc += "\e[38;5;0;48;5;0m                                   \e[38;5;249;48;5;0m▄\e[38;5;250;48;5;249m▄\e[38;5;252;48;5;102m▄\e[38;5;7;48;5;250m▄\e[38;5;250;48;5;249m▄\e[38;5;249;48;5;243m▄\e[38;5;250;48;5;247m▄\e[38;5;249;48;5;0m▄\e[38;5;250;48;5;0m▄\e[38;5;249;48;5;0m▄\e[38;5;248;48;5;0m▄\e[38;5;245;48;5;0m▄\e[38;5;233;48;5;248m▄\e[38;5;254;48;5;253m▄\e[38;5;254;48;5;254m▄\e[38;5;145;48;5;0m▄\e[48;5;0m\n";
        desc += "\e[38;5;0;48;5;0m                                  \e[38;5;236;48;5;0m▄\e[38;5;247;48;5;249m▄\e[38;5;245;48;5;145m▄\e[38;5;245;48;5;245m▄\e[38;5;145;48;5;245m▄\e[38;5;246;48;5;248m▄\e[38;5;247;48;5;247m▄\e[38;5;245;48;5;250m▄\e[38;5;246;48;5;250m▄\e[38;5;249;48;5;188m▄\e[38;5;252;48;5;253m▄\e[38;5;145;48;5;188m▄\e[38;5;247;48;5;188m▄\e[38;5;246;48;5;188m▄\e[38;5;102;48;5;247m▄\e[38;5;240;48;5;242m▄\e[38;5;242;48;5;249m▄\e[48;5;0m\n";
        desc += "\e[38;5;0;48;5;0m                                 \e[38;5;0;48;5;0m▄\e[38;5;0;48;5;235m▄\e[38;5;0;48;5;252m▄\e[38;5;0;48;5;248m▄\e[38;5;0;48;5;254m▄\e[38;5;0;48;5;253m▄\e[38;5;0;48;5;254m▄▄\e[38;5;0;48;5;188m▄\e[38;5;0;48;5;252m▄▄\e[38;5;0;48;5;188m▄\e[38;5;0;48;5;250m▄\e[38;5;0;48;5;248m▄\e[38;5;0;48;5;247m▄\e[38;5;0;48;5;145m▄\e[38;5;0;48;5;246m▄\e[38;5;0;48;5;243m▄\e[38;5;0;48;5;0m▄\e[48;5;0m";
    }
    return desc;
}

void create () {
    ::create();
    set_id(({ "sculpture", "david", }));
    set_name("sculpture");
    set_short("a sculpture towering in a western alcove");
    set_long((: sculpture_long :));
    set_long_footer("A label says 'David' by Michelangelo. It appears to be a recreation of a sculpture from another era of time.");
    set_no_get(1);
}
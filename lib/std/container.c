inherit STD_OBJECT;

int can_receive (object ob) {
    return (member_array(ob, all_inventory(this_object())) == -1);
}
int can_release (object ob) {
    return (member_array(ob, all_inventory(this_object())) > -1);
}

int handle_receive_object () {
    return !(!previous_object());
}
int handle_release_object () {
    return !(!previous_object());
}

int inventory_visible () {
    return 1;
}
int inventory_accessible () {
    return 1;
}
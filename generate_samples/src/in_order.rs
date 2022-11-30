fn generate_one_set(size: u16) -> String {
    let mut ret = String::new();
    ret.push_str(&size.to_string());
    ret.push_str(" ");
    for i in 0..size {
        ret.push_str(&i.to_string());
        ret.push_str(" ");
    }
    ret
}

pub fn in_order(size: u16) -> String {
    let mut ret = String::new();
    for set_size in 1..size {
        ret.push_str(&generate_one_set(set_size));
        ret.push_str("\n");
    }
    ret
}
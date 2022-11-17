pub fn in_order(size: u16) -> String {
    let mut ret = String::new();
    for i in 0..size {
        ret.push_str(&i.to_string());
        ret.push_str("\n");
    }
    ret
}
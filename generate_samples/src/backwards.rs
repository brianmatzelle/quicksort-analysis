pub fn backwards(size: u16) -> String {
    let mut ret = String::new();
    for i in (0..size).rev() {
        ret.push_str(&i.to_string());
        ret.push_str("\n");
    }
    ret
}
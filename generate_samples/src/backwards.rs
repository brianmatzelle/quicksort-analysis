// pub fn backwards(size: u16) -> String {
//     let mut ret = String::new();
//     for i in (0..size).rev() {
//         ret.push_str(&i.to_string());
//         ret.push_str("\n");
//     }
//     ret
// }

fn generate_one_set(size: u16) -> String {
    let mut ret = String::new();
    ret.push_str(&size.to_string());
    ret.push_str(" ");
    for i in (0..size).rev() {
        ret.push_str(&i.to_string());
        ret.push_str(" ");
    }
    ret
}

pub fn backwards(size: u16) -> String {
    let mut ret = String::new();
    for set_size in (1..size) {
        // let mut generated_set: String = String::new();
        // generated_set.push_str(&generate_one_set(set_size));
        ret.push_str(&generate_one_set(set_size));
        ret.push_str("\n");
    }
    ret
}
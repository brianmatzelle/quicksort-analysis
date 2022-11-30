use rand::Rng;

fn generate_one_set(size: u16, lower_b: i32, upper_b: i32) -> String {
    let mut ret = String::new();
    ret.push_str(&size.to_string());
    ret.push_str(" ");
    for _i in 0..size {
        let num = rand::thread_rng().gen_range(lower_b..upper_b);
        ret.push_str(&num.to_string());
        ret.push_str(" ");
    }
    ret
}

pub fn random_ints(size: u16, lower_b: i32, upper_b: i32) -> String {
    let mut ret = String::new();
    for set_size in 1..size {
        // let mut generated_set: String = String::new();
        // generated_set.push_str(&generate_one_set(set_size, lower_b, upper_b));
        ret.push_str(&generate_one_set(set_size, lower_b, upper_b));
        ret.push_str("\n");
    }
    ret
}
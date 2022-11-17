use rand::Rng;

pub fn random_ints(size: u16, lower_b: i32, upper_b: i32) -> String {
    let mut ret = String::new();
    for _i in 0..size {
        let num = rand::thread_rng().gen_range(lower_b..upper_b);
        ret.push_str(&num.to_string());
        ret.push_str("\n");
    }
    ret
}
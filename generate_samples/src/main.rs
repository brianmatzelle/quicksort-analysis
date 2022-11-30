use std::fs::File;
use std::io::{Error, Write};
mod in_order;
use crate::in_order::in_order;
mod backwards;
use crate::backwards::backwards;
mod random_ints;
use crate::random_ints::random_ints;

fn main() -> Result<(), Error> {
    
    // configs
    const SET_SIZE: u16 = 1000;
    const RANDOM_LOWER_B: i32 = 0;
    const RANDOM_UPPER_B: i32 = 1000;


    // create in_order.txt
    write!(File::create("../samples/in_order.txt")?, "{}", in_order(SET_SIZE))?;

    // create backwards.txt
    write!(File::create("../samples/backwards.txt")?, "{}", backwards(SET_SIZE))?;

    // create random.txt
    write!(File::create("../samples/random_1k.txt")?, "{}", random_ints(SET_SIZE, RANDOM_LOWER_B, RANDOM_UPPER_B))?;

    // create random_10k.txt
    // write!(File::create("../samples/random_10k.txt")?, "{}", random_ints(SET_SIZE*10, RANDOM_LOWER_B, RANDOM_UPPER_B*10))?;

    // create random_with_neg.txt
    write!(File::create("../samples/random_1k_with_neg.txt")?, "{}", random_ints(SET_SIZE, RANDOM_LOWER_B-RANDOM_UPPER_B, RANDOM_UPPER_B))

    // create random_10k_with_neg.txt
    // write!(File::create("../samples/random_10k_with_neg.txt")?, "{}", random_ints(SET_SIZE*10, (RANDOM_LOWER_B-RANDOM_UPPER_B)*10, RANDOM_UPPER_B*10))
}

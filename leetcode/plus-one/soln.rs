pub fn plus_one(mut digits: Vec<i32>) -> Vec<i32> {
    let mut c = 0i32;
    let mut rd = 0i32;
    let mut idx: usize = digits.len() - 1;
    rd = digits[idx] + 1;
    loop{
        digits[idx] = rd % 10;
        c = rd / 10;
        if idx == 0{
            break;
        }
        idx -= 1;
        rd = c + digits[idx];
    };

    if c > 0{
        digits.insert(0usize, c);
    }
    digits
}

fn main(){
    let v: Vec<i32> = vec![9i32,9];
    println!("{:?}", plus_one(v));
}

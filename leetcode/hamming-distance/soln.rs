
pub fn hamming_distance(x: i32, y: i32) -> i32{
    let mut z = x^y;
    let mut cnt: i32 = 0;
    while z > 0{
        if z&1 == 1{
            cnt += 1;
        }
        z >>= 1;
    }
    cnt
}

fn main(){
    println!("{}", hamming_distance(1, 4));
}



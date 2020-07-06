
pub fn reverse(mut x: i32) -> i32 {
    let mut y: i64 = x as i64;
    let neg = if y < 0{
        y *= -1;
        true
    } else {false};

    let mut s = y.to_string();
    s = s.chars().rev().collect::<String>();
    y = s.parse::<i64>().unwrap();
    if neg{
        y = y * -1;
    }

    if y < i32::MIN.into() || y > i32::MAX.into(){
        return 0;
    }

    y as i32
}

fn main(){
    println!("{}", reverse(-123));
}


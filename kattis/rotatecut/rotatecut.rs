
fn get_input() -> String {
    let mut buffer = String::new();
    std::io::stdin().read_line(&mut buffer).expect("Failed");
    buffer
}


fn main(){
    let mut t = get_input().trim().parse::<i32>().unwrap();
    loop {
        if t == 0 { break; }
        solve();
        t -= 1;
    }
}

fn solve(){
    let mut buffer = String::new();
    std::io::stdin().read_line(&mut buffer).unwrap();
    let vec = buffer.split_whitespace().collect::<Vec<&str>>();
    let n: usize = vec[0].parse().unwrap();
    let mut s = vec[1];
    let mut a: usize = 0;
    let mut b = s.len() - 1;

    if n&1 == 1 {
        // remove the first x characters
        a = n/4;
    }
    else{
        b -= n/4;
    }

    println!("{:?}", s.chars().by_ref().skip(a));

}


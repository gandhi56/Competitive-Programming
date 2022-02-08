use std::collections::HashSet;

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
    let stdin = std::io::stdin();
    let mut a = HashSet::new();
    let mut n = get_input().trim().parse::<i32>().unwrap();
    loop {
        if n == 0 {break;}
        let mut buffer = String::new();
        stdin.read_line(&mut buffer).unwrap();
        a.insert(buffer.clone());
        n -= 1;
    }
    println!("{}", a.len());
}

use std::{io::*, str::*};
fn cin() -> String {
	let mut s = "".into(); stdin().read_to_string(&mut s); 
	s 
}

fn next<T: FromStr>(s: &mut SplitWhitespace) -> Option<T>
where
    <T as FromStr>::Err: std::fmt::Debug
{
    match s.next() {
        Some(s) => Some(s.parse().unwrap()),
        None => None,
    }
    // Even shorter version
    // s.next().map(|s| s.parse().unwrap())
}

fn getline()-> String{
	let mut s = String::new();
	std::io::stdin().read_line(&mut s);
	s
}

fn main() {
	let sc = cin(); 
	let cin = &mut sc.split_whitespace();

	let n: i32 = next(cin).unwrap_or_default();
	let path: String = next(cin).unwrap_or_default();

	let x: u64 = (1<<(n+1));
	let mut i: usize = x as usize;
	let mut ans = 1u64;
	for c in path.chars(){
		ans <<= 1;
		if c == 'R'{
			ans += 1;
		}
	}
	println!("{}", x - ans);

}

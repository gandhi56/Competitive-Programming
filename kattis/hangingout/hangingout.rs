use std::{io::*, str::*};
fn cin() -> String {
	let mut s = "".into(); stdin().read_to_string(&mut s); 
	s 
}

fn next<T: FromStr>(s: &mut SplitWhitespace) -> T where <T as FromStr>::Err: std::fmt::Debug {
	s.next().unwrap().parse().unwrap() 
}

fn getline()-> String{
	let mut s = String::new();
	std::io::stdin().read_line(&mut s);
	s
}

fn main() {
	let sc = cin(); 
	let cin = &mut sc.split_whitespace();

	let L: i32 = next(cin);
	let x: i32 = next(cin);

	let mut l = 0;
	let mut ans = 0;
	for i in 0..x{
		let q: String = next(cin);
		let c: i32 = next(cin);
		if q == String::from("enter")	{
			l += c;
		} 
		else {
			l -= c;
		}
		if l > L{
			ans += 1;
			l -= c;
		}
	}
	println!("{}", ans);

}

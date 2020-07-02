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

fn value(c: char, dom: bool) -> i32{
	if dom{
		if c == 'A'	{	return 11	};
		if c == 'K' {	return 4	};
		if c == 'Q'	{	return 3	};
		if c == 'J' {	return 20	};
		if c == 'T'	{	return 10	};
		if c == '9' {	return 14	};
		if c == '8'	{	return 0	};
		if c == '7' {	return 0	};
	}
	if c == 'A'	{	return 11	};
	if c == 'K' {	return 4	};
	if c == 'Q'	{	return 3	};
	if c == 'J' {	return 2	};
	if c == 'T'	{	return 10	};
	if c == '9' {	return 0	};
	if c == '8'	{	return 0	};
	if c == '7' {	return 0	};
	0
}

fn main() {
	let s = cin(); 
	let cin = &mut s.split_whitespace();

	let N: i16 = next(cin);
	let B: char = next(cin);

	let mut ans: i32 = 0;

	let mut cards: Vec<String> = Vec::new();
	for i in 0..(4*N){
		let c : String = next(cin);
		cards.push(c);
	}

	for card in cards.iter(){
		let num = card.chars().nth(0).unwrap();
		let suit = card.chars().nth(1).unwrap();
		ans += value(num, suit==B);
	}

	println!("{}", ans);

}
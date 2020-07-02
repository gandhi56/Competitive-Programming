use std::{io::*, str::*};
fn cin() -> String {
	let mut s = "".into(); stdin().read_to_string(&mut s); 
	s 
}

fn next<T: FromStr>(s: &mut SplitWhitespace) -> T where <T as FromStr>::Err: std::fmt::Debug {
	s.next().unwrap().parse().unwrap() 
}

fn main() {
	// let s = cin(); 
	// let cin = &mut s.split_whitespace();
	let mut rev: Vec<char> = Vec::new();
	rev.push('0');
	rev.push('1');
	rev.push('2');
	rev.push('#');
	rev.push('#');
	rev.push('5');
	rev.push('9');
	rev.push('#');
	rev.push('8');
	rev.push('6');

	let mut ans: Vec<String> = Vec::new();

	let MAXN: u32 = 100;
	for x in 10..MAXN{
		let mut ok = true;
		let xs = x.to_string();
		for d in xs.chars(){
			let idx = (d as u32) - ('0' as u32);
			if rev[idx as usize] == '#'{
				ok = false;
				println!("{:?} is NOT ok", xs);
				break;
			}
		}
		let mut revs = String::new();
		let mut i = xs.len() - 1;
		println!("{:?} is ok", xs);
		loop{
			let d = xs.chars().nth(i).unwrap();
			println!("d = {:?}", d);
			let idx = (d as u32) - ('0' as u32);
			revs.push(rev[idx as usize]);
			i -= 1;
			if i <= 0{
				break;
			}
		}
		rev.push(revs);
	}

	for num in rev{
		println!("{:?}", num);
	}


}
use std::{io::*, str::*};
use std::collections::HashMap;

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
	let s = cin(); 
	let cin = &mut s.split_whitespace();

	let n: u32 = next(cin);
	let t: u8 = next(cin);
	
	let mut a: Vec<u32> = Vec::new();
	let mut cnt: HashMap<u32, u32> = HashMap::new();

	for _i in 0..n{
		let x = next(cin);
		a.push(x);
		*cnt.entry(x).or_insert(0) += 1;
	}

	a.sort();

	if t == 1{
		let mut done = false;
		for i in 0..a.len(){
			if cnt.contains_key(&(7777-a[i])){
				println!("Yes");
				done = true;
				break;
			}
		}
		if !done{
			println!("No");
		}
	}

	else if t == 2{
		let mut ans = String::from("Unique");
		for (_k,v) in cnt.iter(){
			if *v > 1 {
				ans = String::from("Contains duplicate");
				break;
			}
		}
		println!("{}", ans);
	}

	else if t == 3{
		let mut ans: i32 = -1;
		for (k,v) in cnt.iter(){
			if *v > (n/2){
				ans = *k as i32;
				break;
			}
		}
		println!("{}", ans);
	}

	else if t == 4{
		let idx = n/2;
		if n%2 == 0{
			println!("{:?} {:?}", a[(idx-1) as usize], a[idx as usize]);
		}
		else{
			println!("{:?}", a[idx as usize]);
		}
	}

	else if t == 5{
		for i in 0..a.len(){
			if a[i] >= 100 && a[i] <= 999{
				print!("{} ", a[i]);
			}
		}
		println!();
	}

}















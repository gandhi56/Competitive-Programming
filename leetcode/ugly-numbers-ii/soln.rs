
use std::cmp::min;
use std::collections::HashSet;

pub fn solve(mut n: i32) -> i32 {
	let mut v: HashSet<i32> = HashSet::new();
	v.insert(1);
	let mut idx: usize = 0;
	loop{

		let mut y = i32::MAX;
		for x in v.iter(){
			let mut a = x*2;
			let mut b = x*3;
			let mut c = x*5;
			if !v.contains(&a){
				y = min(y, a);
			}
			if !v.contains(&b){
				y = min(y, b);
			}
			if !v.contains(&c){
				y = min(y, c);
			}
		}
		v.insert(y);
		println!("{:?}", v);

		if v.len() >= 20{
				break;
		}
	};
	// v.sort();
	// v[(n-1) as usize]
	n
}


fn main(){
    println!("{}", solve(10));
}

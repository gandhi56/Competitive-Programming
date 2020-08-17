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

fn solve(s: i32, t: i32, n: i32, d: Vec<i32>, b: Vec<i32>, c: Vec<i32>){
	let mut currTime : i32 = s;
	let mut i: usize = 0;
	while i < (n as usize){
		// walk for d_i time
		currTime += d[i];
		// println!("walk {}", currTime);

		// wait until bus arrives
		if currTime % c[i] > 0{
			let y = currTime % c[i];
			let xx = (currTime - y) / c[i];
			currTime += ((xx+1)*c[i]) - currTime;
			// println!("wait {}", currTime);
		}

		// ride the bus
		currTime += b[i];
		// println!("ride {}\n", currTime);

		i += 1;
	}

	// walk to class
	currTime += d[n as usize];
	if currTime > t{
		println!("no");
	}
	else{
		println!("yes");
	}
}

/*

0 20 2
2 2 2
5 5
3 5

walk 2, reaches bus stop
ride 5
walk 2 reaches bus stop at 9min
wait until bus arrives... 0mins
ride 5
walk 2

(x-1)*c + y = curr
x-1 = (curr - y) / c
*/


fn main() {
	let sc = cin(); 
	let cin = &mut sc.split_whitespace();

	// let N: i16 = next(cin);
	// let B: char = next(cin);

	// let mut ans: i32 = 0;

	// let mut cards: Vec<String> = Vec::new();
	// for i in 0..(4*N){
	// 	let c : String = next(cin);
	// 	cards.push(c);
	// }

	let s: i32 = next(cin);
	let t: i32 = next(cin);
	let n: i32 = next(cin);

	let mut d: Vec<i32> = Vec::new();
	for i in 0..(n+1){
		let dd : i32 = next(cin);
		d.push(dd);
	}

	let mut b: Vec<i32> = Vec::new();
	for i in 0..n{
		let bb: i32 = next(cin);
		b.push(bb);
	}

	let mut c: Vec<i32> = Vec::new();
	for i in 0..n{
		let cc: i32 = next(cin);
		c.push(cc);
	}

	solve(s, t, n, d, b, c);

}








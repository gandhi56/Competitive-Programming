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

	let n: usize = next(cin);
	let mut m = vec![vec![0; n]; n];
	for i in 0..n{
		for j in 0..n{
			m[i][j] = next(cin);
		}
	}

	let mut a = vec![0; n];
	for i in 0..n{
		for j in 0..n{
			a[i] |= m[i][j];
		}
	}

	for x in a.iter(){
		print!("{} ", x);
	}

}


/*
a[0] & a[1] = 0
a[0] & a[2] = 1 ==> ...1 & ...1
a[0] & a[3] = 1
a[0] & a[4] = 1

a[1] & a[2] = 2
a[1] & a[3] = 0
a[1] & a[4] = 2

a[2] & a[3] = 1
a[2] & a[4] = 3

a[3] & a[4] = 1

a = [1, 2, 3, 1, 7]

0 0 1 1 1
0 0 2 0 2
1 2 0 1 3
1 0 1 0 1
1 2 3 1 0



*/
















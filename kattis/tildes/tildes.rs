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

fn initUF(n: usize) -> Vec<i32>{
	let mut uf = vec![0i32; n];
	for i in 0..n{
		uf[i] = i as i32;
	}
	uf
}

fn find(uf: &mut Vec<i32>, i: usize) -> i32 {
	if (i as i32) == uf[i]{
		return (i as i32);
	}
	uf[i] = find(uf, uf[i] as usize);
	uf[i]
}

fn union(uf: &mut Vec<i32>, rk: &mut Vec<i32>, i: usize, j: usize) -> bool {
	let ii = find(uf, i);
	let jj = find(uf, j);
	if ii == jj{
		return false;
	}
	uf[ii as usize] = jj;
	rk[jj as usize] += rk[ii as usize];
	// println!("merged {}({}) and {}({})", i, rk[ii as usize], j, rk[jj as usize]);
	true
}

fn main() {
	let sc = cin(); 
	let cin = &mut sc.split_whitespace();

	let n: i32 = next(cin).unwrap_or_default();
	let q: i32 = next(cin).unwrap_or_default();

	let mut uf = initUF((n+1) as usize);
	let mut rk = vec![1i32; (n+1) as usize];
	for t in 0..q{
		let c: char = next(cin).unwrap_or_default();
		if c == 't'{
			let a: i32 = next(cin).unwrap_or_default();
			let b: i32 = next(cin).unwrap_or_default();
			union(&mut uf, &mut rk, a as usize, b as usize);
		}
		else if c == 's'{
			let a: i32 = next(cin).unwrap_or_default();
			println!("{}", rk[find(&mut uf, a as usize) as usize]);
		}

	}
}

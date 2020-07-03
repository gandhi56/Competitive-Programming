
use std::collections::HashSet;
use std::cmp::max;

fn solve(s: String) -> i32 {
	let bytes = s.as_bytes();
	if (bytes.len() == 0){
		return 0;
	}
	let mut ans: usize = 1;
	let mut i: usize = 0;
	let mut j: usize = 0;
	let mut seen: HashSet<u8> = HashSet::new();
	while i < bytes.len() && j < bytes.len(){
		if seen.contains(&bytes[j]){
			seen.remove(&bytes[i]);
			i += 1;
		}
		else{
			seen.insert(bytes[j]);
			ans = max(ans, seen.len());
			j += 1;
		}
	}
	ans as i32
}


fn main(){
	// let ans = solve(String::from("abcass"));
	// let ans = solve(String::from("bbbbb"));
	// let ans = solve(String::from("abbcabc"));
	// let ans = solve(String::from("pwwkew"));
	let ans = solve(String::from("auc"));
	println!("{}", ans);
}
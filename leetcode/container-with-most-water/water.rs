use std::cmp::max;

pub fn max_area(height: Vec<i32>) -> i32 {
	let mut ans = 0i32;
	for i in 0..height.len(){
		for j in i+1..height.len(){
			if height[i] == height[j]{
				ans = max(ans, height * (j-1));
			}
		}
	}
	ans
}

fn main(){
	println!("{}", abs(20-3));
}
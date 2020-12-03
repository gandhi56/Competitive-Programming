pub fn is_palindrome(x: i32) -> bool {
	if x < 0{
		return false;
	}
	let s = x.to_string();
	s == s.chars().rev().collect::<String>()
}

fn main(){
	println!("{}", is_palindrome(-12321));
}
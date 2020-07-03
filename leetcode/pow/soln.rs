pub fn my_pow(x: f64, y: i32) -> f64 {
	if y == 0{
		return 1.0;
	}
	let z = my_pow(x, y/2);
	if y%2 == 0{
		return z*z;
	}
	else{
		if y > 0{
			return x * z * z;
		}
		else{
			return (z*z)/x;
		}
	}
}

fn main(){
	println!("{:?}", my_pow(100.00000, -400000000 as i32));
}
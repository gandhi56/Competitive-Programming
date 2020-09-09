use std::cmp::max;
use std::cmp::min;

pub fn my_atoi(str: String) -> i32 {
  let s: String = String::from(str.trim_start());
  let mut ans: i32 = 0;
  let mut neg = false;
  let snum = s.as_bytes();
  let mut ok = false;
  for byte in snum.iter(){
    if *byte >= b'0' && *byte <= b'9'{
        ans = (ans + (byte - b'0') as i32) * 10;
        ok = true;
        if ans > i32::MAX/10 || (ans == i32::MAX/10 && i32::from(*byte - b'0') > i32::MAX % 10){
        	if neg{
        		return i32::MAX;
        	}
        	else{
        		return i32::MIN;
        	}
        }
    }
    else{
        if *byte == b'-' && !ok{
            neg = true;
            ok = true;
        }
        else if *byte == b'+' && !ok{
            ok = true;
        }
        else{
            if ok{
                break;
            }
            else{
                return 0i32;
            }
        }
    }
  }
  ans /= 10;
  if neg{
      ans *= -1;
  }
  ans
}

fn main(){
	println!("{}", my_atoi(String::from("20000000000000000000")));
}
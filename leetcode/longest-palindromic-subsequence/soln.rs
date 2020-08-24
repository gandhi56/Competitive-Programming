use std::cmp::max;

pub fn longest_palindrome_subseq(s: String) -> i32 {
	println!("FOO");
  let bytes = s.as_bytes();
  println!("FOO");
  const N: usize = 2000;
  let n = bytes.len();
  let mut dp = [[0i32; N]; N];
  println!("FOO");
  for i in 0..n{
  	dp[i][i] = 1;
  }

  for i in (0..n).rev(){
  	for j in i+1..n{
  		println!("{} {}", i, j);
  		if i+1 >= n || j < 1{
  			continue;
  		}
  		if bytes[i] == bytes[j]{
  			dp[i][j] = dp[i+1][j-1] + 2;
  		}
  		else{
  			dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
  		}
  	}
  }
  dp[0][n-1]
}

fn main(){
	println!("FOO");
	let s: String = String::from("bbbab");
	let ans = longest_palindrome_subseq(s);
	println!("{:?}", ans);
}
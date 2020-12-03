pub fn product_except_self(nums: Vec<i32>) -> Vec<i32> {
  let mut l = vec![0; nums.len()];
  let mut r = vec![0; nums.len()];
  l[0] = 1;
  for i in 1..nums.len(){
    l[i] = l[i-1] * nums[i-1];
  }
  
  r[nums.len()-1] = 1;
  for i in (0..nums.len()-1).rev(){
    r[i] = r[i+1] * nums[i+1];
  }
  
  let mut ans = vec![0; nums.len()];
  for i in 0..nums.len(){
    ans[i] = l[i] * r[i];
  }
  ans
}

fn main(){
  let v: Vec<i32> = [1,2,3,4].to_vec();
  println!("{:?}", product_except_self(v));
}

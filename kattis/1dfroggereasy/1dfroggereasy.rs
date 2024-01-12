
#![allow(warnings)]
use std::cmp::{min,max};
use std::io::{BufWriter, stdin, stdout, Write};
const BITS: usize = 19;

#[derive(Default)]
struct Scanner {
  buffer: Vec<String>
}
impl Scanner {
  fn next<T: std::str::FromStr>(&mut self) -> T {
    loop {
      if let Some(token) = self.buffer.pop() {
        return token.parse().ok().expect("Failed parse");
      }
      let mut input = String::new();
      stdin().read_line(&mut input).expect("Failed read");
      self.buffer = input.split_whitespace().rev().map(String::from).collect();
    }
  }
}

fn main() {
  let mut scan = Scanner::default();
  let out = &mut BufWriter::new(stdout());

  let n = scan.next::<usize>();
  let s = scan.next::<usize>();
  let m = scan.next::<i32>();

  let mut a = vec![0];
  for i in 0..n {
    let x = scan.next::<i32>();
    a.push(x);
  }
  let mut seen = vec![false;(n+1)];
  let mut i = s;
  let mut count = 0;
  // println!("{:?}", a);

  loop {
    // println!("i = {} {:?}", i, seen);
    // check bounds
    if i < 1 {
      println!("left\n{}", count);
      break;
    }
    else if i > n {
      println!("right\n{}", count);
      break;
    }
    else if seen[i] == true {
      println!("cycle\n{}", count);
      break;
    }
    else if a[i] == m {
      println!("magic\n{}", count);
      break;
    }
    
    // mark i as visited
    seen[i] = true;
    
    // update i
    let mut idx = i as i32;
    if a[i] > 0 {
      idx += a[i];
    }
    else if a[i] < 0 {
      idx -= a[i].abs();
    }
    count += 1;
    
    if idx >= 0 {
      i = idx as usize;
    }
    else {
      println!("left\n{}", count);
      break;
    }
  }

}

use std::{io::*, str::*};
use std::cmp::min;

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

#[derive(Debug, PartialEq, PartialOrd)]
struct Point{
	x: f64, 
	y: f64
}

impl Point{
	pub fn new(x: f64, y: f64) -> Self{
		Point{x, y}
	}
	pub fn angle(&self) -> f64{
		self.y.atan2(self.x)
	}
	pub fn dot(&self, p: Point) -> f64{
		self.x * p.x + self.y * p.y
	}
}

struct Line{
	p: Point,
	theta: f64
}
impl Line{
	pub fn new(p: Point, theta: f64) -> Self{
		Line{p, theta }
	}
}

fn dist(i: &Point, j: &Point) -> f64{
	let dx = i.x - j.x;
	let dy = i.y - j.y;
	(dx*dx + dy*dy).sqrt()
}

fn main() {
	let sc = cin(); 
	let cin = &mut sc.split_whitespace();
	let N = next(cin).unwrap_or_default();
	for test in 0..N{
		let n: usize = next(cin).unwrap_or_default();
		let d: f64 = next(cin).unwrap_or_default();

		let mut pts: Vec<Point> = Vec::new();
		for t in 0..n{
			let x: f64 = next(cin).unwrap_or_default();
			let y: f64 = next(cin).unwrap_or_default();
			pts.push(Point{x, y});
		}
		
		// sort points in ccw order
		pts.sort_by(|a, b| a.angle().partial_cmp(&b.angle()).unwrap());
	
		let mut ans: i32 = 500;

		for st in 0..n{
			let mut marked = vec![false; n];
			let mut cnt: i32 = 0;
			// println!("{}", st);
			for i in 0..n{
				let idx = ((st + i) % n) as usize;
				if marked[idx]{
					continue;
				}
				let mut nxt: usize = idx;
				while nxt != st{
					if dist(&pts[nxt], &pts[idx]) <= 2f64 * d{
						marked[nxt] = true;
					}
					else{
						break;
					}
					nxt = (nxt + 1) % n;
				}
				cnt += 1;
			}
			ans = min(ans, cnt);
		}

		println!("{}", ans);

	}
}

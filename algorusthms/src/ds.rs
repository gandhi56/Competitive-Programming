
/// Fenwick tree ===============================================
/*
	Usage:

	let n: usize = 20;
	let mut tree = ds::FenwickTree::new(n, 0);
	tree.add(1, 2);
	tree.add(0, 1);
	tree.add(2, 4);
	tree.add(0, 2);
	println!("{}", tree.sum(5));
*/

pub struct FenwickTree{
	pub bit: Vec<i32>,
	pub n: usize,
}

impl FenwickTree{
	pub fn new(n: usize, val: i32) -> FenwickTree{
		FenwickTree{
			bit: vec![val;n],
			n: n,
		}
	}

	pub fn sum(&self, mut r: usize) -> i32{
		let mut ret: i32 = 0;
		while r&(r+1) > 0 {
			ret += self.bit[r];
			r = (r & (r + 1)) - 1 ;
		}
		ret
	}

	pub fn add(&mut self, mut idx: usize, delta: i32){
		while idx < self.n{
			self.bit[idx] += delta;
			idx = idx | (idx + 1);
		}
	}
}

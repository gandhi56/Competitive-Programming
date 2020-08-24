
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

	pub fn sum(&self, r: &mut usize) -> i32{
		let mut ret: i32 = 0;
		while r >= &mut 0{
			ret += self.bit[*r];
			// FIXME
			*r = ((*r) & ((*r) + 1)) - 1;
		}
		ret
	}

	pub fn add(&mut self, idx: &mut usize, delta: i32){
		while idx < &mut self.n{
			self.bit[*idx] += delta;
			*idx = *idx | (*idx + 1);
		}
	}

}
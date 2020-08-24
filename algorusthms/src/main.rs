mod ds;

fn main() {
	let n: usize = 20;
	let mut tree = ds::FenwickTree::new(n, 0);
	println!("{:?}", tree.bit);
	tree.add(&mut 1, 2);
	tree.add(&mut 0, 1);
	println!("{:?}", tree.bit);
	println!("{:?}", tree.sum(&mut 5));
}

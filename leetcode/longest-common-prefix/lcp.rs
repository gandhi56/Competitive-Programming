use std::ptr;

#[derive(Debug, Default)]
struct TrieNode<'a>{
	chars: Vec<&'a TrieNode<'a>>,
}

impl TrieNode<'_>{
	fn new() -> TrieNode<'static>{
		TrieNode{
			chars: vec![&TrieNode<'_>;26]
		}
	}

	fn add_string(&self, str: String){
		
	}

}

fn main(){
	let mut root = TrieNode::new();
	root.add_string(String::from("foobar"));
	println!("len of trie = {}", root.chars.len());

}

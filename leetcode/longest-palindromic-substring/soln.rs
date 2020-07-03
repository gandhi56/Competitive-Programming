use std::cmp::max;

pub fn longest_palindrome(s: String) -> String {
	if s.len() == 0{
		return String::from("");
	}
	let mut memo = vec![vec![0; s.len()+1]; s.len()+1];
	let mut ans: usize = 1;

	let a = s.as_bytes();

	for i in 0..s.len(){
		memo[i][i] = 1;
		if i < s.len()-1{
			let x = a[i];
			let y = a[i+1];
			if x == y {
				memo[i][i+1] = 1;
				memo[i+1][i] = 1;
				ans = 2;
			}
		}
	}

	for i in (0..s.len()).rev(){
		for j in i..s.len(){
			if i == j{
				memo[i][i] = 1;
			}
			if i < s.len()-1 && j >= 1 && memo[i+1][j-1] == 1 {
				let x = a[i];
				let y = a[j];
				if x == y{
					memo[i][j] = 1;
					memo[j][i] = 1;
					ans = max(ans, j-i+1);
				}
			}
		}
	}

	for i in (0..s.len()).rev(){
		for j in i..s.len(){
			let len:usize = j-i+1;
			if len == ans && memo[i][j] == 1{
				return String::from(&s[i..j+1]);
			}
		}
	}
	String::new()
}

fn main(){
	// let ans = solve("babad".to_string());
	let s = String::from("rgczcpratwyqxaszbuwwcadruayhasynuxnakpmsyhxzlnxmdtsqqlmwnbxvmgvllafrpmlfuqpbhjddmhmbcgmlyeypkfpreddyencsdmgxysctpubvgeedhurvizgqxclhpfrvxggrowaynrtuwvvvwnqlowdihtrdzjffrgoeqivnprdnpvfjuhycpfydjcpfcnkpyujljiesmuxhtizzvwhvpqylvcirwqsmpptyhcqybstsfgjadicwzycswwmpluvzqdvnhkcofptqrzgjqtbvbdxylrylinspncrkxclykccbwridpqckstxdjawvziucrswpsfmisqiozworibeycuarcidbljslwbalcemgymnsxfziattdylrulwrybzztoxhevsdnvvljfzzrgcmagshucoalfiuapgzpqgjjgqsmcvtdsvehewrvtkeqwgmatqdpwlayjcxcavjmgpdyklrjcqvxjqbjucfubgmgpkfdxznkhcejscymuildfnuxwmuklntnyycdcscioimenaeohgpbcpogyifcsatfxeslstkjclauqmywacizyapxlgtcchlxkvygzeucwalhvhbwkvbceqajstxzzppcxoanhyfkgwaelsfdeeviqogjpresnoacegfeejyychabkhszcokdxpaqrprwfdahjqkfptwpeykgumyemgkccynxuvbdpjlrbgqtcqulxodurugofuwzudnhgxdrbbxtrvdnlodyhsifvyspejenpdckevzqrexplpcqtwtxlimfrsjumiygqeemhihcxyngsemcolrnlyhqlbqbcestadoxtrdvcgucntjnfavylip");

	let x = String::from("abddadd");

	let z = String::from("ddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd");
	let test1 = String::from("cbbd");
	println!("{:?}", longest_palindrome(test1));
}
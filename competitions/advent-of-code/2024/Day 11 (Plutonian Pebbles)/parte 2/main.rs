use std::env;
use std::fs;
use std::collections::{HashMap};

fn get_len(n: u64) -> u32 {
	n.checked_ilog10().unwrap_or(0) + 1
}

fn dp(memo: &mut HashMap<(u64, u64), u64>, n: u64, i: u64) -> u64 {
	if memo.contains_key(&(n, i)) {
		return memo[&(n, i)];
	}
	if i == 0 {
		return 1
	}

	if n == 0 {
		let dp1 = dp(memo, 1, i - 1);
		memo.insert((n, i), dp1);
	}
	else if get_len(n) % 2 == 0 {
		let med = (get_len(n) / 2) as usize;
		let ns = n.to_string();
		let dp1 = dp(memo, ns[..med].parse::<u64>().unwrap(), i - 1);
		let dp2 = dp(memo, ns[med..].parse::<u64>().unwrap(), i - 1);
		memo.insert((n, i), dp1 + dp2);
	}
	else {
		let dp1 = dp(memo, n * 2024, i - 1);
		memo.insert((n, i), dp1);
	}

	memo[&(n, i)]
}

fn main() {
	let args = env::args().collect::<Vec<String>>();
	let input = &args[1];

	let mut content = fs::read_to_string(input).unwrap();
	content = content.trim().to_string();

	let list = content.split(" ").map(|s| s.parse::<u64>().unwrap()).collect::<Vec<u64>>();
	let mut memo = HashMap::<(u64, u64), u64>::new();

	let mut count = 0;
	for l in &list {
		count += dp(&mut memo, *l, 75);
	}

	println!("{}", count);
}

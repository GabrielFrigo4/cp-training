use std::env;
use std::fs;

fn get_len(n: u64) -> u32 {
	n.checked_ilog10().unwrap_or(0) + 1
}

fn main() {
	let args = env::args().collect::<Vec<String>>();
	let input = &args[1];

	let mut content = fs::read_to_string(input).unwrap();
	content = content.trim().to_string();

	let mut list = content.split(" ").map(|s| s.parse::<u64>().unwrap()).collect::<Vec<u64>>();
	let mut nlist = Vec::<u64>::new();

	for _ in 0..25 {
		for l in list {
			if l == 0 {
				nlist.push(1);
			}
			else if get_len(l) % 2 == 0 {
				let med = (get_len(l) / 2) as usize;
				let ns = l.to_string();
				nlist.push(ns[..med].parse::<u64>().unwrap());
				nlist.push(ns[med..].parse::<u64>().unwrap());
			}
			else {
				nlist.push(l * 2024);
			}
		}

		list = nlist.clone();
		nlist.clear();
	}

	println!("{}", list.len());
}

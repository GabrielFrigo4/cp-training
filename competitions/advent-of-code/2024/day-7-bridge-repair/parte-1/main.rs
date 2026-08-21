use std::env;
use std::fs::File;
use std::io::{BufRead, BufReader};

fn main() {
	let args = env::args().collect::<Vec<String>>();
	let input = &args[1];

	let file = File::open(input).unwrap();
	let reader = BufReader::new(file);

	let mut sum = 0;
	for line in reader.lines() {
		let line = line.unwrap();
		let parts1 = line.split(": ").collect::<Vec<&str>>();

		let num = parts1[0].parse::<u64>().unwrap();
		let nums = parts1[1].split(" ").map(|x| x.parse::<u64>().unwrap()).collect::<Vec<u64>>();

		for comb in 0..(1 << (nums.len() - 1)) {
			let mut equation = 0;
			for (i, n) in nums.clone().into_iter().enumerate() {
				if i == 0 {
					equation = n;
					continue;
				}
				match (comb >> (i - 1)) & 1 {
					0 => equation *= n,
					1 => equation += n,
					_ => ()
				}
			}
			if num == equation {
				sum += equation;
				break;
			}
		}
	}
	println!("{}", sum);
}

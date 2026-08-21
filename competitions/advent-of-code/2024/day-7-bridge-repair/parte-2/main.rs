use std::env;
use std::fs::File;
use std::io::{BufRead, BufReader};

fn new_poss(poss: &mut Vec<u8>) -> bool {
	for ref mut p in poss {
		**p += 1;
		if **p == 3 {
			**p = 0;
		}
		else {
			return true;
		}
	}
	return false;
}

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

		let mut comb = vec![0; nums.len() - 1];
		loop {
			let mut equation = 0;
			for (i, n) in nums.clone().into_iter().enumerate() {
				if i == 0 {
					equation = n;
					continue;
				}
				match comb[i - 1] {
					0 => equation *= n,
					1 => equation += n,
					2 => equation = format!("{equation}{n}").parse::<u64>().unwrap(),
					_ => ()
				}
			}
			if num == equation {
				sum += equation;
				break;
			}

			if !new_poss(&mut comb) {
				break;
			}
		}
	}
	println!("{}", sum);
}

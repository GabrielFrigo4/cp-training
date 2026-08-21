use std::env;
use std::fs::File;
use std::io::{BufRead, BufReader};
use regex::Regex;

fn main() {
	let args = env::args().collect::<Vec<String>>();
	let input = &args[1];

	let file = File::open(input).unwrap();
	let reader = BufReader::new(file);

	let mut sum = 0;
	let mut button_a = (0, 0);
	let mut button_b = (0, 0);
	let mut prize: (i64, i64);
	for (i, line) in reader.lines().enumerate() {
		let line = line.unwrap();
		match i % 4 {
			0 => {
				let re = Regex::new(r"Button A: X\+(\d+), Y\+(\d+)").unwrap();
				let (_, [n1, n2]) = re.captures(&line).unwrap().extract();
				button_a = (n1.parse::<i64>().unwrap(), n2.parse::<i64>().unwrap());
			},
			1 => {
				let re = Regex::new(r"Button B: X\+(\d+), Y\+(\d+)").unwrap();
				let (_, [n1, n2]) = re.captures(&line).unwrap().extract();
				button_b = (n1.parse::<i64>().unwrap(), n2.parse::<i64>().unwrap());
			},
			2 => {
				let re = Regex::new(r"Prize: X=(\d+), Y=(\d+)").unwrap();
				let (_, [n1, n2]) = re.captures(&line).unwrap().extract();
				prize = (n1.parse::<i64>().unwrap(), n2.parse::<i64>().unwrap());

				let mut count_a = 0;

				let mut mod0 = prize.0 % button_b.0 == 0;
				let mut mod1 = prize.1 % button_b.1 == 0;
				let mut div = prize.0 / button_b.0 == prize.1 / button_b.1;
				let mut ge = prize.0 >= 0 && prize.1 >= 0;
				while !(mod0 && mod1 && div) && ge {
					prize.0 -= button_a.0;
					prize.1 -= button_a.1;
					count_a += 1;

					mod0 = prize.0 % button_b.0 == 0;
					mod1 = prize.1 % button_b.1 == 0;
					div = prize.0 / button_b.0 == prize.1 / button_b.1;
					ge = prize.0 >= 0 && prize.1 >= 0;
				}

				if ge {
					let count_b = prize.0 / button_b.0;
					sum += count_a * 3 + count_b;
				}
			},
			_ => (),
		}
	}

	println!("{}", sum);
}

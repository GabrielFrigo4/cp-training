use std::env;
use std::cmp;
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
				prize.0 += 10000000000000;
				prize.1 += 10000000000000;

				let tg_a = (button_a.1 as f64) / (button_a.0 as f64);
				let tg_b = (button_b.1 as f64) / (button_b.0 as f64);
				let k = tg_a / tg_b;

				let min = cmp::min(prize.0 / button_b.0, prize.1 / button_b.1);
				let b_x = (prize.0 - min * button_b.0) as f64;
				let b_y = (prize.1 - min * button_b.1) as f64;

				let pos = (b_x - (1.0 / tg_b) * b_y, 0.0);
				let ca = pos.0 / (1.0 - k);
				let cb = ca - pos.0;
				let co = tg_b * cb;

				let co = co.round() as i64;
				if co % button_a.1 != 0 || (prize.1 - co) % button_b.1 != 0 {
					continue;
				}
				let use_a = co / button_a.1;
				let use_b = (prize.1 - co) / button_b.1;
				sum += use_a * 3 + use_b;
			},
			_ => (),
		}
	}

	println!("{}", sum);
}

use std::env;
use std::fs::File;
use std::io::{BufRead, BufReader};
use regex::Regex;

const WIDE: i64 = 101;
const TALL: i64 = 103;
const SECONDS: i64 = 100;

fn main() {
	let args = env::args().collect::<Vec<String>>();
	let input = &args[1];

	let file = File::open(input).unwrap();
	let reader = BufReader::new(file);

	let mut q1 = 0;
	let mut q2 = 0;
	let mut q3 = 0;
	let mut q4 = 0;
	let re = Regex::new(r"p=(-?\d+),(-?\d+) v=(-?\d+),(-?\d+)").unwrap();
	for line in reader.lines() {
		let line = line.unwrap();
		let (_, [c1, c2, c3, c4]) = re.captures(&line).unwrap().extract();
		let p_x = c1.parse::<i64>().unwrap();
		let p_y = c2.parse::<i64>().unwrap();
		let v_x = c3.parse::<i64>().unwrap();
		let v_y = c4.parse::<i64>().unwrap();

		let np_x = (p_x + WIDE * SECONDS + v_x * SECONDS).abs() % WIDE;
		let np_y = (p_y + TALL * SECONDS + v_y * SECONDS).abs() % TALL;
		if np_x < WIDE / 2 && np_y < TALL / 2 {
			q1 += 1;
		}
		if np_x > WIDE / 2 && np_y < TALL / 2 {
			q2 += 1;
		}
		if np_x < WIDE / 2 && np_y > TALL / 2 {
			q3 += 1;
		}
		if np_x > WIDE / 2 && np_y > TALL / 2 {
			q4 += 1;
		}
	}

	println!("{}", q1 * q2 * q3 * q4);
}

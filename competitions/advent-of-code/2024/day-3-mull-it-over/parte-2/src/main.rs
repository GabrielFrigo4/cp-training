use std::env;
use std::fs::File;
use std::io::{BufRead, BufReader};
use regex::Regex;

fn main() {
	let args = env::args().collect::<Vec<String>>();
	let input = &args[1];

	let file = File::open(input).unwrap();
	let reader = BufReader::new(file);

	let mut do_mul = true;
	let mut ans = 0;
	for line in reader.lines() {
		let line = line.unwrap();
		let re = Regex::new(r"(?:(?:mul\((\d{1,3}),(\d{1,3})\))|(do\(\))|(don't\(\)))").unwrap();

		for cap in re.captures_iter(&line) {
			if cap.get(3) != None {
				do_mul = true;
				continue;
			}
			if cap.get(4) != None {
				do_mul = false;
				continue;
			}
			if do_mul && cap.get(1) != None && cap.get(2) != None {
				ans += &cap[1].parse::<i32>().unwrap() * &cap[2].parse::<i32>().unwrap();
			}
		}
	}

	println!("{}", ans);
}

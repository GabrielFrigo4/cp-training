use std::env;
use std::fs::File;
use std::io::{BufRead, BufReader};
use regex::Regex;

fn main() {
	let args = env::args().collect::<Vec<String>>();
	let input = &args[1];

	let file = File::open(input).unwrap();
	let reader = BufReader::new(file);

	let mut ans = 0;
	for line in reader.lines() {
		let line = line.unwrap();
		let re = Regex::new(r"mul\((\d{1,3}),(\d{1,3})\)").unwrap();

		for (_, [n1, n2]) in re.captures_iter(&line).map(|c| c.extract()) {
			ans += n1.parse::<i32>().unwrap() * n2.parse::<i32>().unwrap();
		}
	}

	println!("{}", ans);
}

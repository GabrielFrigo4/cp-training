use std::env;
use std::fs::File;
use std::io::{BufRead, BufReader};

enum State {
	Rules,
	Updates
}

fn main() {
	let args = env::args().collect::<Vec<String>>();
	let input = &args[1];

	let file = File::open(input).unwrap();
	let reader = BufReader::new(file);

	let mut sum = 0;
	let mut rules = Vec::<(i32, i32)>::new();
	let mut state = State::Rules;
	for line in reader.lines() {
		let line = line.unwrap();
		if line == "" {
			state = State::Updates;
			continue;
		}

		match state {
			State::Rules => {
				let parts = line.split("|").collect::<Vec<&str>>();
				let min = parts[0].parse::<i32>().unwrap();
				let max = parts[1].parse::<i32>().unwrap();
				rules.push((min, max));
			},
			State::Updates => {
				let numbs = line.split(",").map(|x| x.parse::<i32>().unwrap()).collect::<Vec<i32>>();
				let mut ok = true;
				for i in 0..numbs.len() {
					for e in (i+1)..numbs.len() {
						for rule in &rules {
							if numbs[i] == rule.1 && numbs[e] == rule.0 {
								ok = false;
							}
						}
					}
				}
				if ok {
					sum += numbs[numbs.len()/2];
				}
			}
		}
	}
	println!("{}", sum);
}

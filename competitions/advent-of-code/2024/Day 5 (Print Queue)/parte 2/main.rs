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
				let mut numbs = line.split(",").map(|x| x.parse::<i32>().unwrap()).collect::<Vec<i32>>();

				let mut tmp = true;
				let mut ok = true;
				let mut i = 0;
				let mut e = 0;
				while i < numbs.len() {
					e = i + 1;
					while e < numbs.len() && tmp {
						for rule in &rules {
							if numbs[i] == rule.1 && numbs[e] == rule.0 {
								numbs[i] = rule.0;
								numbs[e] = rule.1;
								tmp = false;
								ok = false;
								break;
							}
						}
						e += 1;
					}

					if tmp {
						i += 1;
					}
					tmp = true;
				}
				if !ok {
					sum += numbs[numbs.len()/2];
				}
			}
		}
	}
	println!("{}", sum);
}

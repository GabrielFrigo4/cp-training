use std::env;
use std::fs::File;
use std::io::{BufRead, BufReader};

enum State {
	None,
	Last,
	Increase,
	Decrease,
}

fn main() {
	let args = env::args().collect::<Vec<String>>();
	let input = &args[1];

	let file = File::open(input).unwrap();
	let reader = BufReader::new(file);

	let mut count = 0;
	for line in reader.lines() {
		let line = line.unwrap();
		let parts = line.split(" ").collect::<Vec<&str>>();

		let mut safe = true;
		let mut last = 0;
		let mut state = State::None;
		for part in parts {
			let numb = part.parse::<i32>().unwrap();
			match state {
				State::None => {
					state = State::Last;
					last = numb;
				},
				State::Last => {
					if (numb - last).abs() > 3 || numb == last {
						safe = false;
						break;
					}
					if numb > last {
						state = State::Increase;
					}
					if numb < last {
						state = State::Decrease;
					}
					last = numb;
				}
				State::Increase => {
					if numb - last > 3 || numb - last <= 0 {
						safe = false;
						break;
					}
					last = numb;
				},
				State::Decrease => {
					if last - numb > 3 || last - numb <= 0 {
						safe = false;
						break;
					}
					last = numb;
				}
			}
		}
		count += i32::from(safe);
	}

	println!("{}", count);
}

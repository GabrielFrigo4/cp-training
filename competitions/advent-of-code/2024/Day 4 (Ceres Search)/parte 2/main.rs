use std::env;
use std::fs::File;
use std::io::{BufRead, BufReader};

fn main() {
	let args = env::args().collect::<Vec<String>>();
	let input = &args[1];

	let file = File::open(input).unwrap();
	let reader = BufReader::new(file);

	let mut mat: Vec<Vec<char>> = Vec::<Vec<char>>::new();
	for line in reader.lines() {
		let line = line.unwrap();
		mat.push(line.chars().collect());
	}

	let mut count = 0;
	for y in 1..(mat.len()-1) {
		for x in 1..(mat[y].len()-1) {
			if mat[y][x] != 'A' {
				continue;
			}

			if !(mat[y-1][x-1] == 'M' && mat[y+1][x+1] == 'S') &&
				!(mat[y-1][x-1] == 'S' && mat[y+1][x+1] == 'M') {
				continue;
			}

			if !(mat[y-1][x+1] == 'M' && mat[y+1][x-1] == 'S') &&
				!(mat[y-1][x+1] == 'S' && mat[y+1][x-1] == 'M') {
				continue;
			}

			count += 1;
		}
	}

	println!("{}", count);
}

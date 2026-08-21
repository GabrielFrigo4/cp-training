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
	for y in 0..mat.len() {
		for x in 0..mat[y].len() {
			if x < mat[y].len() - 3 {
				if mat[y][x] == 'X' &&
					mat[y][x+1] == 'M' &&
					mat[y][x+2] == 'A' &&
					mat[y][x+3] == 'S' {
					count += 1;
				}
				if mat[y][x] == 'S' &&
					mat[y][x+1] == 'A' &&
					mat[y][x+2] == 'M' &&
					mat[y][x+3] == 'X' {
					count += 1;
				}
			}

			if y < mat.len() - 3 {
				if mat[y][x] == 'X' &&
					mat[y+1][x] == 'M' &&
					mat[y+2][x] == 'A' &&
					mat[y+3][x] == 'S' {
					count += 1;
				}
				if mat[y][x] == 'S' &&
					mat[y+1][x] == 'A' &&
					mat[y+2][x] == 'M' &&
					mat[y+3][x] == 'X' {
					count += 1;
				}
			}

			if y < mat.len() - 3 &&
				x < mat[y].len() - 3 {
				if mat[y][x] == 'X' &&
					mat[y+1][x+1] == 'M' &&
					mat[y+2][x+2] == 'A' &&
					mat[y+3][x+3] == 'S' {
					count += 1;
				}
				if mat[y][x] == 'S' &&
					mat[y+1][x+1] == 'A' &&
					mat[y+2][x+2] == 'M' &&
					mat[y+3][x+3] == 'X' {
					count += 1;
				}
			}

			if y < mat.len() - 3 && x > 2 {
				if mat[y][x] == 'X' &&
					mat[y+1][x-1] == 'M' &&
					mat[y+2][x-2] == 'A' &&
					mat[y+3][x-3] == 'S' {
					count += 1;
				}
					if mat[y][x] == 'S' &&
					mat[y+1][x-1] == 'A' &&
					mat[y+2][x-2] == 'M' &&
					mat[y+3][x-3] == 'X' {
					count += 1;
				}
			}
		}
	}

	println!("{}", count);
}
